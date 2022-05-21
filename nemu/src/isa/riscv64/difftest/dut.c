#include <isa.h>
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  if (ref_r->pc != cpu.pc) return false;
  for (int i = 0;i < 32;i += 2) {
    if (cpu.gpr[i] != ref_r->gpr[i]) {
      printf("[%s] dut: 0x%08lx \t ref: 0x%08lx\n", regs[i], cpu.gpr[i], ref_r->gpr[i]);
      return false;
    }
  }
  return true;
}

void isa_difftest_attach() {
}
