#include "stdio.h"
// #include "veriuser.h"
#include "svdpi.h"
#include "VMEM__Dpi.h"
#include "mem.h"

void vmem_read(
  const svBitVecVal* addr,
  const svBitVecVal* len,
  svBitVecVal* data
) {
  printf("%x,%x,%x\n", *addr, *len, *data);
  *data = pmem_read(*addr, *len);
}
