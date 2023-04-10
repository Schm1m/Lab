// cody by tim, L4Q2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];  // define char array
    int x = 0;
    fgets(array, 40, stdin);                    // get char array (fgets is part of stdio.h)
    for (int i = 0; i <= sizeof(array); i++) {  // count up x for every non-null character
        if (array[i] == '\0') break;
        if (array[i] >= 'a' && array[i] <= 'z') {  // only count up x if the element is a lowercase member of the alphabet
            x++;
        }
    }
    printf("%d Kleinbuchstaben\n", x);
    return 0;
}
