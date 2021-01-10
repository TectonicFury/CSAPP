#include <stdio.h>

int x_y_mask(int x, int y) {
  return (y & 0xffffff00)|(x & 0x000000ff);
}

int main() {
  int x, y;
  printf("Enter x and y\n");
  scanf("%x", &x);
  scanf("%x", &y);
  printf("%x\n", x_y_mask(x, y));
  return 0;
}
