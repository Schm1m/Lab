#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int minimum(const int pInt[], int i) {

  int min = pInt[0];

  int j;
  j = 0;

  while (j < i) {

    if (pInt[j] < min) {

      min = pInt[j];
    }

    j++;
  }

  return min;
}

int main(void) {

  int numbers[] = {4, 6, 9, 5};
  printf("%d", minimum(numbers, 4));
}
