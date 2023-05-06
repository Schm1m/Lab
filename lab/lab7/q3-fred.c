#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char *ownStrcpy(char dest[], char src[]) {

  int i;
  i = 0;

  while (src[i] != '\0') {

    dest[i] = src[i];
    i++;
  }

  dest[i] = '\0';
  return dest;
}

int main(void) {

  char originalString[] = "Programmieren";
  char copiedString[40];
  ownStrcpy(copiedString, originalString);
  printf("%s", copiedString);
}
