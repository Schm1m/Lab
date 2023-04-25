// Sie schreiben nur die Funktion, keine Ausgabe!
#include <stdio.h>

int weekday(int d, int m, int y)
{
    d += m < 3 ? y-- : y - 2;
    
    return (23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}

int main()
{
    printf("%d", weekday(29, 04, 2021));
}
