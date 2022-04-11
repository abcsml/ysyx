#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "verilated.h"
#include "verilated_vcd_c.h"

// #include <nvboard.h>
#include <Vexample.h>

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

Vexample *top = new Vexample;
VerilatedVcdC *tfp = new VerilatedVcdC;

// void nvboard_bind_all_pins(Vtop* top);

// void single_cycle() {
//   top.clk = 0; top.eval();
//   top.clk = 1; top.eval();
// }

// void reset(int n) {
//   top.rst = 1;
//   while (n -- > 0) single_cycle();
//   top.rst = 0;
// }

int main(){
  Verilated::traceEverOn(true);
  top->trace(tfp,10);
  tfp->open("output/example.vcd");

//   nvboard_bind_all_pins(&top);
//   nvboard_init();

//   reset(10);
  while (sim_time < MAX_SIM_TIME) {
    // single_cycle();
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();

    tfp->dump(sim_time);
    sim_time++;
    // nvboard_update();
  }
//   nvboard_quit();
  tfp->close();
}
