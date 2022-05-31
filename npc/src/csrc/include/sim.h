#ifndef __SIM_H__
#define __SIM_H__

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VCPU.h"

#include "common.h"

typedef struct {
  word_t gpr[32];
  word_t pc;
} CPU_state;

extern const char *regs[];

// void step_and_dump_wave();
// void sim_init();
// void sim_exit();

extern CPU_state cpu;

void init_cpu();
bool cpu_run();

void difftest_step(vaddr_t pc, vaddr_t npc);
void init_difftest(char *ref_so_file, long img_size, int port);


#endif
