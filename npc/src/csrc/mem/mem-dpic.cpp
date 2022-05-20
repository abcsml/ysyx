#include "stdio.h"
// #include "veriuser.h"
#include "svdpi.h"
#include "VMEM__Dpi.h"
#include "mem.h"

void vmem_read(
  const svBitVecVal* addr,
  const svBitVecVal* len,
  svBitVecVal* data,
  svBit reset
) {
  printf("%x,%x,%x,%d\n", *addr, *len, *data, reset);
  if (reset != 1) {
    *data = pmem_read(*addr, *len);
  }
}
