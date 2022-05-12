#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>
// #include <string.h>   ?????

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  for (len = 0; s[len] != '\0'; len++);
  return len;
}

char *strcpy(char *dst, const char *src) {
  size_t i;
  for (i = 0; src[i] != '\0'; i++)
    dst[i] = src[i];
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++)
    dst[i] = src[i];
  for ( ; i < n; i++)
    dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t dst_len = strlen(dst);
  size_t i;
  for (i = 0 ; src[i] != '\0' ; i++)
    dst[dst_len + i] = src[i];
  dst[dst_len + i] = '\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  size_t i;
  for (i = 0; s1[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      if (s1[i] < s2[i])
        return -1;
      else
        return 1;
    }
  }
  if (s2[i] != '\0')
    return -1;
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  for (i = 0; i < n && s1[i] != '\0'; i++) {
    if (s1[i] != s2[i]) {
      if (s1[i] < s2[i])
        return -1;
      else
        return 1;
    }
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  if (s == NULL || n == 0)
    return NULL;
  uint8_t *pS = s;

  for (size_t i = 0; i < n; i++) {
    pS[i] = (uint8_t) c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  if (dst == NULL || src == NULL || n == 0)
    return NULL;
  uint8_t *pDst = dst;
  const uint8_t *pSrc = src;

  if (dst < src) {  // front to back
    for (size_t i = 0; i < n; i++)
      pDst[i] = pSrc[i];
  } else {          // reserve
    for (size_t i = n-1; i >= 0; i--)
      pDst[i] = pSrc[i];
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  if (out == NULL || in == NULL || n == 0)
    return NULL;
  uint8_t *pOut = out;
  const uint8_t *pIn = in;

  for (size_t i = 0; i < n; i++)
    pOut[i] = pIn[i];
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  if (s1 == NULL || s2 == NULL)
    return 0;
  const uint8_t *pS1 = s1;
  const uint8_t *pS2 = s2;
  size_t i;
  for (i = 0; i < n; i++) {
    if (pS1[i] != pS2[i]) {
      if (pS1[i] < pS2[i])
        return -1;
      else
        return 1;
    }
  }
  return 0;
}

#endif
