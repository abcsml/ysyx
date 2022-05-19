#include "sim.h"

// static VCPU* top;

int main() {
  sim_init();
  
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();

  sim_exit();
}