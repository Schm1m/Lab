// cody by tim, L3Q1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int num;                      // initialise variable
    scanf("%d", &num);            // wait for integer input
    for (int i = 0; i < num; i++) // print as many "*" as defined by the input
    {
        printf("*");
    }

    return 0;
}