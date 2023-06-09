// cody by tim, L3Q4

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char star = '*';
    char space = ' ';
    int h, l;                    // initialise variables (height and lenght)
    scanf("%d %d", &h, &l);      // wait for integer inputs
    for (int i = 1; i <= h; i++) // make h rows
    {
        if (i == 1 || i == h)
        {
            // full lines
            for (int j = 1; j <= l; j++) // make a line of '*'s
            {
                putchar(star);
            }
        }
        else
        {
            // empty lines
            for (int j = 1; j <= l; j++)
            {
                if (j == 1 || j == l) // set a '*' at the beginning and the end of the line
                {
                    putchar(star);
                }
                else
                {
                    putchar(space);
                }
            }
        }
        printf("\n");
    }

    return 0;
}