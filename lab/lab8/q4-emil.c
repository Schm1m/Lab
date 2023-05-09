#include <stdio.h>

float series(float a, float x, int n)
{
    float y;

    for (int i = 1; i <= n; i++)
    {
        y = y + (a + 2 * i * x); // iteratively calculates y up to n
    }

    return y;
}

int main(void)
{
    float a, x;
    int n;

    scanf("%f %f %i", &a, &x, &n);
    printf("%.1f", series(a, x, n));

    return 0;
}