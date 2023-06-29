#include <stdio.h>
#include <string.h>

int main()
{
	int v1, v2;
	char feld[] = "4321";
	// terminating char '\0' will be added to the allocated cha array by the compiler
	v1 = sizeof feld;	 // the size of the allocated array = 4 * chars + '\0' = 5
	v1 = strlen(feld); // just 4 * chars 4 .. 1. Will overwrite the value of v1

	printf("v1: %d\n", v1); // will be 4 because it got reassigned
	printf("v2: %d\n", v2); // will stay at its initial value. Never got assigned!

	return 0;
}
