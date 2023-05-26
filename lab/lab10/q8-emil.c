#include <stdio.h>

int fibrec(int n)
{
    switch (n)
    {
    case 0:
        return 0; // f(0) = 0

    case 1:
        return 1; // f(1) = 1

    default:
        return (fibrec(n - 1) + fibrec(n - 2)); // recursive calc
    }
}

int main(int argc, char *argv[])
{
    int input;

    do
    {
        scanf("%d", &input); // scans until a vild input is given
    } while (input < 2);

    printf("%d", fibrec(input));

    return 0;
}