package play

import chisel3._
import chisel3.util._

class FSM extends Module {
  val io = IO(new Bundle {
    var in = Input(UInt(1.W))
    var out = Output(UInt(1.W))
  })
  var reg = RegInit(0.U(4.W))
  
  reg := MuxLookup(reg, 0.U, Array(
    0.U -> Mux(io.in === 1.U, 5.U, 1.U),
    1.U -> Mux(io.in === 1.U, 5.U, 2.U),
    2.U -> Mux(io.in === 1.U, 5.U, 3.U),
    3.U -> Mux(io.in === 1.U, 5.U, 4.U),
    4.U -> Mux(io.in === 1.U, 5.U, 4.U),
    5.U -> Mux(io.in === 1.U, 6.U, 1.U),
    6.U -> Mux(io.in === 1.U, 7.U, 1.U),
    7.U -> Mux(io.in === 1.U, 8.U, 1.U),
    8.U -> Mux(io.in === 1.U, 8.U, 1.U),
  ))
  io.out := MuxLookup(reg, 0.U, Array(
    4.U -> 1.U,
    8.U -> 1.U
  ))
}