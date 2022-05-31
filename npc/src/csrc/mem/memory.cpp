#include "mem.h"
#include "cpu.h"

static uint8_t pmem[CONFIG_MSIZE] = {};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    case 8: return *(uint64_t *)addr;
  }
  assert(0);
}

static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    case 8: *(uint64_t *)addr = data; return;
  }
  assert(0);
}

static inline bool in_pmem(paddr_t addr) {
  return (addr >= CONFIG_MBASE) && (addr < (paddr_t)CONFIG_MBASE + CONFIG_MSIZE);
}

static void out_of_bound(paddr_t addr) {
  printf("out of bound addr: 0x%x\n", addr);
  assert(0);
}

word_t pmem_read(paddr_t addr, int len) {
  if (in_pmem(addr) == false) { out_of_bound(addr); return 0; }
  word_t ret = host_read(guest_to_host(addr), len);
#ifdef CONFIG_MTRACE    // MTRACE
  if (addr != cpu.pc)   // filter pc read
    printf("READ  MEM 0x%08x: 0x%08lx\n", addr, ret);
#endif
  return ret;
}

void pmem_write(paddr_t addr, int len, word_t data) {
  if (in_pmem(addr) == false) { out_of_bound(addr); return; }
  host_write(guest_to_host(addr), len, data);
#ifdef CONFIG_MTRACE
  printf("WRITE MEM 0x%08x: 0x%08lx [len:%d]\n", addr, data, len);
#endif
}

// word_t vmem_read(paddr_t addr, int len) {
//   word_t ret = host_read(guest_to_host(addr), len);
//   return ret;
// }

// void vmem_write(paddr_t addr, int len, word_t data) {
//   host_write(guest_to_host(addr), len, data);
// }




