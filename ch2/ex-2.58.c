//little-endian or big-endian
//ex-2.58.c

#include <stdio.h>

int is_little_endian() {
  short x = 0x0100; //256
  char *p = (char*) &x;
  if (p[0] == 0) {
    return 1;
  }
  return 0;
}
int main() {
  if (is_little_endian()) {
    printf("Little endian machine\n");
  } else printf("Big endian machine\n");
  return 0;
}
