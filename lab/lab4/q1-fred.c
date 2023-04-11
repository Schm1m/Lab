#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* bad take to min. the array to four
     * will give unpredictable C shit if
     * called with more plus four elements */
    double nums[4];
    double smallest;
    int i;

    /* looping and putting the input into the array */
    for (i = 0; i < 4; ++i) {

        scanf("%lf", &nums[i]);

    }

    /* simple sorting algorithm */
    smallest = nums[0];
    int index = 0;

    for (i = 0; i < 4; i++) {

        if (nums[i] < smallest) {

            smallest = nums[i];
            index = i;

        }

    }

    printf("Kleinste Zahl: %.1lf an Index %d\n", smallest, index);


    return 0;

}