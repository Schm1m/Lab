#include <stdio.h>

int fibiter(int iteration)
{
    int num1 = 0, num2 = 1, out;

    for (int i = 2; i <= iteration; i++) // iterative calc
    {
        out = num1 + num2;
        num1 = num2;
        num2 = out;
    }

    return out;
}

int main(int argc, char *argv[])
{
    int input;

    do
    {
        scanf("%d", &input); // scans until a valid input is found
    } while (input < 2);

    printf("%d", fibiter(input));

    return 0;
}
