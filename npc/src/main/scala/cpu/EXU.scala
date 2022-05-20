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
  io.regsOut := io.regsIn
  io.dnpcOut := io.dnpcIn
  io.regsOut(io.dest) := MuxLookup(io.command.asUInt, io.regsIn(io.dest)
  , Array(
    addi.asUInt -> io.src1 + io.src2,
    auipc.asUInt -> io.pc + io.src1,
    jal.asUInt -> io.pc + 4,
    jalr.asUInt -> io.pc + 4,
    // sd.asUInt -> 

    // ebreak.asUInt -> 
    // inv.asUInt
  ))
  io.dnpcOut := MuxLookup(io.command.asUInt, io.dnpcIn, Array(
    jal.asUInt -> io.pc + io.src1,
    jalr.asUInt -> (io.src1 + io.src2) & (~1.U),
  ))

  // debug
  printf(p"${io.command.toString()}")
  printf("??? %d %d %d\n",io.regsOut(io.dest),io.regsIn(io.src1),io.src2)
}
