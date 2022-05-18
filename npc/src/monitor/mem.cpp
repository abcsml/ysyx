#include "stdio.h"
// #include "veriuser.h"
#include "svdpi.h"
#include "VMEM__Dpi.h"

void pmem_read(
  const svBitVecVal* addr,
  const svBitVecVal* len,
  svBitVecVal* data
) {
  printf("%d,%d,%d", *addr, *len, *data);
  *data = 0x108093;
}
