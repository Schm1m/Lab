#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     * using a constant for the array size
     */
    int const arraySize = 4;
    int input[arraySize];

    /*
     * scanning while size of array isn't hit
     */
    int i = 0;
    while (i < arraySize) {

        scanf("%d", &input[i]);

        i++;

    }

    /*
     * calculating the stuff
     */
    int j = 0;
    float sum = 0;
    while (j < arraySize) {

        sum += input[j];

        j++;

    }

    float average;
    average = sum / arraySize;

    /*
     * because i am lazy, we use a float sum,
     * and trim it with a ".", because it is
     * easier to do that than casting or any
     * other stizzz. for steve. 💦
     */
    printf("Summe: %.f\n", sum);
    printf("Durchschnitt: %f", average);

    return 0;

}
