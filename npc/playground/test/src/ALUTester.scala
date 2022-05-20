package play

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

import chiseltest.simulator.WriteVcdAnnotation

class ADDTester extends AnyFlatSpec with ChiselScalatestTester {
  "ADDTester" should "pass" in {
    test(new ADD(4))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      println(s"test:${1.U}")
      for (a <- 0 to 15) {
        for (b <- 0 to 15) {
          dut.io.a.poke(a.S)
          dut.io.b.poke(b.S)
          dut.io.c.poke(1.U(1.W))
          dut.clock.step()
        }
      }
    }
  }
}

class ALUTester extends AnyFlatSpec with ChiselScalatestTester {
  "ALUTester" should "pass" in {
    test(new ALU(4))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      for (a <- 0 to 15) {
        for (b <- 0 to 15) {
          for (sel <- 0 to 7) {
            dut.io.a.poke(a.S)
            dut.io.b.poke(b.S)
            dut.io.sel.poke(sel.U)
            dut.clock.step()
            // printf("dut: %d %d %d\n",dut.io.a, dut.io.b, dut.io.sel)
          }
        }
      }
    }
  }
}
