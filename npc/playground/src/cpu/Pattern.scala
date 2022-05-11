package core

import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum

object BaseType extends ChiselEnum {
	val R, I = Value
	val	S, U = Value
	val	B, J = Value
}

object Opcode extends ChiselEnum {
	val OP_IMM = 	Value("b0010011".U)
	val AUIPC =		Value("b0010111".U)
	val LUI = 		Value("b0110111".U)
}

object Command extends ChiselEnum {
	val auipc,
			sd,
			lui,
			jal,
			jalr,
			addi,
			slti,
			sltiu,
			xori,
			ori,
			andi,
			addiw,
			beq,
			bne,
			blt,
			bge,
			bltu,
			bgeu,
			lb,
			lh,
			lw,
			lbu,
			lhu,
			lwu,
			ld,
			sb,
			sh,
			sw,
			slli,
			srli,
			srai,
			slliw,
			srliw,
			sraiw,
			add,
			sub,
			slt,
			sltu,
			sll,
			srl,
			sra,
			xor,
			or,
			and,
			addw,
			subw,
			sllw,
			srlw,
			sraw,
			mul,
			mulw,
			divw,
			remw,
			ret,
			ebreak,
			inv = Value
}
