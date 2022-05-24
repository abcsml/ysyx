#include "stdio.h"
// #include "veriuser.h"
#include "svdpi.h"
#include "VMEM__Dpi.h"
#include "mem.h"

void vmem_read(
  svBit en,
  svBit rw,
  const svBitVecVal* addr,
  const svBitVecVal* len,
  const svBitVecVal* dataIn,
  svBitVecVal* dataOut,
  svBit reset
) {
  if (reset == 1 || en == 0) {
    return;
  }
  if (rw == 1) {
    *dataOut = pmem_read(*addr, *len);
  } else {
    pmem_write(*addr, *len, *dataIn);
    *dataOut = *dataIn;
  }
  // printf("%x,%x,0x%08x,%d\n", *addr, *len, *data, reset);
}
