#include <stdio.h>

int leftmost_one_basic(unsigned x) {
  //all i could come up with
  int l = 31;
  int i;
  for (i = 0; i < 32; i++) {
    if (x & (1 << (l - i))) {
      return (1 << (l - i));
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  printf("0x%x\n", leftmost_one_basic(0xff00));
  printf("0x%x\n", leftmost_one_basic(0x0));
  return 0;
}
