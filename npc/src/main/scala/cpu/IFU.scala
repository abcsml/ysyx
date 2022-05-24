// Instruction Fetch Unit
package core

import chisel3._
import chisel3.util._

class IFU extends Module {
  val io = IO(new Bundle {
    val snpcIn = Input(UInt(64.W))
    val len = Input(UInt(3.W))
    val inst = Output(UInt(32.W))
    val snpcOut = Output(UInt(64.W))
  })
  val mem = withClockAndReset(clock, reset){ Module(new MEM()) }
  // val reg = RegInit(UInt(64.W), "x80000000".U(64.W))

  mem.io.clock := clock
  mem.io.reset := reset
  mem.io.en := true.B
  mem.io.rw := true.B
  mem.io.addr := io.snpcIn
  mem.io.len := io.len
  io.inst := mem.io.dataOut(32, 0)
  // reg := mem.io.data
  io.snpcOut := io.snpcIn + io.len

  // printf("snpc: %x = %x + %x\n", io.snpcOut, io.snpcIn, io.len)

  // test
  // io.inst := ("b0000000"+"00001"+"00001"+   // R(1) = R(1) + 1
  //             "000"+"00001"+"00100"+"11").U
  
}

