// cody by tim, L2Q1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int i1, i2, i3;                                    // define variables
    scanf("%d %d %d", &i1, &i2, &i3);                  // wait for inputs
    printf("Ganze Zahlen: %d, %d, %d \n", i1, i2, i3); // print formated inputs

    float f;                                                // define variable
    scanf("%f", &f);                                        // wait for input
    printf("Fliesskommazahl mit Formatangabe: %.2f \n", f); // print formated input

    char s[100];                      // define variable
    scanf("%s", &s[0]);               // wait for input
    printf("Zeichenkette: %s \n", s); // print formated input

    return 0; // no error
}
