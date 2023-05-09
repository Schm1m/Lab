#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int upperLetter(int chr) { return chr >= 'A' && chr <= 'Z' ? 1 : 0; }

size_t stringLength(const char *s) { return *s ? 1 + stringLength(s + 1) : 0; }

char getFirstCapitalLetter(char *string) {

  static int i = 0;

  if (i < stringLength(string)) {

    if (upperLetter(string[i])) {

      return string[i];

    } else {

      i = i + 1;
      return getFirstCapitalLetter(string);
    }

  } else
    return 0;
}

int main(int argc, char *argv[]) {

  char inputString[20];
  char capital;

  scanf("%s", inputString);

  capital = getFirstCapitalLetter(inputString);
  capital == 0 ? printf(" ") : printf("%c", capital);

  return 0;
}
