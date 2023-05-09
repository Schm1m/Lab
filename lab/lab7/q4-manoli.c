/*
	Author: Manoli
*/

#include <stdio.h>

void ownStrcpy(char copiedString[], char originalString[])
{ // from q3
	// shifts the pointer to the left to start the loop by incrementing first!
	originalString--; // should be okay no dereferencing!
	while (*++originalString)
	{ // originalString should be Null terminated!
		// increment then test but keep the same value you tested for
		*copiedString++ = *originalString; // fetch address, assign value and the increment
	}
	*copiedString = '\0'; // add null termination
}

void append(char originalString[], char appendString[])
{ // find null termination
	while (*originalString++); // index of '\0'
	// copy appended string to the original string
	// over write '\0' from the originalString
	ownStrcpy(originalString - 1, appendString);
}

int main()
{
	char buffer[40] = "Hallo ";

	append(buffer, "Welt");

	printf("%s\n", buffer);

	return 0;
}
