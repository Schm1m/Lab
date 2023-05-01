#include <stdio.h>

// Sie schreiben nur die Funktion, keine Ausgabe!
void sphere(int r, double *V, double *A)
{
    #define PI 3.1415

    *V = (4 * PI * r * r * r) / 3;
    *A = 4 * PI * r * r;
}

int main(void)
{
    int radius = 5;
    double volume, surface;
    sphere(radius, &volume, &surface);
    printf("Radius: %d\nVolumen: %.1lf\nOberflaeche %.1lf\n", radius, volume, surface);
}