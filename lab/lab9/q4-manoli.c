/*
	Author: Manoli
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct numberItem
{
	int value;
	// only time writing `struct numberItem` is required
	struct numberItem *Next;
} numberItem; // alias for `struct numberItem`

void appendNumberItem(numberItem **R, int value)
{
	// create new node
	numberItem *N = malloc(sizeof(numberItem));

	// initialize values
	N->value = value;
	N->Next = NULL;

	// seek the end of the list

	if (*R == NULL)
	{ // the list is empty!
		*R = N;
		return; // IMPORTANT!
	}

	numberItem *LV = *R;

	while (LV->Next) // find the element pointing into the void
	{
		LV = LV->Next; // loop by climbing down the node tree from the current node to the next
	}

	LV->Next = N; // attach the node to the last branch
}

void printList(numberItem *R)
{
	while (R) // NULL has the numerical value of 0
	{
		printf("%d\n", R->value);
		R = R->Next; // seek next element
	}
}

void clearList(numberItem *R)
{
	// Laufvariable
	numberItem *LV; // place holder until R is freed
	while (R)
	{
		LV = R->Next;
		free(R);
		R = LV;
	}
}
