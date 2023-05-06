#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
int minimum(int *ptr, int length) // (int *ptr) = (int ptr[])
{
    int min = ptr[0];

    for (int i = 0; i < length; i++)
    {
        if (ptr[i] < min)
        {
            min = ptr[i]; //overrides the minimum if the next number is smaller
        }
    }
    return min;
}

int main (void)
{
    int numbers[] = {4, 6, 9, 5};
    printf("%d", minimum(numbers, 4));
}
