#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    int n;
    int i;
    scanf("%i", &n);

    for (i = 0; i < n; i++) {

        if (i % 2 == 1) {
            printf("_");
        } else {
            printf("*");
        }

    }

    return 0;
}