#include <stdio.h>

int fib(int input) {

  int a = 1;
  int b = 1;

  if (input <= 2)
    return 1;

  int i = 1;
  while (i < input) {

    int c = a + b;
    a = b;
    b = c;

    ++i;
  }

  return a;
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
