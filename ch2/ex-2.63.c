#include <stdio.h>
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

int main(int argc, char const *argv[]) {
  unsigned v = 12345678;
  unsigned y = srl(v, 16);
  show_unsigned(v);
  printf("%u\n", y);
  show_unsigned(y);
  return 0;
}
