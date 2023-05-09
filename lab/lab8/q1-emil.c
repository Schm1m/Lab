#include <stdio.h>

int potenz_iter(int a, int b, int n)
{
    int out = 1;

    for (int i=0; i < n; i++) // iteratively calculate the pot
    {
        out = out*(a+b); 
    }

    return out;
}

int main(void)
{
    int a, b, n, pot;

    scanf("%i %i %i", &a, &b, &n);

    pot = potenz_iter(a, b, n);
    printf("%i", pot);

    return 0;
}
