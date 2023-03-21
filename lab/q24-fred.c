#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    // initialize the variables
    double weight;
    double height;
    double bmi;

    // scanning for the two values
    scanf("%lf", &weight);
    scanf("%lf", &height);

    // conversion
    weight = weight * 0.001;
    height = height * 0.01;

    // calculation of the bmi value
    bmi = weight / (height * height);

    // condition and print
    if (bmi <= 18.4) {
        printf("Untergewicht %.1f", bmi);
    } else if (18.4 < bmi && bmi < 24.9) {
        printf("Normalgewicht %.1f", bmi);
    } else if (bmi >= 24.9) {
        printf("Uebergewicht %.1f", bmi);
    }

    return 0;

}
