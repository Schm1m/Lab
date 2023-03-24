#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {

    float temp_f;
    scanf("%f", &temp_f);

    float temp_c;
    temp_c = (5 * (temp_f - 32))/9;

    printf("%.1f Grad Fahrenheit = %.1f Grad Celsius", temp_f, temp_c);

    return 0;

}

