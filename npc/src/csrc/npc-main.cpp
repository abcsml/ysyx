#include "sim.h"
#include <stdio.h>

// static VCPU* top;

int main(int argc, char *argv[]) {
  printf("hello\n");
  sim_init();
  
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();
  step_and_dump_wave();

  sim_exit();
}