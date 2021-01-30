#include <stdio.h>
#include <limits.h>
#include "show_bytes.h"

unsigned srl(unsigned x, int k) {
  unsigned xsra = (int) x >> k;
  int l = 8*sizeof(int) - k - 1;
  unsigned y = 0;
  for ( ; l >= 0; l--) {
    y += 1 << l;
  }
  xsra = xsra & y;
  return xsra;
}

unsigned sra(int x, int k) {
  int xsrl = (unsigned) x >> k;
  if (x > 0) return xsrl;
  unsigned y = 0;
  for (size_t i = 0; i <= k; i++) {
    y += 1 << (31 - i);
  }
  return xsrl | y;
}

int main(int argc, char const *argv[]) {
  int v = 16;
  unsigned y = sra(v, 4);
  show_unsigned(v);
  printf("%u\n", y);
  show_unsigned(y);
  return 0;
}
