#include "cpu.h"
// #include "state.h"

static VerilatedContext* contextp = NULL;
static VerilatedVcdC* tfp = NULL;

static VCPU* top;
CPU_state cpu;

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

static void step_and_dump_wave() {
  top->clock = top->clock == 1?0:1;
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
static void sim_init() {
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VCPU;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("out/cpu.vcd");
}

static void sim_exit() {
  // step_and_dump_wave();
  tfp->close();
}

void display() {
  printf("pc : 0x%lx \n", top->io_pc);
  uint64_t *p_regs = &top->io_regs_0;
    for (int i = 0; i < 32; i += 2) {
      printf("%s : 0x%08lx \t %s : 0x%08lx\n", regs[i], p_regs[i], regs[i+1], p_regs[i+1]);
    }
}

static void cpu_exec_once() {
  step_and_dump_wave();
  step_and_dump_wave();
  cpu.pc = top->io_pc;
  uint64_t *p_regs = &top->io_regs_0;
  for (int i = 0; i < 32; i ++) {
    cpu.gpr[i] = p_regs[i];
  }
}

void cpu_exec(int n) {
  for (int i = 0; i < n; i ++) {
    word_t pc = top->io_pc;
    step_and_dump_wave();
    step_and_dump_wave();
    cpu.pc = top->io_pc;
    uint64_t *p_regs = &top->io_regs_0;
    for (int i = 0; i < 32; i ++) {
      cpu.gpr[i] = p_regs[i];
    }
#ifdef CONFIG_DIFFTEST
    difftest_step(pc, cpu.pc);
#endif
  }
}

bool cpu_run() {   // false: over
  while (cpu.pc != 0x87ffffff) {
    display();
    word_t last_pc = top->io_pc;
    cpu_exec_once();
#ifdef CONFIG_DIFFTEST
    if (cpu.pc < 0x87fffff0) {
      difftest_step(last_pc, cpu.pc);
    }
#endif
    if (cpu.pc == 0x87fffff0) {
      printf("------- not impl --------\n");
      sim_exit();
      return false;
    }
    if (cpu.pc == 0x87fffff1) {
      printf("-------- difftest fail --------\n");
      display();
      sim_exit();
      return false;
    }
  }
  sim_exit();
  if (cpu.gpr[10] == 0) {
    printf("--------- good trap -----------\n");
  } else {
    printf("--------------- bad trap ------------------\n");
  }
  return false;
}

void init_cpu() {
  sim_init();
  top->reset = 1;
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  top->reset = 0;
  cpu.pc = top->io_pc;
}
