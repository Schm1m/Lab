// cody by tim, L4Q4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];  // define char array
    char x;
    scanf(" %c %s", &x, array);                 // get input
    for (int i = 0; i <= sizeof(array); i++) {  // replace every vocal character with x
        if (array[i] == '\0') break;
        if (array[i] == 'a' || array[i] == 'A' || array[i] == 'e' || array[i] == 'E' || array[i] == 'i' || array[i] == 'I' || array[i] == 'o' || array[i] == 'O' || array[i] == 'u' || array[i] == 'U') {  // only replace if char is an vocal
            array[i] = x;
        }
    }
    printf("%s\n", array);
    return 0;
}
