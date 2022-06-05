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

static int fmtl2str(char *out, const char *fmtl, va_list ap) {
  // char *fmtl = **fmt;
  int fmt_len = 0;
  // int out_len = 0;
  // char buf[65];
  // memset(buf, 0, 65);
  char *s;
  int d;

  fmt_label l;
  l.flags = ' ';
  l.width = 0;
  if (*fmtl == '0') {
    l.flags = '0';
    fmtl ++;
    fmt_len ++;
  }
  l.width = atoi(fmtl);
  for (int i = 0; i < 2; i ++) {      // max width 99
    if (*fmtl > '0' && *fmtl < '9') {
      fmtl ++;
      fmt_len ++;
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
    // char *d_buf = buf;

    // int neg = 0;
    if (d < 0) {
      *out = '-';
      out++;
    }

    int d_len = 1;
    int d_var = d/10;
    while (d_var != 0) { d_var /= 10; d_len ++; }
    
    for (int i = 0; i < (l.width - d_len); i ++) {
      *out = l.flags;
      out ++;
    }

    for (int i = 0 ;i < d_len; i++) {
      out[d_len - 1 - i] = d%10+'0';
      d /= 10;
    }
    out += d_len;
    break;
  default:
    assert(0);
    break;
  }
  *out = '\0';
  fmtl ++;
  fmt_len ++;
  return fmt_len;
}

int printf(const char *fmt, ...) {
  char out[MAX_STR_LEN];
  
  va_list ap;
  va_start(ap, fmt);
  int ret = vsprintf(out, fmt, ap);
  for (int i = 0; i < MAX_STR_LEN && out[i] != '\0'; i ++) {
    putch(out[i]);
  }
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  int i = MAX_STR_LEN;
  char buf[MAX_STR_LEN];
  // int fmt_len = 0;
  // const char *fmtl = fmt;

  while (*fmt != '\0' && i --) {
    if (*fmt == '%') {
      fmt++;
      fmt += fmtl2str(buf, fmt, ap);
      strcpy(out, buf);
      out += strlen(buf);
    }
    strncpy(out, fmt, 1);
    out ++;
    fmt ++;
  }
  strncpy(out, fmt, 1);
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
