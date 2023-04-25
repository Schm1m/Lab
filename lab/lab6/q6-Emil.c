// Sie schreiben nur die Funktion, keine Ausgabe!
int stringlength(char str[])
{
    int i = 0, count = 0;

    while (str[i] != '\0') // checks for the exit character
    {
        i++;
        count++; // counter raised for every entry of the string which is not the exit character
    }

    return count; // returns integer
}