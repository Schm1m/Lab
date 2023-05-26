#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int epx(int a, int b, int n) {

  int base;
  base = a + b;

  int i;

  int result;
  result = 1;

  for (i = 0; i < n; ++i) {

    result *= base;
  }

  printf("%d", result);
}

int main(int argc, char *argv[]) {

  int a;
  int b;
  int n;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &n);

  epx(a, b, n);

  return 0;
}
