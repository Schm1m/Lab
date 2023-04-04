#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    float i;
    float k;

    printf("Fahrenheit\tCelsius\n");

    /* using the width trick with *, which tells
     * the full width, number included */

    /* actually never use a float for the loop
     * induction expression, i just don't care */

    for (i = -20; i <= 300; i = i + 20) {
        k = (5 * (i - 32)) / 9;
        printf("%*.0f\t%*.2f\n", 10, i, 7, k);
    }

    return 0;
}