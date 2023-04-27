/*
	Author: Manoli
*/

#include <stdio.h>

#define length 10

int main()
{

	float array[length];

	int i = -1;

	while (++i < length) // start the loop with index 0
	{
		scanf("%f", array + i);

		if (array[i] < 1.0 || array[i] > 6.0)
		{ // out of range
			break;
		}
	}

	int count = i--; // skip the bad buffer
	// the last element will be used to sum the rest
	// count of 1 means i == 0 ==> no need to sum anything! array[count-1] is already the sum
	while (i > 0) // 0 > 0 is false!
	{
		// i points to the index of the last but we want the one before
		// (count-1) is index the last acceptable value!
		// which where the sum of the array+ will accumulate
		array[count - 1] += array[--i];
	}

	// #Ternary-Operator if (!0) ? True-Value : False-Value // x/0 -> NaN
	printf("Durchschnitt (N=%d): %.2f\n", count, (count) ? array[count - 1] / count : 0);

	return 0;
}
