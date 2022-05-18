package play

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

import chiseltest.simulator.WriteVcdAnnotation

class FSMTester extends AnyFlatSpec with ChiselScalatestTester {
  "FSMTester" should "pass" in {
    test(new FSM())
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      val r = scala.util.Random
      for (a <- 0 to 40) {
        dut.io.in.poke(r.nextInt(2).U)
        dut.clock.step()
      }
    }
  }
}
