// EXecution Unit
package core

import chisel3._
import chisel3.util._

import Command._

class EXU extends Module {
  val io = IO(new Bundle {
    val command = Input(Command())
    // val type = Input(Type())
    val dest = Input(UInt(64.W))
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val regsIn = Input(Vec(32, UInt(64.W)))
    val pc = Input(UInt(64.W))
    val dnpcIn = Input(UInt(64.W))
    val regsOut = Output(Vec(32, UInt(64.W)))
    val dnpcOut = Output(UInt(64.W))
  })
  def sext(x:UInt, len:Int) = {
    Fill(64-len, x(len-1)) ## x(len-1, 0)
  }

  // load, store
  val enMem = Wire(Bool())
  val rwMem = Wire(Bool())
  val mem = withClockAndReset(clock, reset){ Module(new MEM()) }
  
  enMem := io.command.isOneOf(lb,lh,lw,ld,lbu,lhu,lwu,sb,sh,sw,sd)
  rwMem := io.command.isOneOf(lb,lh,lw,ld,lbu,lhu,lwu)
  mem.io.en := enMem
  mem.io.rw := rwMem
  mem.io.addr := Mux(rwMem, io.src1 + io.src2, io.src1 + io.dest)
  mem.io.len := MuxLookup(io.command.asUInt, 0.U, Array(
    lb.asUInt  -> 1.U,
    lh.asUInt  -> 2.U,
    lw.asUInt  -> 4.U,
    ld.asUInt  -> 8.U,
    sb.asUInt  -> 1.U,
    sh.asUInt  -> 2.U,
    sw.asUInt  -> 4.U,
    sd.asUInt  -> 8.U,
    lbu.asUInt -> 1.U,
    lhu.asUInt -> 2.U,
    lwu.asUInt -> 4.U,
  ))
  mem.io.dataIn := Mux(rwMem, 0.U, io.src2)

  io.regsOut := io.regsIn
  io.dnpcOut := io.dnpcIn
  io.regsOut(io.dest) := MuxLookup(io.command.asUInt, io.regsIn(io.dest)
  , Array(
    auipc.asUInt  -> (io.pc + io.src1),
    lui.asUInt    -> io.src1,
    jal.asUInt    -> (io.pc + 4.U),
    jalr.asUInt   -> (io.pc + 4.U),

    addi.asUInt   -> (io.src1 + io.src2),
    slti.asUInt   -> Mux(io.src1.asSInt < io.src2.asSInt, 1.U, 0.U),
    sltiu.asUInt  -> Mux(io.src1 < io.src2, 1.U, 0.U),
    xori.asUInt   -> (io.src1 ^ io.src2),
    ori.asUInt    -> (io.src1 | io.src2),
    andi.asUInt   -> (io.src1 & io.src2),
    slli.asUInt   -> (io.src1 << io.src2(5,0)),     // ???
    srli.asUInt   -> (io.src1 >> io.src2(5,0)),
    srai.asUInt   -> (io.src1.asSInt >> io.src2(5,0)).asUInt,

    addiw.asUInt  -> sext((io.src1 + io.src2), 32),
    slliw.asUInt  -> sext((io.src1(31,0) << io.src2(4,0)), 32),
    srliw.asUInt  -> sext((io.src1(31,0) << io.src2(4,0)), 32),
    sraiw.asUInt  -> sext((io.src1(31,0).asSInt << io.src2(4,0)).asUInt, 32),

    add.asUInt    -> (io.src1 + io.src2),
    sub.asUInt    -> (io.src1 - io.src2),
    slt.asUInt    -> Mux(io.src1.asSInt < io.src2.asSInt, 1.U, 0.U),
    sltu.asUInt   -> Mux(io.src1 < io.src2, 1.U, 0.U),
    sll.asUInt    -> (io.src1 << io.src2(5,0)),
    srl.asUInt    -> (io.src1 >> io.src2(5,0)),
    sra.asUInt    -> (io.src1.asSInt >> io.src2(5,0)).asUInt,
    xor.asUInt    -> (io.src1 ^ io.src2),
    or.asUInt     -> (io.src1 | io.src2),
    and.asUInt    -> (io.src1 & io.src2),
    mul.asUInt    -> (io.src1 * io.src2),

    addw.asUInt   -> sext((io.src1 + io.src2), 32),
    subw.asUInt   -> sext((io.src1 - io.src2), 32),
    sllw.asUInt   -> sext((io.src1(31,0) << io.src2(4,0)), 32),
    srlw.asUInt   -> sext((io.src1(31,0) >> io.src2(4,0)), 32),
    sraw.asUInt   -> sext((io.src1(31,0).asSInt >> io.src2(4,0)).asUInt, 32),
    mulw.asUInt   -> sext((io.src1(31,0) * io.src2(31,0)), 32),
    // divw.asUInt   -> sext((io.src1(31,0).asSInt / io.src2(31,0).asSInt).asUInt, 32),
    // remw.asUInt   -> sext((io.src1(31,0).asSInt % io.src2(31,0).asSInt).asUInt, 32),

    lb.asUInt     -> sext(mem.io.dataOut, 8),
    lh.asUInt     -> sext(mem.io.dataOut, 16),
    lw.asUInt     -> sext(mem.io.dataOut, 32),
    ld.asUInt     -> mem.io.dataOut,
    lbu.asUInt    -> mem.io.dataOut,
    lhu.asUInt    -> mem.io.dataOut,
    lwu.asUInt    -> mem.io.dataOut,
  ))

  io.dnpcOut := MuxLookup(io.command.asUInt, io.dnpcIn, Array(
    jal.asUInt    -> (io.pc + io.src1),
    jalr.asUInt   -> ((io.src1 + io.src2) & (~1.U(64.W))),

    beq.asUInt    -> Mux(io.src1 === io.src2, io.pc + io.dest, io.dnpcIn),
    bne.asUInt    -> Mux(io.src1 =/= io.src2, io.pc + io.dest, io.dnpcIn),
    blt.asUInt    -> Mux(io.src1.asSInt < io.src2.asSInt, io.pc + io.dest, io.dnpcIn),
    bge.asUInt    -> Mux(io.src1.asSInt >= io.src2.asSInt, io.pc + io.dest, io.dnpcIn),
    bltu.asUInt   -> Mux(io.src1 < io.src2, io.pc + io.dest, io.dnpcIn),
    bgeu.asUInt   -> Mux(io.src1 >= io.src2, io.pc + io.dest, io.dnpcIn),

    ebreak.asUInt -> ("x87ffffff".U),               // over
    inv.asUInt    -> ("x87fffff0".U),               // not imp
  ))

  

  // debug
  // Command.all.foreach
  // println(Command(io.command.asUInt))
  // println(Command.all(2))
  printf("command %x %x %x\n",io.regsOut(io.dest),io.src1,io.src2)
}
