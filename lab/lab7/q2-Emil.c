#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
void toUpper(char *arr)
{
    int i = 0;

    while (arr[i] != '\0')
    {

        if (arr[i] >= 'a' && arr[i] <= 'z') // *see ASCII table 
        {

            arr[i] = arr[i] - 32;
        }
        i++;
    }
}

int main(void)
{
    char arr[] = "Hallo Welt";
    toUpper(arr);
    printf("%s\n", arr);
}