// cody by tim, L4Q6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    char array[40];  // define char array
    char cutted[40];
    int x, y;
    scanf("%s %d %d", array, &x, &y);  // get input
    for (int i = x; i <= y; i++) {     // put the selected chars in a new char array
        cutted[i - x] = array[i];
    }
    printf("%s %d-%d: %s\n", array, x, y, cutted);
    return 0;
}
