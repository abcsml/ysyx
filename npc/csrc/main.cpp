#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vlight.h"

#include "verilated.h"
#include "verilated_vcd_c.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

void single_cycle() {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}

void reset(int n) {
  top->rst = 1;
  while (n -- > 0) single_cycle();
  top->rst = 0;
}

int main(){
  Verilated::traceEverOn(true);
  Vlight *top = new Vlight;
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp,10);
  tfp->open("light.vcd");

  reset(10);
  while (sim_time < MAX_SIM_TIME) {
    single_cycle();

    tfp->dump(sim_time);
    sim_time++;
  }
  tfp->close();
}
