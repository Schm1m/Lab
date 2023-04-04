// cody by tim, L3Q7

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("Fahrenheit\tCelsius\n");         // wirte first line
    for (int i = -20; i <= 300; i += 20)     // do it for i in [-20, 300]
    {                                        //
        float c = (float)(5 * (i - 32)) / 9; // calculate celsius equivalent
        printf("%10d\t%7.2f\n", i, c);       // print fahrenheit and celsius as numbers
    }
    return 0;
}