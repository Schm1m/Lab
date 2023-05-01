#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
char *append(char *buffer, char *app)
{
    int i = 0, k = 0;

    while (buffer[i] != '\0')
    {
        i++;
    }

    while (app[k] != '\0') // app gets attatched to buffer+space
    {
        buffer[i] = app[k];
        k++;
        i++;
    }

    buffer[i] = '\0'; // new exit character for buffer created

    return buffer;
}

int main(void)
{
    char buffer[40] = "Hallo ";
    append(buffer, "Welt");
    printf("%s\n", buffer);
}