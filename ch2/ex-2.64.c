#include <stdio.h>

int any_one_odd(unsigned x) {
  unsigned y = 1;
  int l = 2;
  while (l < 32) {
    y += (1 << l);
    l += 2;
  }
  return (x & y) && 1;
}

int main(int argc, char const *argv[]) {
  unsigned x = 32;
  printf("%d\n", any_one_odd(x));
  return 0;
}
