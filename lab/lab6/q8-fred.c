#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>


double bmi(double mass, double height) {

    height = height / 100;
    double result = mass / (height * height);

    return result;

}

int main(void) {

    printf("%dkg und %fm = %.2lf", 85, 1.5, bmi(85, 150));

}