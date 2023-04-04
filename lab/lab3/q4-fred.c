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

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= m; j++) {

            printf(i == 1 || i == n || j == 1 || j == m ? "*" : " ");

        }

        printf("\n");

    }

    return 0;
}