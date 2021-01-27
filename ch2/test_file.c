//file to test ideas
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>
#include "show_bytes.h"
#include "str.h"
#include "number_rep.h"
int get_msb(int x) {
  unsigned y = (unsigned)x;
  y = y >> 24;
  return y;
}
int main() {
  int n, m;
  n = 100;
  m = -100;
  str sn, sm;
  sn = dec_to_bin(-400);
  printf("%" PRIu64 "\n", (uint64_t)-10);
  //sm = dec
  print_str(sn);
  char c = get_msb(INT_MAX);
  printf("msb = %d\n", c);
  sn = dec_to_bin(c);
  print_str(sn);
  int k = (-400000 & ~0) && 1;
  printf("%d\n", k);
  
  return 0;
}
