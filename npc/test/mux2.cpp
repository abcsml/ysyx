#include "verilated.h"
#include "verilated_vcd_c.h"

#include <Vmux2.h>

#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;

Vmux2* top = new Vmux2;
VerilatedVcdC* tfp = new VerilatedVcdC;
VerilatedContext* contextp = new VerilatedContext;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  top->trace(tfp, 0);
  tfp->open("output/mux2.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  Verilated::traceEverOn(true);
  sim_init();

  top->s=0; top->a=0; top->b=0;  step_and_dump_wave();   // 将s，a和b均初始化为“0”
                      top->b=1;  step_and_dump_wave();   // 将b改为“1”，s和a的值不变，继续保持“0”，
            top->a=1; top->b=0;  step_and_dump_wave();   // 将a，b分别改为“1”和“0”，s的值不变，
                      top->b=1;  step_and_dump_wave();   // 将b改为“1”，s和a的值不变，维持10个时间单位
  top->s=1; top->a=0; top->b=0;  step_and_dump_wave();   // 将s，a，b分别变为“1,0,0”，维持10个时间单位
                      top->b=1;  step_and_dump_wave();
            top->a=1; top->b=0;  step_and_dump_wave();
                      top->b=1;  step_and_dump_wave();

  sim_exit();
}
