/*
 *
 * quiz 6 question 9
 * ( ͡° ͜ʖ ͡°)
 *
 */

#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double celsius(int input) {

    /*
     * again, using the float trick for
     * enhanced precision
     */
    return (input - 32) * (5.0 / 9.0);

}

int main(void) {

    printf("%dF = %.1fC", 20, celsius(20));

}