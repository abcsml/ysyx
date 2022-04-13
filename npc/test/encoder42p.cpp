#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vencoder42p.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vencoder42p* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vencoder42p;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("output/encoder42p.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  top->en=0b0; top->x =0b0000; step_and_dump_wave();
               top->x =0b0001; step_and_dump_wave();
               top->x =0b0010; step_and_dump_wave();
               top->x =0b0011; step_and_dump_wave();
               top->x =0b0100; step_and_dump_wave();
               top->x =0b0101; step_and_dump_wave();
               top->x =0b0110; step_and_dump_wave();
               top->x =0b0111; step_and_dump_wave();
               top->x =0b1000; step_and_dump_wave();
               top->x =0b1001; step_and_dump_wave();
               top->x =0b1010; step_and_dump_wave();
               top->x =0b1100; step_and_dump_wave();
               top->x =0b1111; step_and_dump_wave();
  top->en=0b1; top->x =0b0000; step_and_dump_wave();
               top->x =0b0001; step_and_dump_wave();
               top->x =0b0010; step_and_dump_wave();
               top->x =0b0011; step_and_dump_wave();
               top->x =0b0100; step_and_dump_wave();
               top->x =0b0101; step_and_dump_wave();
               top->x =0b0110; step_and_dump_wave();
               top->x =0b0111; step_and_dump_wave();
               top->x =0b1000; step_and_dump_wave();
               top->x =0b1001; step_and_dump_wave();
               top->x =0b1010; step_and_dump_wave();
               top->x =0b1100; step_and_dump_wave();
               top->x =0b1111; step_and_dump_wave();

  sim_exit();
}