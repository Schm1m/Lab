// cody by tim, L4Q1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    float array[4];
    float min;
    int index = 0;
    scanf("%f %f %f %f", &array[0], &array[1], &array[2], &array[3]);  // get array inputs
    min = array[0];
    // index set to 0 and min to the first element of the array to have a "base" value to compare against
    for (int i = 0; i < 4; i++) {
        // go through the array, if the current element is smaller than the in "min" defined element set the current element as the new min
        if (array[i] <= min) {
            min = array[i];
            index = i;
        }
    }
    printf("Kleinste Zahl: %0.1f an Index %d\n", min, index);
    return 0;
}
