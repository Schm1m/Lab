#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void toUpper(char arr[]) {

  int i;
  i = 0;

  while (arr[i] != '\0') {

    if (arr[i] >= 'a' && arr[i] <= 'z') {

      arr[i] = arr[i] - 32;
    }

    i++;
  }
}

int main(void) {

  char arr[] = "Hallo Welt";
  toUpper(arr);
  printf("%s\n", arr);
}
