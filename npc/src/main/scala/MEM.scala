package core

import chisel3._
import chisel3.util._

class MEM extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    var clock  = Input(Clock())
    var reset  = Input(Bool())
    val en = Input(Bool())
    val rw = Input(Bool())      // true: r ,false: w
    val addr = Input(UInt(64.W))
    val len  = Input(UInt(4.W))
    val dataIn = Input(UInt(64.W))
    val dataOut = Output(UInt(64.W))
  })
  addPath("./src/vsrc/MEM.v")
}
