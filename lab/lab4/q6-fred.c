#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* initial of the variables */
    char input[40], output[40];
    int i = 0, OGlower, lower, OGupper, upper;

    scanf("%s %d %d", input, &lower, &upper);

    /* copy because we mess with the numbers */
    OGlower = lower;
    OGupper = upper;

    /* simple while loop */
    while (lower <= upper) {

        output[i] = input[lower];
        i++;
        lower++;

    }

    output[i] = '\0';

    printf("%s %d-%d: %s", input, OGlower, OGupper, output);

    return 0;

}