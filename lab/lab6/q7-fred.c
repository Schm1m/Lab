#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>


double triangleArea(double base, double height) {

    /*
     * used 1.0 insted of 1 to avoid the loss
     * of precision...
     */
    return 1.0 / 2.0 * base * height;

}

int main(void) {

    printf("%.2f", triangleArea(3, 4));

}