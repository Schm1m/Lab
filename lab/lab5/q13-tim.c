// cody by tim, L5Q13

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int array[4];  // define array
    int sum = 0;   // pre-define vars for sum and average
    float avrg;    //
    for (int i = 0; i < 4; i++) {
        scanf("%d", &array[i]);  // read inputs into the array
    }
    for (int i = 0; i < 4; i++) {
        sum += array[i];  // calculate sum
    }
    avrg = sum / 4.0;                                    // calculate average
    printf("Summe: %d\nDurchschnitt: %f\n", sum, avrg);  // return sum and average
    return 0;
}
