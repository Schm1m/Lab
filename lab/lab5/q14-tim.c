// cody by tim, L5Q14

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int array[4];              // define array
    int *pointer = &array[2];  // define pointer to index 2 of array
    for (int i = 0; i < 4; i++) {
        scanf("%d", &array[i]);  // read inputs into the array
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);  // return the array
    }
    printf("\n");
    *pointer = 42;  // set the value the pointer is pointing to to 42

    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);  // return the array
    }
    printf("\n");
    return 0;
}
