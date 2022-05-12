#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  // char *head = out;
  // char *p = out;

  char *s;
  int n;

  char buf[65];
  memset(buf, 0, sizeof(buf));

  while (*fmt != '\0') {
    if (*fmt == '%') {
      fmt++;
      switch (*fmt) {
      case 's':
        s = va_arg(ap, char *);
        strncpy(out, s, strlen(s));
        out += strlen(s);
        break;
      case 'd':
        n = va_arg(ap, int);
        int n_len = n/10 + 1;
        for (int i = 0 ;i < n_len; i++) {
          buf[n_len - 1 - i] = n%10+'0';
          n /= 10;
        }
        strncpy(out, buf, n_len);
        out += n_len;
        break;
      default:
        assert(0);
        break;
      }
    } else {
      strncpy(out, fmt, 1);
      out ++;
    }
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
