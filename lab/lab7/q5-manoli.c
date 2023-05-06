/*
	Author: Manoli
*/

#include <stdio.h>

#define PI 3.1415

void sphere(int radius, double *volume, double *surface)
{
	*surface = (double)4 * PI * radius * radius;
	*volume = *surface * radius / 3;
}

int main()
{
	int radius = 5;

	double volume, surface;

	sphere(radius, &volume, &surface);

	printf("Radius: %d\nVolumen: %.1lf\nOberflaeche %.1lf\n", radius, volume, surface);

	return 0;
}
