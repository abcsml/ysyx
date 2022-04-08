#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "verilated.h"
#include "verilated_vcd_c.h"

#include <nvboard.h>
#include <Vtop.h>

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

static TOP_NAME top;
// Vtop *top = new Vtop;
// VerilatedVcdC *tfp = new VerilatedVcdC;

void nvboard_bind_all_pins(Vtop* top);

void single_cycle() {
  top.clk = 0; top.eval();
  top.clk = 1; top.eval();
}

void reset(int n) {
  top.rst = 1;
  while (n -- > 0) single_cycle();
  top.rst = 0;
}

int main(){
  // Verilated::traceEverOn(true);
  // top->trace(tfp,10);
  // tfp->open("light.vcd");

  nvboard_bind_all_pins(&top);
  nvboard_init();

  reset(10);
  while (true) {
    single_cycle();

    // tfp->dump(sim_time);
    // sim_time++;
    nvboard_update();
  }
  nvboard_quit();
  // tfp->close();
}
