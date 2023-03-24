// cody by tim, L2Q2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    float c, f;                                                   // define variable
    scanf("%f", &f);                                              // wait for input
    c = (5 * (f - 32)) / 9;                                       // calculate degrees celsius with given formula
    printf("%0.1f Grad Fahrenheit = %0.1f Grad Celsius\n", f, c); // print temteratures
    return 0;                                                     // no error
}
