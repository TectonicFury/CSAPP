#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "number_rep.h"
#include "show_bytes.h"


int main(int argc, char const *argv[]) {
  str s, st;

  printf("Enter the hex string\n");
  s = read_str();
  //int c = 2607352;
  //scanf("%d", &c);
  //printf("%d\n", c);
  st = hex_to_bin(s);
  //float k = 3510593.0;
  //print_str(s);
  //show_int(c);
  //show_float(k);
  //str sty = read_str();
  print_str(st);
  unsigned short x = 10000;
  show_short(x);
  printf("above address = %p\n", &x);
  show_float(x);
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
