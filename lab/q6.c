// cody by tim, L1Q6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int a;                                                                                    // define variables
    float b;                                                                                  //
    char c;                                                                                   //
    char d = ':';                                                                             //
    scanf("%d %f %c", &a, &b, &c);                                                            // wait for inputs
    printf("Ganzzahlen%5c %010d\nGleitkommazahl%c %0.5f\nZeichen%8c %c\n", d, a, d, b, d, c); // print formated outputs
    return 0;                                                                                 // no error
}
