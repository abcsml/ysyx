import chisel3._
import chisel3.util._

class PDD extends Module {
  val io = IO(new Bundle {
    var a = Input(Vec(4,UInt(1.W)))
    var sel = Input(UInt(2.W))
    var out = Output(UInt(1.W))
  })
  io.out := 0.U
  switch(io.sel) {
    is(0.U) {io.out := io.a(0)}
    is(1.U) {io.out := io.a(1)}
    is(2.U) {io.out := io.a(2)}
    is(3.U) {io.out := io.a(3)}
  }
  // io.a(4) := io.a(0) | io.a(1)
}
