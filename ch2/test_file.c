//file to test ideas
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <inttypes.h>
#include "show_bytes.h"
#include "str.h"
#include "number_rep.h"
int main() {
  int n, m;
  n = 100;
  m = -100;
  str sn, sm;
  sn = dec_to_bin(-400);
  printf("%" PRIu64 "\n", (uint64_t)-10);
  //sm = dec
  print_str(sn);
  return 0;
}
