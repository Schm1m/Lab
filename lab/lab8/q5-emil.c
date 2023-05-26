#include <stdio.h>

float series(float a, float x, int n)
{
    if (n == 1)
    {
        return (a + 2 * n * x); // starting index 1
    }
    else
    {
        return ((a + 2 * n * x) + series(a, x, n - 1)); // recursively calculates the series
    }
}

int main(void)
{
    float a, x;
    int n;

    scanf("%f %f %i", &a, &x, &n);
    printf("%.1f", series(a, x, n));

    return 0;
}