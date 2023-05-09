/*
	Author: Manoli
*/

#include <stdio.h>

int minimum(int numbers[], int n)
{
	int i = 0; // assume minimum is at index 0
	// count-down loop
	while (--n)
	{ // range [n-1, 1]
		if (numbers[n] < numbers[i])
		{ // compare with current min
			i = n;
		}
	}
	return numbers[i];
}

int main()
{
	int arr[] = {1, 2, 3, -17, 0, 32};

	int len = sizeof(arr) / sizeof(int);

	printf("%d\n", minimum(arr, len));

	return 0;
}
