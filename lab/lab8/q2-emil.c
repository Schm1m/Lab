#include <stdio.h>

int potenz_rekursive(int a, int b, int n)
{
    int out;

    if (n == 0) // special case for n=0
    {
        return 1;
    }
    else if (n == 1)
    {
        return (a + b); // starting index for n
    }
    else
    {
        out = (a + b) * potenz_rekursive(a, b, n - 1); // iterative calc
        return out;
    }
}

int main(void)
{
    int a, b, n, pot;

    scanf("%i %i %i", &a, &b, &n);

    pot = potenz_rekursive(a, b, n);
    printf("%i", pot);

    return 0;
}
