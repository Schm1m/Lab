#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    int rows;
    int cols;

    int i;
    int j;
    int k;

    scanf("%d", &rows);
    scanf("%d", &cols);

    /* k could be moved in scope */

    k = 1;

    for (i = 0; i < rows; i++) {

        for (j = 0; j < cols; j++) {

            printf(k == 1 ? "+" : "-");

            /* setting k to new value
             * k = 1 then -1
             * k = -1 then 1 */

            k *= -1;

        }

        if (cols % 2 == 0) {

            k *= -1;

        }

        printf("\n");

    }

    return 0;
}