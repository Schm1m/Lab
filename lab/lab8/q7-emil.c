#include <stdio.h>

int isPrime(int num, int i)
{
    if (num % i == 0 && num != i) // num divisible by i => not a prime
    {
        return 0;
    }
    else if (num == 0 || num == 1) // special cases for 0 and 1
    {
        return 0;
    }
    return i * i < num ? isPrime(num, i + 1) : 1; // process is repeated until num is divisible or i reaches the sqrt of num
}

int main(void)
{
    int num;

    scanf("%i", &num);
    printf("%i", isPrime(num, 2)); // i starts at 2 as to not divide by 0 or

    return 0;
}