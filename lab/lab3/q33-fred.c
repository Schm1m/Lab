#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    int n;
    int m;
    scanf("%i", &n);
    scanf("%i", &m);

    int i;
    int j;

    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) {
            printf("*");
        }

        printf("\n");

    }

    return 0;
}