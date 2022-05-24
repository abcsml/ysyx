// Instruction Decode Unit
package core

import chisel3._
import chisel3.util._

import Command._

class IDU extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val regs = Input(Vec(32, UInt(64.W)))
    val command = Output(Command())
    // val type = Output(Type())
    val dest = Output(UInt(64.W)) // default means reg
    val src1 = Output(UInt(64.W))
    val src2 = Output(UInt(64.W))
  })
  def sext(x:UInt, len:Int) = {
    Fill(64-len, x(len-1)) ## x(len-1, 0)
  }
  
  def immI(i:UInt) = {
    sext(i(31,20), 12)
  }
  def immU(i:UInt) = {
    (sext(i(31,12), 20) << 12)
  }
  def immS(i:UInt) = {
    sext(i(31,25) ## i(11,7), 12)
  }
  def immJ(i:UInt) = {
    sext(i(31,31) ## i(19,12) ##
      i(20,20) ## i(30,21) ##
      0.U(1.W), 13)
  }
  def immB(i:UInt) = {
    sext(i(31,31) ## i(7,7) ##
      i(30,25) ## i(11,8) ##
      0.U(1.W), 13)
  }

  val baseType = Wire(BaseType())
  // val baseType = Wire(UInt(3.W))
  val op  = Wire(UInt((6-0+1).W))
  val rd  = Wire(UInt((11-7+1).W))
  val rs1 = Wire(UInt((19-15+1).W))
  val rs2 = Wire(UInt((24-20+1).W))
  val funct3 = Wire(UInt((14-12+1).W))
  val funct7 = Wire(UInt((31-25+1).W))

  val regs = io.regs
  op := io.inst(6,0)  
  baseType := MuxLookup(op, BaseType.I, Array(
    // Opcode.OP_IMM.asUInt -> BaseType.I,
    // Opcode.LUI.asUInt ->    BaseType.U,
    Opcode.LOAD.asUInt ->       BaseType.I,
    Opcode.OP_IMM.asUInt ->     BaseType.I,
    Opcode.AUIPC.asUInt ->	    BaseType.U,
    Opcode.OP_IMM_32.asUInt ->  BaseType.I,
    Opcode.STORE.asUInt ->	    BaseType.S,
    Opcode.OP.asUInt ->	        BaseType.R,
    Opcode.LUI.asUInt -> 	      BaseType.U,
    Opcode.OP_32.asUInt ->      BaseType.R,
    Opcode.BRANCH.asUInt ->     BaseType.B,
    Opcode.JALR.asUInt ->       BaseType.I,
    Opcode.JAL.asUInt ->        BaseType.J,
    Opcode.SYSTEM.asUInt ->     BaseType.N,
  ))

  rd  := io.inst(11,7)    // return index, not reg val
  rs1 := io.inst(19,15)
  rs2 := io.inst(24,20)
  io.dest := MuxLookup(baseType.asUInt, rd, Array(
    BaseType.S.asUInt -> immS(io.inst),
    BaseType.B.asUInt -> immB(io.inst),
  ))
  io.src1 := MuxLookup(baseType.asUInt, rs1, Array(
    BaseType.I.asUInt -> regs(rs1),
    BaseType.U.asUInt -> immU(io.inst),
    BaseType.S.asUInt -> regs(rs1),
    BaseType.J.asUInt -> immJ(io.inst),
    BaseType.B.asUInt -> regs(rs1),
    BaseType.R.asUInt -> regs(rs1),
  ))
  io.src2 := MuxLookup(baseType.asUInt, rs2, Array(
    BaseType.I.asUInt -> immI(io.inst),
    BaseType.S.asUInt -> regs(rs2),
    BaseType.B.asUInt -> regs(rs2),
    BaseType.R.asUInt -> regs(rs2),
  ))

  funct3 := io.inst(14,12)
  funct7 := io.inst(31,25)
  io.command := MuxLookup(op, inv, Array(
    Opcode.OP_IMM.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> addi,
      "b010".U -> slti,
      "b011".U -> sltiu,
      "b100".U -> xori,
      "b110".U -> ori,
      "b111".U -> andi,
      "b001".U -> Mux(io.inst(31,26) === "b000000".U, slli, inv),
      "b101".U -> MuxLookup(io.inst(31,26), inv, Array(
        "b000000".U -> srli,
        "b010000".U -> srai,
      )),
    )),
    Opcode.OP.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> MuxLookup(funct7, inv, Array(
        "b0000000".U -> add,
        "b0100000".U -> sub,
        "b0000001".U -> mul,
      )),
      "b001".U -> Mux(funct7 === "b0000000".U, sll, inv),
      "b010".U -> Mux(funct7 === "b0000000".U, slt, inv),
      "b011".U -> Mux(funct7 === "b0000000".U, sltu, inv),
      "b101".U -> MuxLookup(funct7, inv, Array(
        "b0000000".U -> srl,
        "b0100000".U -> sra,
      )),
      "b100".U -> Mux(funct7 === "b0000000".U, xor, inv),
      "b110".U -> Mux(funct7 === "b0000000".U, or, inv),
      "b111".U -> Mux(funct7 === "b0000000".U, and, inv),
    )),
    Opcode.BRANCH.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> beq,
      "b001".U -> bne,
      "b100".U -> blt,
      "b101".U -> bge,
      "b110".U -> bltu,
      "b111".U -> bgeu,
    )),
    Opcode.LOAD.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> lb,
      "b001".U -> lh,
      "b010".U -> lw,
      "b011".U -> ld,
      "b100".U -> lbu,
      "b101".U -> lhu,
      "b110".U -> lwu,
    )),
    Opcode.STORE.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> sb,
      "b001".U -> sh,
      "b010".U -> sw,
      "b011".U -> sd,
    )),
    Opcode.OP_IMM_32.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> addiw,
      "b001".U -> Mux(funct7 === "b0000000".U, slliw, inv),
      "b101".U -> MuxLookup(funct7, inv, Array(
        "b0000000".U -> srliw,
        "b0100000".U -> sraiw,
      )),
    )),
    Opcode.OP_32.asUInt -> MuxLookup(funct3, inv, Array(
      "b000".U -> MuxLookup(funct7, inv, Array(
        "b0000000".U -> addw,
        "b0100000".U -> subw,
        "b0000001".U -> mulw,
      )),
      "b001".U -> Mux(funct7 === "b0000000".U, sllw, inv),
      "b100".U -> Mux(funct7 === "b0000001".U, divw, inv),
      "b101".U -> MuxLookup(funct7, inv, Array(
        "b0000000".U -> srlw,
        "b0100000".U -> sraw,
      )),
      "b110".U -> Mux(funct7 === "b0000001".U, remw, inv),
    )),
    Opcode.LUI.asUInt -> lui,
    Opcode.AUIPC.asUInt -> auipc,
    Opcode.JAL.asUInt -> jal,
    Opcode.JALR.asUInt -> jalr,
    Opcode.SYSTEM.asUInt -> ebreak,
  ))

  // // test
  // io.command := addi
  // io.dest := io.inst(11,7)
  // io.src1 := io.inst(19,15)
  // io.src2 := io.inst(31,20)
}
