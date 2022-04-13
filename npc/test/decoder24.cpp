#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vdecoder24.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vdecoder24* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vdecoder24;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("output/decoder24.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  top->en = 0b0;  top->x = 0b00;  step_and_dump_wave();
                  top->x = 0b01;  step_and_dump_wave();
                  top->x = 0b10;  step_and_dump_wave();
                  top->x = 0b11;  step_and_dump_wave();
  top->en = 0b1;  top->x = 0b00;  step_and_dump_wave();
                  top->x = 0b01;  step_and_dump_wave();
                  top->x = 0b10;  step_and_dump_wave();
                  top->x = 0b11;  step_and_dump_wave();

  sim_exit();
}