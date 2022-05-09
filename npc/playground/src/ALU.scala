package play

import chisel3._
import chisel3.util._

class ADD(size: Int) extends Module {
  val io = IO(new Bundle {
    var a = Input(SInt(size.W))
    var b = Input(SInt(size.W))
    var c = Input(UInt(1.W))   // 1:+,0:-
    var out = Output(SInt(size.W))
    var cf = Output(Bool())   // carry
    var of = Output(Bool())   // overflow
  })
  var noCin = Wire(SInt(size.W))
  var ans = Wire(UInt(size.W + 1))
  noCin := Fill(size, io.c).asSInt ^ io.b
  ans := io.a.asUInt +& (noCin.asUInt + io.c)

  io.out := ans.asSInt
  io.cf := ans(size).asBool
  io.of := (io.a(size-1) === noCin(size-1)) && (ans(size-1) =/= io.a(size-1))
}

class ALU(size: Int) extends Module {
  val io = IO(new Bundle {
    var a = Input(SInt(size.W))
    var b = Input(SInt(size.W))
    var sel = Input(UInt(3.W))
    var out = Output(SInt(size.W))
    var cf = Output(Bool())
    var of = Output(Bool())
    var ze = Output(Bool())
  })
  var add = Module(new ADD(size))
  var sub = Module(new ADD(size))
  
  add.io.a := io.a
  add.io.b := io.b
  add.io.c := 0.U
  sub.io.a := io.a
  sub.io.b := io.b
  sub.io.c := 1.U

  io.out := MuxLookup(io.sel, 0.S, Array(
    0.U -> add.io.out,
    1.U -> sub.io.out,
    2.U -> ~ io.a,
    3.U -> (io.a & io.b),
    4.U -> (io.a | io.b),
    5.U -> (io.a ^ io.b),
    6.U -> Mux(io.a < io.b, 1.S, 0.S),
    7.U -> Mux(io.a === io.b, 1.S, 0.S),
  ))

  io.cf := MuxLookup(io.sel, false.B, Array(
    0.U -> add.io.cf,
    1.U -> sub.io.cf,
  ))

  io.of := MuxLookup(io.sel, false.B, Array(
    0.U -> add.io.of,
    1.U -> sub.io.of,
  ))
  
  io.ze := io.out === 0.S
}

class ALUC(size: Int) extends Module {
  val io = IO(new Bundle {
    var a = Input(SInt(size.W))
    var b = Input(SInt(size.W))
    var sel = Input(UInt(3.W))
    var out = Output(SInt(size.W))
    var cf = Output(Bool())
    var of = Output(Bool())
    var ze = Output(Bool())
  })
  var add = Module(new ADD(size))

  add.io.a := io.a
  add.io.b := io.b
  add.io.c := false.B
  var out_d = WireDefault(0.S(size.W))
  var cf_d = WireDefault(false.B)
  var of_d = WireDefault(false.B)
  var ze_d = WireDefault(false.B)

  switch(io.sel) {
    is(0.U) {
      out_d := add.io.out
      cf_d := add.io.cf
      of_d := add.io.of
    }
    is(1.U) {
      add.io.c := true.B
      out_d := add.io.out
      cf_d := add.io.cf
      of_d := add.io.of
    }
    is(2.U) {out_d := ~ io.a}
    is(3.U) {out_d := io.a & io.b}
    is(4.U) {out_d := io.a | io.b}
    is(5.U) {out_d := io.a ^ io.b}
    is(6.U) {out_d := Mux(io.a < io.b, 1.S, 0.S)}
    is(7.U) {out_d := Mux(io.a === io.b, 1.S, 0.S)}
  }
  io.out := out_d
  io.cf := cf_d
  io.of := of_d
  io.ze := io.out === 0.S
}
