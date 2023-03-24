//cody by tim, L2Q4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int k, g;                   // define variables
    float b;                    //
    scanf("%d %d", &k, &g);     // wait for inputs
    float kg = (float)k / 1000; // convert data to fit formula
    float gm = (float)g / 100;  //
    b = kg / (gm * gm);         // calculate bmi
    if (b <= 18.4)              // run if bmi is smaller or equal to 18.4
    {
        char txt[20] = "Untergewicht"; // set evaluation
        printf("%s %0.1f\n", txt, b);  // print bmi + evaluation
    }
    else if (b >= 24.9) // run if bmi is greater or equal to 24.9
    {
        char txt[20] = "Uebergewicht"; // set evaluation
        printf("%s %0.1f\n", txt, b);  // print bmi + evaluation
    }
    else // run if bmi is between 18.4 and 24.9
    {
        char txt[20] = "Normalgewicht"; // set evaluation
        printf("%s %0.1f\n", txt, b);   // print bmi + evaluation
    }

    return 0; // no error
}
