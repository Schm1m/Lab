// cody by tim, L4Q8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int x;      // temp variable to get next input
    int y = 0;  // number of grades in array
    float sum = 0;
    int grades[10];                 // array of grades
    for (int i = 0; i < 10; i++) {  // get a maximum of 10 grades
        scanf("%d", &x);
        if (x < 1 || x > 6) break;  // if the input is outside of {1 < x < 6} stop taking inputs
        grades[i] = x;              //
        y++;                        // count up number of grades
    }
    if (y == 0) {  // return standart output if no valid grades were submitted
        printf("Durchschnitt (N=0): 0.00");
        return 0;
    }
    for (int i = 0; i < y; i++) {  // add all grades together
        sum += grades[i];
    }
    // debug
    // printf("num grades: %d\n", y);
    printf("Durchschnitt (N=%d): %0.2f\n", y, sum / y);
}
