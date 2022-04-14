#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vadder4way.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vadder4way* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vadder4way;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("output/adder4way.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  for (int i=-8;i<=7;i++) {
    for (int j=-8;j<=7;j++) {
        top->x = i;
        top->y = j;
        step_and_dump_wave();
    }
  }

  sim_exit();
}