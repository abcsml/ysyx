// Instruction Decode Unit
package core

import chisel3._
import chisel3.util._

import Command._

class IDU extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val command = Output(Command())
    // val type = Output(Type())
    val dest = Output(UInt(64.W)) // default means reg
    val src1 = Output(UInt(64.W))
    val src2 = Output(UInt(64.W))
  })
  def sext(x:UInt, len:Int) = {
    Fill(64-len, x(len-1)) ## x(len-1, 0)
  }

  val baseType = Wire(BaseType())
  // val baseType = Wire(UInt(3.W))
  val op  = Wire(UInt((6-0+1).W))
  val rd  = Wire(UInt((11-7+1).W))
  val rs1 = Wire(UInt((19-15+1).W))
  val rs2 = Wire(UInt((24-20+1).W))
  val funct3 = Wire(UInt((14-12+1).W))
  val funct7 = Wire(UInt((31-25+1).W))

  op := io.inst(6,0)  
  baseType := MuxLookup(op, BaseType.I, Array(
    Opcode.OP_IMM.asUInt -> BaseType.I,
    Opcode.LUI.asUInt ->    BaseType.U,
  ))

  rd  := io.inst(11,7)
  rs1 := io.inst(19,15)
  rs2 := io.inst(24,20)
  io.dest := MuxLookup(baseType.asUInt, rd, Array(
    BaseType.S.asUInt -> sext(io.inst(31,25) ## io.inst(11,7), 12),
    BaseType.B.asUInt -> sext(io.inst(31,31) ## io.inst(7,7) ##
                        io.inst(30,25) ## io.inst(11,8) ##
                        0.U(1.W), 13)
  ))
  io.src1 := MuxLookup(baseType.asUInt, rs1, Array(
    BaseType.U.asUInt -> (sext(io.inst(31,12), 20) << 12),
  ))
  io.src2 := MuxLookup(baseType.asUInt, rs2, Array(
    BaseType.I.asUInt -> sext(io.inst(31,20), 12),
  ))

  funct3 := io.inst(14,12)
  funct7 := io.inst(31,25)
  io.command := MuxLookup(op, inv, Array(
    Opcode.OP_IMM.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> addi,
      "b010".U -> slti,
      "b011".U -> sltiu,
    )),
    Opcode.LUI.asUInt -> lui,
    Opcode.AUIPC.asUInt -> auipc,
  ))

  // // test
  // io.command := addi
  // io.dest := io.inst(11,7)
  // io.src1 := io.inst(19,15)
  // io.src2 := io.inst(31,20)
}
