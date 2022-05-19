#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VMEM.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VMEM* top;

void step_and_dump_wave() {
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init() {
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VMEM;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("out/mem.vcd");
}

void sim_exit() {
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();
  top->addr = 0x800000;
  top->len = 4;
  top->clk = 0;
  step_and_dump_wave();
  top->addr = 0x800001;
  top->len = 4;
  top->clk = 1;
  step_and_dump_wave();
  top->addr = 0x800002;
  top->len = 4;
  top->clk = 0;
  step_and_dump_wave();
  top->addr = 0x800003;
  top->len = 4;
  top->clk = 1;
  step_and_dump_wave();
  top->addr = 0x800004;
  top->len = 4;
  top->clk = 0;
  step_and_dump_wave();

  sim_exit();
}