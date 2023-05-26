#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/* (5.1 + 2 * 3.2) + (5.1+4*3.2) + (5.1+6*3.2) + (5.1+8*3.2) = 84.4 */

void series(double a, double x, double n) {

  int i;
  double result = 0;

  for (i = 1; i < n + 1; i++) {

    result += (a + (2 * i) * x);
  }

  printf("%.1lf", result);
}

int main(int argc, char *argv[]) {

  double a;
  double n;
  double x;

  /* IMPORTANT: ORDER */
  scanf("%lf %lf %lf", &a, &x, &n);

  series(a, x, n);

  return 0;
}
