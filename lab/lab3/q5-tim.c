// cody by tim, L3Q5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char plus = '+';
    char minus = '-';
    int x, y;                    // initialise variable
    scanf("%d %d", &x, &y);      // wait for integer input
    for (int i = 1; i <= x; i++) // print x rows
    {
        {
            if (i % 2 == 0) // if i is even, start with an '-'
            {
                for (int j = 1; j <= y; j++)
                {
                    if (j % 2 == 0)
                    {
                        putchar(plus);
                    }
                    else
                    {
                        putchar(minus);
                    }
                }
            }
            else // else start with an '+'
            {
                for (int j = 1; j <= y; j++)
                {
                    if (j % 2 == 0)
                    {
                        putchar(minus);
                    }
                    else
                    {
                        putchar(plus);
                    }
                }
            }
        }
        printf("\n");
    }
}