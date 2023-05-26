#include <stdio.h>

void input(int *in) // overwrites the value of the adress of n
{
    scanf("%i", in);
}

int faculty(int n)
{
    if (n == 0) // 0! = 1
    {
        return 1;
    }
    else if (n == 1) // 1! = 1
    {
        return 1;
    }
    else
    {
        return (n * faculty(n - 1)); // recursive calculation of the factorial
    }
}

int main(void)
{
    int n;
    input(&n);
    printf("%i! = %i", n, faculty(n));
    return 0;
}