#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    // THREE INTS FOR SAVING THE INPUT
    int x;
    int y;
    int z;

    // printf("Enter three integers:\n"); // COMMENTED FOR PRETTY OUTPUT (MOODLE)
    scanf("%d%d%d", &x,&y,&z);
    // printf("The input is:\n%d\n%d\n%d", x,y,z); // THIS LINE IS FOR DEBUGGING

    // PRINTING THE RIGHT ORDER, NOT SWITCHING THE POINTER, JUST A DIFF QUEUE
    printf("Zahl 3: %4d\nZahl 2: %4d\nZahl 1: %4d\n", z,y,x);

    return 0;

}
