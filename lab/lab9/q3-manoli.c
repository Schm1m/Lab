/*
	Author: Manoli
*/

#include <stdio.h>
#include <stdlib.h>

// Globals
int *Array;
int length;

// Start reading from the bottom like a computer would!

void cleanup()
{
	free(Array);
	Array = NULL; // Discard invalid reference
}

void display()
{
	int i = 0;

	while (i++ < length)
	{
		printf("%3d: %3d", i, Array[i - 1]);
	}
	putchar('\n');
}

int notSorted() // checks if the Array is sorted in ascending order or not
{
	int i = length; // will be decremented before access

	while (--i) // stops at 0 ==> last index allowed is 1
	{
		if (Array[i - 1] > Array[i]) // (a[k-1]  <= a[k]) negated
		{
			return 1; // when such case is found ==> not sorted
		}
	}
	return 0; // sorted
}

void sort() // access the global Array variable to sort it
{
	// sort in ascending order ==> from smallest 2 biggest

	/*
		Bubble Sort Algorithm:
		- Compare two neighboring elements in the list
			- if not in the right order swap them
		- Keep doing that until the list is sorted
	*/

	int i; // LaufVariable

	while (notSorted()) // Swap
	{
		i = length; // reset inner loop
		while (--i)
		{
			if (Array[i - 1] > Array[i])
			{
				Array[i - 1] ^= Array[i]; // bitwise xor swap
				Array[i] ^= Array[i - 1];
				Array[i - 1] ^= Array[i];
			}
		}
	}
}

void fetch_numbers()
{
	int loop = length;
	int *p = Array;

	while (loop--) // count down loop
	{
		scanf("%d", p++); // assign and then scoot over
	}
}

void setup()
{
	scanf("%d", &length);
	Array = malloc(length * sizeof(int));
	if (Array == NULL)
	{
		printf("\n\tMEMORY DENIED!\n\n");
		exit(-1);
	}
	fetch_numbers();
}

// START HERE

int main(int argc, char *argv[])
{
	setup();

	sort();

	display();

	cleanup();

	return 0;
}
