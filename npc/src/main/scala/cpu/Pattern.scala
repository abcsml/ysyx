package core

import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum

object BaseType extends ChiselEnum {
	val R, I = Value
	val	S, U = Value
	val	B, J = Value
	val N  Value		// NULL
}

object Opcode extends ChiselEnum {
	val LOAD = 	  	Value("00000011".U)
	val OP_IMM =   	Value("b0010011".U)
	val AUIPC =	  	Value("b0010111".U)
	val OP_IMM_32 = Value("b0011011".U)		// RV64I
	val STORE =			Value("b0100011".U)
	val OP = 				Value("b0110011".U)
	val LUI = 			Value("b0110111".U)
	val OP_32 = 		Value("b0111011".U)		// RV64I
	val BRANCH =		Value("b1100011".U)
	val JALR =			Value("b1100111".U)
	val JAL = 			Value("b1101111".U)
	val SYSTEM =		Value("b1110011".U)
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
