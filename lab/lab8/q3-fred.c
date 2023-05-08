#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int faculty(int input) { return input == 0 ? 1 : input * faculty(input - 1); }

int input() {

  int input;

  scanf("%d", &input);

  return input;
}

int main(int argc, char *argv[]) {

  int printHelper123;
  printHelper123 = input();

  printf("%d! = %d", printHelper123, faculty(printHelper123));

  return 0;
}
