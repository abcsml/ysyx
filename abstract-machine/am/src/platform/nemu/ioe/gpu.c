#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static uint32_t w;
static uint32_t h;

void __am_gpu_init() {
  // int i;
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  w = inw(VGACTL_ADDR + 2);
  h = inw(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *p = ctl->pixels;
  for (uint32_t i = ctl->y; i < ctl->y + ctl->h; i ++) {
    for (uint32_t j = ctl->x; j < ctl-> x + ctl->w; j ++) {
      outl(FB_ADDR + i*4*w + j*4, *p);
      // outl(FB_ADDR, *p);
      p ++;
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
