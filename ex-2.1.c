#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "number_rep.h"

int main(int argc, char const *argv[]) {
  str s, st;

  printf("Enter the binary string\n");
  s = read_str();
  st = bin_to_hex(s);
  print_str(st);
  return 0;
}
