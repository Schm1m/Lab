#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    int i;
    int k;

    printf("Celsius\tFahrenheit\n");

    /* using the width trick with *, which tells
     * the full width, number included */

    for (i = -20; i <= 300; i = i + 20) {
        k = ((i * 9) / 5) + 32;
        printf("%*d\t%*d\n", 7, i, 10, k);
    }

    return 0;
}