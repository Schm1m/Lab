/*
	Author: Manoli
*/

#include <stdio.h>

#define length 4

int main(int argc, char *argv[])
{

	// length will be replaced with 4 by the compiler
	double array[length]; // #preprocessing #Macros

	int index; // loop counter

	index = -1; // will be incremented to 0 before starting the loop

	while (++index < length)		 // increment before even comparing
	{								 // double == long float
		scanf("%lf", array + index); // `array + i` means `&array[i]`
	}

	int min_index = 0;
	// assume that's min is the first one unless otherwise

	index = 0; // resets the loop

	while (++index < length) // start comparing with the index after 0 ;)
	{
		// is it smaller the current record holder
		if (array[index] < array[min_index])
		{
			// new min found
			min_index = index; // update min_index
		}
	}

	printf("Kleinste Zahl: %.1lf an Index %d\n", array[min_index], min_index);

	return 0;
}
