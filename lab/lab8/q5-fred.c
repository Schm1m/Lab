#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* (5.1 + 2 * 3.2) + (5.1+4*3.2) + (5.1+6*3.2) + (5.1+8*3.2) = 84.4 */

double series(double a, double x, double n) {

  return n == 1 ? a + 2 * x : series(a, x, n - 1) + (a + 2 * n * x);
}

int main(int argc, char *argv[]) {

  double a;
  double n;
  double x;

  /* IMPORTANT: ORDER */
  scanf("%lf %lf %lf", &a, &x, &n);

  printf("%.1lf", series(a, x, n));

  return 0;
}
