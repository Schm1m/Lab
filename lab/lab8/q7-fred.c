#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isPrime(unsigned int i, unsigned int number) {

  if (number == i) {

    return 0;

  } else
    return number % i == 0 ? 1 : isPrime(i + 1, number);
}

int main(int argc, char *argv[]) {

  unsigned int number;
  scanf("%u", &number);

  if (number == 1) {

    printf("0");
    return 0;
  }

  printf(isPrime(2, number) == 0 ? "1" : "0");

  return 0;
}
