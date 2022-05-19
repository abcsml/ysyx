#include "sim.h"
// #include "state.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VCPU* top;

// NPCState npc_state = { .state = NPC_STOP };

void step_and_dump_wave() {
  top->clock = 0;
  top->eval();
  top->clock = 1;
  top->eval();
  contextp->timeInc(2);
  tfp->dump(contextp->time());
}
void sim_init() {
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VCPU;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("out/cpu.vcd");
}

void sim_exit() {
  step_and_dump_wave();
  tfp->close();
}

bool cpu_step() {   // false: over
  sim_init();
  step_and_dump_wave();
  sim_exit();
}
