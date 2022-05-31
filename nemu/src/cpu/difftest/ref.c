#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  uint8_t *ref_mem = guest_to_host(addr);
  uint8_t *dut_mem = buf;
  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < n; i ++) {
      *ref_mem = *dut_mem;
      ref_mem ++;
      dut_mem ++;
    }
  } else if (direction == DIFFTEST_TO_DUT) {
    for (int i = 0; i < n; i ++) {
      *dut_mem = *ref_mem;
      ref_mem ++;
      dut_mem ++;
    }
  }
}

void difftest_regcpy(void *dut, bool direction) {
  CPU_state *ref_cpu = dut;
  if (direction == DIFFTEST_TO_REF) {
    cpu.pc = ref_cpu->pc;
    for (int i = 0;i < 32;i += 1) {
      cpu.gpr[i] = ref_cpu->gpr[i];
    }
  } else if (direction == DIFFTEST_TO_DUT) {
    ref_cpu->pc = cpu.pc;
    for (int i = 0;i < 32;i += 1) {
      ref_cpu->gpr[i] = cpu.gpr[i];
    }
  }
}

void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

void difftest_raise_intr(word_t NO) {
  assert(0);
}

void difftest_init(int port) {
  /* Perform ISA dependent initialization. */
  init_isa();
}
