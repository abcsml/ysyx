#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  printf("pc : 0x%lx npc: 0x%lx\n", cpu.pc, pc);
  return true;
}

void isa_difftest_attach() {
}
