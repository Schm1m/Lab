// cody by tim, L2Q3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int k, g;                                 // define variables
    float b;                                  //
    scanf("%d %d", &k, &g);                   // wait for inputs
    float kg = (float)k / 1000;               // convert data to fit the given formula
    float gm = (float)g / 100;                //
    b = kg / (gm * gm);                       // calculate bmi with given formula
    printf("Der BMI liegt bei: %0.2f!\n", b); // print bmi
    return 0;                                 // no error
}
