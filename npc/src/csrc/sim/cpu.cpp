#include "sim.h"
// #include "state.h"

// #define R(x) top->io_regs_##x

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VCPU* top;

// NPCState npc_state = { .state = NPC_STOP };

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void step_and_dump_wave() {
  top->clock = top->clock == 1?0:1;
  top->eval();
  // top->clock = 1;
  // top->eval();
  contextp->timeInc(1);
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
  // step_and_dump_wave();
  tfp->close();
}

#define DISPLAY_REGS(i,j) printf("%s : 0x%08lx \t %s : 0x%08lx\n", regs[i], top->io_regs_##i, regs[j], top->io_regs_##j);
void display() {
  printf("pc : 0x%lx \n", top->io_pc);
  DISPLAY_REGS(0,1); DISPLAY_REGS(2,3); DISPLAY_REGS(4,5); DISPLAY_REGS(6,7);
  DISPLAY_REGS(8,9); DISPLAY_REGS(10,11); DISPLAY_REGS(12,13); DISPLAY_REGS(14,15);
  DISPLAY_REGS(16,17); DISPLAY_REGS(18,19); DISPLAY_REGS(20,21); DISPLAY_REGS(22,23);
  DISPLAY_REGS(24,25); DISPLAY_REGS(26,27); DISPLAY_REGS(28,29); DISPLAY_REGS(30,31);
}

bool cpu_step() {   // false: over
  sim_init();
  // top->reset = 1;
  // top->eval();
  // top->clock = 0;
  // top->reset = 1;
  // top->io_pc = 0x80000000;
  // top->clock = 0; top->eval(); display();
  // top->clock = 1; top->eval(); display();
  // top->reset = 0;
  int i = 8;
  while (top->io_pc != 0x87ffffff) {
    display();
    step_and_dump_wave();
    step_and_dump_wave();
  }
  sim_exit();
  // if top->
  return false;
}
