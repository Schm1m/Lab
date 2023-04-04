#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[]) {

    /* initializing two integers
     * C90 style, also the i int */

    int n = 0;
    int i = 0;
    scanf("%i", &n);

    for (i = 0; i < n; i++) {
        printf("*");
    }

    /*while (i < n) {
        printf("*");
        i++;
    }*/

    /*do {
        printf("*");
        i++;
    } while (i < n);*/

    return 0;
}