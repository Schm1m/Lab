// cody by tim, L3Q9

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x;                       // initialize variable
    scanf("%d", &x);             // wait for input
    for (int i = 1; i <= x; i++) // create x rows
    {
        if (i == 1 || i == x)            // for the first and last row
        {                                //
            for (int j = 1; j <= x; j++) // fill with "*"s
            {
                printf("*");
            }
        }
        else // for every other row
        {
            for (int j = 1; j <= x; j++)
            {
                if (j == 1 || j == x) // set the first an last character as a "*"
                {
                    printf("*");
                }
                else if (j == i || j == (x - (i - 1))) // set the character a "*" if i and j are the samee and mirrored
                {
                    printf("*");
                }
                else // set every other character as a " "
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
