#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vexample.h"

#include "verilated.h"
#include "verilated_vcd_c.h"

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

int main(){
  Verilated::traceEverOn(true);
  Vexample *top = new Vexample;
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp,10);
  tfp->open("test.vcd");

  while (sim_time < MAX_SIM_TIME) {
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == a ^ b);

    tfp->dump(sim_time);
    sim_time++;
  }
  tfp->close();
}
