#include <stdio.h>
#include <assert.h>
int odd_ones(unsigned x) {
  //picked this up from stackoverflow and dreamAndDead gitbook
  //https://dreamanddead.gitbooks.io/csapp-3e-solutions/content/chapter2/2.65.html
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  x &= 0x1;
  return x;
}

int odd_ones_basic(unsigned x) {
  //turns out that this technique is equally valid as far as solving the problem is concerned
  int count = 0;
  int l = 0;
  while (l < 32) {
    if ((x & (1 << l)) && 1) count++;
    l++;
  }
  return count & 0x01;
}
int main(int argc, char const *argv[]) {
  assert(odd_ones_basic(0x01010100));
  assert(!odd_ones_basic(0x10101010));
  return 0;
}
