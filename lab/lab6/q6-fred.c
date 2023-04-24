#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int stringlength(const char input[]) {

    int i;
    i = 0;

    while (input[i] != '\0') {

        i++;

    }

    return i;

}

int main(void) {

    char test[] = "Hochschule Esslingen";
    printf("%s hat %d Zeichen", test, stringlength(test));

}