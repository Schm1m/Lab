// cody by tim, L2Q5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define DENSITY 0.8
int main(void)
{
    char gender[20];           // define variables // gender might be a bad variable naming, cause "child" is not a gender
    int massP, mlAlc, alcPerc; //
    float p, r;                //

    scanf("%c %d %d %d", &gender[0], &massP, &mlAlc, &alcPerc);                 // wait for inputs
    if (strcmp(gender, "m") == 0)                                               // define factor "r" if ->
    {                                                                           // the input gender is "male" ->
        r = 0.7;                                                                // "r" is 0.7
    }                                                                           //
    if (strcmp(gender, "w") == 0)                                               //
    {                                                                           // the input gender is "female" ->
        r = 0.6;                                                                // "r" is 0.6
    }                                                                           //
    if (strcmp(gender, "k") == 0)                                               //
    {                                                                           // the input gender is "child" ->
        r = 0.8;                                                                // "r" is 0.8
    }                                                                           //
    p = (float)((float)(mlAlc * alcPerc * DENSITY) / (float)(massP * r)) / 100; // calculate p with the given formula
    printf("%0.2f Promille\n", p);                                              // print p
    return 0;                                                                   // no error
}
