// cody by tim, L3Q2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char star = '*';
    char line = '_';
    int num;                       // initialise variable
    scanf("%d", &num);             // wait for integer input
    for (int i = 1; i <= num; i++) // print:
    {
        if (i % 2 == 0)
        {
            putchar(line); // a '_' if i is even
        }
        else
        {
            putchar(star); // a '*' if i is odd
        }
    }

    return 0;
}