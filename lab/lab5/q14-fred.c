#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     * giving my array a extra cool name.
     */
    int const arraySize = 4;
    int myFirstArray[arraySize];

    /*
     * scanning!
     */
    int i = 0;
    while (i < arraySize) {

        scanf("%d", &myFirstArray[i]);

        i++;

    }

    int *pnt = &myFirstArray[2];

    /*
     * printing!
     */
    int j = 0;
    while (j < arraySize) {

        printf("%d ", myFirstArray[j]);

        j++;

    }

    printf("\n");
    *pnt = 42;

    /*
     * printing!
     */
    int k = 0;
    while (k < arraySize) {

        printf("%d ", myFirstArray[k]);

        k++;

    }

    return 0;

}

/*
 * (‿|‿)
 */