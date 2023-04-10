// cody by tim, L4Q5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];                             // define char array
    scanf("%s", array);                         // get input
    for (int i = 0; i <= sizeof(array); i++) {  // replace every lower-case character with an uper-case one an vice-versa
        if (array[i] >= 'a' && array[i] <= 'z') {
            // printf("%c\n", a - 32);
            array[i] -= 32;
        } else if (array[i] >= 'A' && array[i] <= 'Z') {
            // printf("%c\n", a + 32);
            array[i] += 32;
        }
    }
    printf("%s\n", array);
    return 0;
}
