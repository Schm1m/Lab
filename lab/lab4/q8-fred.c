#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {


    /* variables */
    int i;
    float input;
    int num = 0;
    float grade = 0;

    int grades[10];

    /* simple while loop
     * could be solved with break and while (1) */
    i = 0;
    while (i < 10) {

        scanf("%f", &input);
        if (input < 1 || input > 6) {
            break;
        }

        grades[i] = input;
        num++;

        i++;

    }

    int j;

    /* not super clean because the narrowing conversion
     * from int to float, but who cares. */
    for (j = 0; j < num; j++) {

        grade += grades[j];
    }

    /* edge case */
    float all;
    if (num == 0) {
        all = 0;
    } else { all = grade / num; }

    printf("Durchschnitt (N=%d): %0.2f\n", num, all);

    return 0;

    /* 1 1 1 1 1 1 1 1 0.0 2 3 4 5 5
     * what the fuck, should 0.0 not end the input?
     * but the test wants it to run...
     * shitty. */

}
