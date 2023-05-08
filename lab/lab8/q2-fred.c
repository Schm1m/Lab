#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int epx(int a, int b, int n) {

  int base;
  base = a + b;

  return n == 0 ? 1 : base * epx(a, b, n - 1);
}

int main(int argc, char *argv[]) {

  int a;
  int b;
  int n;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &n);

  printf("%d", epx(a, b, n));

  return 0;
}
