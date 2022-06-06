#include <am.h>
#include <nemu.h>
#include <klib.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t data = inl(KBD_ADDR);
  if (data > KEYDOWN_MASK)
    printf("%u\n", data);
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}
