// Instruction Fetch Unit
package core

import chisel3._
import chisel3.util._

class IFU extends Module {
  val io = IO(new Bundle {
    val snpcIn = Input(UInt(64.W))
    // val en = Input(Bool())
    // val rw = Input(UInt(1.W)) // 1:r,0,w
    val len = Input(UInt(3.W))
    val inst = Output(UInt(32.W))
    val snpcOut = Output(UInt(64.W))
  })
  io.snpcOut := io.snpcIn + io.len
  io.inst := 0.U
  // test
  io.inst := ("b0000000"+"00001"+"00001"+   // R(1) = R(1) + 1
              "000"+"00001"+"00100"+"11").U
  
}

