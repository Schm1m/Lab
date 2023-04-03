#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* initializing two integers
     * C90 style, also the i int */

    int i;
    int j;

    unsigned int size;
    size = 0;

    scanf("%u", &size);

    /* imported: the loop is stated at one, cause
     * wouldn't work and make sense for i / j = 0... */

    for (i = 1; i <= size; i++) {

        for (j = 1; j <= size; j++) {

            /* logic:
             * - checking diagonal condition
             * - checking second diagonal
             *
             * in a nutshell: is it limited by a side? */

            printf((i == 1) || (i == size) || (j == 1) || (j == size) || (i == j) ||
                   (j == (size - i + 1)) ? "*" : " ");

        }

        printf("\n");

    }

    return 0;
}