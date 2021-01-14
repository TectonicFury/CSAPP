#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "number_rep.h"
#include "show_bytes.h"
#include <limits.h>
float sum_elements(float a[], unsigned length) {
  int i;
  float res = 0;
  for (i = INT_MAX - 1; i <= length; i++) {
    printf("%d\n", i);
    //res += a[i];
  }
  return res;
}

int mult_overflow(int x, int y) {
  if (abs(INT_MIN/x) > y) {
    return 1;
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  str s, st;

  printf("Enter the dec string\n");

  //st = hex_to_bin(s);
  //print_str(st);
  int c = 53191;
  st = dec_to_bin(c);
  print_str(st);
  show_int(c);
  float a[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
  //sum_elements(a, INT_MAX + 100u);
  show_unsigned(UINT_MAX + UINT_MAX);
  st = read_str();
  str st1 = hex_to_bin(st);
  print_str(st1);
  unsigned x, y;
  x = 100;
  y = UINT_MAX - (x - 1);
  show_unsigned(x);
  show_unsigned(y);
  printf("%u\n", x+y);
  int u, v, z;
  u = INT_MIN;
  v = INT_MIN;
  z = u + v;
  show_int(u);
  show_int(z);
  printf("%d\n", z);

  int p = mult_overflow(100000, 200000);
  printf("%d\n", p);
  //scanf("%d", &c);
  //printf("%d\n", c);
  /*long long x = hex_to_dec(s);
  printf("%llx\n", x);
  int32_t c;
  scanf("%d", &c);
  int t = -2147483647 - 1;
  int u = 2147483647;
  show_int(t);
  show_long(u);
  show_long((long)t);*/
  //float k = 3510593.0;
  //print_str(s);
  //show_int(c);
  //show_float(k);
  //str sty = read_str();
  //print_str(st);
  //unsigned short x = 10000;
  //show_short(x);
  //printf("above address = %p\n", &x);
  //show_float(x);
  //long long l = hex_to_dec(sty);
  //printf("%f\n", (float)l);
  //print_str(dec_to_bin(33));
  //print_str(st);
  //printf("%p\n", st.pstr);
  //printf("sizeof long = %ld\n", sizeof(long long));
  //int x = 12345;*/

  /*printf("%d\n", x);
  show_int(x);
  printf("size of void* %ld\n", sizeof(void*));
  show_pointer(&x);
  printf("hi  %f\n", (float)x);
  int a = 0x12345678;
  byte_pointer ap = (byte_pointer) &a; show_bytes(ap, 1);
  show_bytes(ap, 2);
  show_bytes(ap, 3);
  */
  //const char *m = "mnopqr";
  //show_bytes((byte_pointer) m, strlen(m));
  return 0;
}
