#include "stdio.h"
// #include "veriuser.h"
#include "svdpi.h"
#include "VMEM__Dpi.h"
#include "mem.h"

word_t data;

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
    data = pmem_read(*addr, *len);
    *dataOut = data;
    *(dataOut + 1) = data >> 32;
  } else {
    data = *dataIn | (*(dataIn + 1) << 32);
    pmem_write(*addr | (*(addr + 1) << 32), *len, data);
    *dataOut = *dataIn;
    *(dataOut + 1) = *(dataIn + 1);
  }
  // printf("%lx,%x,0x%lx,%d\n", *addr, *len, *dataOut, reset);
}
