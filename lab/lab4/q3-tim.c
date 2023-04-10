// cody by tim, L4Q3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];  // define char array
    int x = 0;
    fgets(array, 40, stdin);                    // get char array (fgets is part of stdio.h)
    for (int i = 0; i <= sizeof(array); i++) {  // count up x for every vocal character
        if (array[i] == '\0') break;
        if (array[i] == 'a' || array[i] == 'A' || array[i] == 'e' || array[i] == 'E' || array[i] == 'i' || array[i] == 'I' || array[i] == 'o' || array[i] == 'O' || array[i] == 'u' || array[i] == 'U') {  // only count up x if the element is a lowercase member of the alphabet
            x++;
        }
    }
    printf("%d Vokale\n", x);
    return 0;
}
