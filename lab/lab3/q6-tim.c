// cody by tim, L3Q6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("Celsius\tFahrenheit\n");     // wirte first line
    for (int i = -20; i <= 300; i += 20) // do it for i in [-20, 300]
    {                                    //
        int f = ((i * 9) / (5)) + 32;    // calculate fahrenheit equivalent
        printf("%7d\t%10d\n", i, f);     // print celsius and fahrenheit as numbers
    }
    return 0;
}