#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
char *ownStrcpy(char *copiedString, char *originalString)
{
    int i = 0;

    while (originalString[i] != '\0')
    {
        copiedString[i] = originalString[i];
        i++;
    }
    
    copiedString[i] = '\0';

    return copiedString;
}

int main(void)
{
    char originalString[] = "Programmieren";
    char copiedString[40];
    ownStrcpy(copiedString, originalString);
    printf("%s", copiedString);
}