#ifndef __SIM_H__
#define __SIM_H__

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VCPU.h"

#include "common.h"

typedef struct {
  word_t pc;
  word_t gpr[32];
} CPU_state;

// void step_and_dump_wave();
// void sim_init();
// void sim_exit();

extern CPU_state cpu;
bool cpu_run();


#endif
