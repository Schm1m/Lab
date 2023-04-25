// Sie schreiben nur die Funktion, keine Ausgabe!
int prime(int x)
{
    for (int i = 2; i * i <= x; i++) // loop checks for the rest of the division of x and every number leading up to its sqrt
    {
        if (x % i == 0)
        {
            return 0; // returns 0 if the number is divisible with no rest
        }
    }
    
    if (x == 1)
    {
        return 0; // special case
    }

    return 1; // returns 1 if the number is a prime
}