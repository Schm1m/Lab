// cody by tim, L1Q5
#include <stdio.h>

int main(void)
{
    int i, a, b, c;                                // define variables
    scanf("%d %d %d", &a, &b, &c);                 // wait for inputs
    int array[3] = {a, b, c};                      // put inputs into an array
    for (i = 3; i > 0; i--)                        // iterate through all part of array
    {                                              //
        printf("Zahl %d: %3d\n", i, array[i - 1]); // print the arrays contents in reverse order
    }                                              //
    return 0;                                      // no error
}