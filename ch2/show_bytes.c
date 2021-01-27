#include "show_bytes.h"

int is_little_endian() {
  short x = 0x0100; //256
  char *p = (char*) &x;
  if (p[0] == 0) {
    return 1;
  }
  return 0;
}
void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i=0;i<len;i++)
    printf(" %.2x", start[i]);
    printf("\n");
}
void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}
void show_unsigned(unsigned x) {
  show_bytes((byte_pointer) &x, sizeof(unsigned));
}
void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}
void show_short(short x) {
  show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
  show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x) {
  printf("inner adderes = %p\n", &x);
  printf("%d\n", (short)x);
  printf("%lf\n", x);
  show_bytes((byte_pointer) &x, sizeof(double));
}
void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}
