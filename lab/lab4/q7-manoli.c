/*
	Author: Manoli
*/

#include <stdio.h>

#define length 40
char B[length];

int main()
{
	scanf("%s\n", B);
	int i = -1;

	// scout ahead
	while (++i < length)
	{
		if (!B[i]) // #NULL '\0' is 0
		{
			break;
		}
	}

	// loop backwards
	while (i--) // skip end
	{
		printf("%c", B[i]);
	}

	printf("\n");

	return 0;
}
