// cody by tim, L9Q3

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y) {  // function for comparing 2 elements
    return (*(int *)x - *(int *)y);
}

int main(void) {
    int arrSize;                            // initiate vars
    int *array;                             //
    scanf("%d", &arrSize);                  // get array size
    array = malloc(arrSize * sizeof(int));  // allocate memory for array
    for (int i = 0; i < arrSize; i++) {     // fill array with inputs
        int temp;
        scanf("%d", &temp);
        array[i] = temp;
    }
    qsort(array, arrSize, sizeof(int), cmp);  // sort array (built-in function of stdlib which is necessary for malloc() anyways)
    for (int i = 0; i < arrSize; i++) {       // print every array element
        printf("%3d: %3d", (i + 1), array[i]);
    }
    free(array);  // free memory
    return 0;
}
