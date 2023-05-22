#include <stdio.h>

int fib(int input) {

  switch (input) {

  case 0:
    return 0;

  case 1:
    return 1;

  default:
    return fib(input - 1) + fib(input - 2);
  }
}

int main(int argc, char *argv[]) {

  int userInput;

  while (1) {

    scanf("%d", &userInput);

    if (userInput < 2) {

    } else {

      break;
    }
  }

  int result;
  result = fib(userInput);
  printf("%d", result);

  return 0;
}
