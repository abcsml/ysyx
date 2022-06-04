#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define MAX_STR_LEN 256

typedef struct {
  char flags;
  uint8_t width;
  char specifier;
} fmt_label;

static void fmtl2str(char *out, const char *fmtl, va_list ap) {
  char buf[65];
  memset(buf, 0, 65);
  char *s;
  int d;

  fmt_label l;
  l.flags = ' ';
  l.width = 0;
  if (*fmtl == '0') {
    l.flags = '0';
    fmtl ++;
  }
  l.width = atoi(fmtl);
  for (int i = 0; i < 2; i ++) {      // max width 99
    if (*fmtl > '0' && *fmtl < '9') {
      fmtl ++;
    }
  }
  switch (*fmtl) {
  case 's':
    s = va_arg(ap, char *);
    int sl = strlen(s);
    strncpy(out, s, sl);
    out += sl;
    break;
  case 'd':
    d = va_arg(ap, int);
    char *d_buf = buf;

    // int neg = 0;
    if (d < 0) { *d_buf = '-'; d_buf++; }

    int d_len = 1;
    int d_var = d/10;
    while (d_var != 0) { d_var /= 10; d_len ++; }
    
    for (int i = 0; i < (l.width - d_len); i ++) {
      *d_buf = l.flags;
      d_buf ++;
    }

    for (int i = 0 ;i < d_len; i++) {
      d_buf[d_len - 1 - i] = d%10+'0';
      d /= 10;
    }
    strcpy(out, buf);
    out += d_len;
    break;
  default:
    assert(0);
    break;
  }
  fmtl ++;
}

int printf(const char *fmt, ...) {
  char out[MAX_STR_LEN];
  // int n = sprintf(out, fmt);
  // for (int i = 0; i < 256 && out[i] != '\0'; i ++) {
  //   putch(out[i]);
  // }
  // return n;
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  for (int i = 0; i < 256 && out[i] != '\0'; i ++) {
    putch(out[i]);
  }
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int i = MAX_STR_LEN;
  const char *fmtl = fmt;

  while (*fmtl != '\0' && i --) {
    if (*fmtl == '%') {
      fmtl++;
      fmtl2str(out, fmtl, ap);
    }
    strncpy(out, fmtl, 1);
    out ++;
    fmtl ++;
  }
  strncpy(out, fmtl, 1);
  return 0;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
