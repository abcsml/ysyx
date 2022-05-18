// Instruction Fetch Unit
package core

import chisel3._
import chisel3.util._

class MEM extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val addr = Input(UInt(64.W))
    val len  = Input(UInt(3.W))
    val data = Output(UInt(32.W))
  })
  addPath("../csrc/mem.v")
}

class IFU extends Module {
  val io = IO(new Bundle {
    val snpcIn = Input(UInt(64.W))
    // val en = Input(Bool())
    // val rw = Input(UInt(1.W)) // 1:r,0,w
    val len = Input(UInt(3.W))
    val inst = Output(UInt(32.W))
    val snpcOut = Output(UInt(64.W))
  })
  val mem = Module(new MEM())

  mem.io.addr := io.snpcIn
  mem.io.len := io.len
  io.inst := mem.io.data
  io.snpcOut := io.snpcIn + io.len

  // test
  // io.inst := ("b0000000"+"00001"+"00001"+   // R(1) = R(1) + 1
  //             "000"+"00001"+"00100"+"11").U
  
}

