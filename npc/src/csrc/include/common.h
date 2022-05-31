#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <assert.h>
#include <stdio.h>

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

typedef uint32_t paddr_t;
typedef uint64_t word_t;
typedef word_t vaddr_t;

#endif
