/*
	Author: Manoli
*/

#include <stdio.h>

void print(int array[], int loop)
{
	printf("%d", *(array + --loop)); // first word with a space padding

	while (loop--) // bad idea! shouldn't trust the user!
	{			   // add padding before writing to the line
		printf(" %d", *(array + loop));
	}
	printf("\n"); // break line
}

void fetch_input(int array[], int loop)
{
	while (loop--) // just a count-down
	{
		// why not right to left
		scanf("%d", array + loop); // all good. We've already decremented!
	}
}

#define length 4

int main(int argc, char *argv[])
{

	int array[length];

	fetch_input(array, length); // populate form the end

	print(array, length);

	// modify the element with the index

	// I am index backwards!!	// #Unfug
	*(array + (length - 3)) = 42;
	// index 2 --> third element
	// ==> backward_index = index+1 --> Also 2+1 = 3
	// ==> access_index = length - backward_index --> Also 4 - 3 = 1

	print(array, length);

	return 0;
}
