// cody by tim, L3Q3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int h, l;                    // initialise variables (height and lenght)
    scanf("%d %d", &h, &l);      // wait for integer inputs
    for (int i = 1; i <= h; i++) // make h rows
    {
        for (int j = 1; j <= l; j++) // with l "*"s
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}