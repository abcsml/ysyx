#ifndef __SIM_H__
#define __SIM_H__

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VCPU.h"

void step_and_dump_wave();
void sim_init();
void sim_exit();


#endif
