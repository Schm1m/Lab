// cody by tim, L4Q7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];                             // define char array
    scanf("%s", array);                         // get input
    for (int i = sizeof(array); i >= 0; i--) {  // return char-array in reverse order
        if (array[i] != '\0') {                 // do not return nul-characters
            putchar(array[i]);
        }
    }
    printf("\n");
    return 0;
}
