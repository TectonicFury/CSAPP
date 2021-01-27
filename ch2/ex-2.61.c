#include <stdio.h>
#include <limits.h>
int main(int argc, char const *argv[]) {
  int x = INT_MIN;
  printf("%d\n", ((x + INT_MIN) & ~0) && 1);
  return 0;
}
