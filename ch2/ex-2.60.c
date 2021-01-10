//ex-2.60.c

#include <stdio.h>
#include <limits.h>
#include "show_bytes.h"
unsigned replace_byte(unsigned x, int i, unsigned char b) {
  char *p = (char*) &x;
  p[i] = (p[i] & 0x00) | b;
  return x;
}

int main() {
  unsigned x = UINT_MAX;
  unsigned y = replace_byte(x, 0, 0);
  printf("%u\n", y);
  show_unsigned(x);
  show_unsigned(y);
  unsigned int c = replace_byte(0x12345678, 0, 0xAB);
  show_unsigned(c);
  return 0;
}
