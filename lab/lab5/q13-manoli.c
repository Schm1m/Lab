/*
	Author: Manoli
*/

#include <stdio.h>

#define length 4

int main(int argc, char *argv[])
{

	int array[length];

	int loop; // just a count-down

	loop = length;

	while (loop--)
	{
		// why not right to left
		scanf("%d", array + loop); // all good. We've already decremented!
	}

	loop = length - 1; // reset the loop

	int *sum = array + loop; // index the "end" of the array

	while (loop--) // skipping "last" one
	{
		*sum += *(array + loop); // add every thing to the "last" element
	}

	printf("Summe: %d\n", *sum);

	// casting the Denominator should also cast the Numerator
	printf("Durchschnitt: %.6f\n", *sum / (float)length); // #Hopefully

	return 0;
}
