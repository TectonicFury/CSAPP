#include <stdio.h>
#include <limits.h>
#include "show_bytes.h"

int int_shifts_are_arithmetic() {
  int x = -2;
  x = x >> 1 ;
  char *px = (char*)&x;
  if (is_little_endian()) {
    unsigned char *upx = (unsigned char*)&px[(int)sizeof(int) - 1];
    if (upx[0] == 255) return 1;
    return 0;
  } else { //big endian
    unsigned char* upx = (unsigned char*)px;
    if (upx[0] == 255) return 1;
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  printf("%d\n", int_shifts_are_arithmetic());
  return 0;
}
