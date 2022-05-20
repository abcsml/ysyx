package core

import chisel3._
import chisel3.util._

class CPU extends Module {
  val io = IO(new Bundle {
    val en = Input(Bool())
    // use for debug
    val regs = Output(Vec(32, UInt(64.W)))
    val pc = Output(UInt(64.W))
  })
  val registerFile = Reg(Vec(32, UInt(64.W)))
  val pc = RegInit("x80000000".U(64.W))

  val dnpc = Wire(UInt(64.W))

  val ifu = Module(new IFU())
  val idu = Module(new IDU())
  val exu = Module(new EXU())

  ifu.io.snpcIn := pc
  ifu.io.len := 4.U
  dnpc := ifu.io.snpcOut
  idu.io.inst := ifu.io.inst
  exu.io.command := idu.io.command
  exu.io.dest := idu.io.dest
  exu.io.src1 := idu.io.src1
  exu.io.src2 := idu.io.src2
  exu.io.regsIn := registerFile
  exu.io.pc := pc
  exu.io.dnpcIn := dnpc
  registerFile := exu.io.regsOut
  registerFile(0) := 0.U
  pc := exu.io.dnpcOut

  // debug
  io.regs := registerFile
  io.pc := pc
}
