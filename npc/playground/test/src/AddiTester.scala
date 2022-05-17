package core

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

import chiseltest.simulator.WriteVcdAnnotation

class AddiTester extends AnyFlatSpec with ChiselScalatestTester {
  "addi" should "pass" in {
    test(new CPU())
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      for (i <- 0 to 9) {
        dut.clock.step()
        // printf(p"${dut.io.command}")
      }
    }
  }
}