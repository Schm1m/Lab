/*
	Author: Manoli
*/

#include <stdio.h>

void ownStrcpy(char copiedString[], char originalString[])
{
	// shifts the pointer to the left to start the loop by incrementing first!
	originalString--; // should be okay no dereferencing!
	while (*++originalString)
	{ // originalString should be Null terminated!
		// increment then test but keep the same value you tested for
		*copiedString++ = *originalString; // fetch address, assign value and the increment
	}
	*copiedString = '\0'; // add null termination
}

int main()
{
	char originalString[] = "Programmieren";

	char copiedString[40];

	ownStrcpy(copiedString, originalString);

	printf("%s\n", copiedString);

	return 0;
}
