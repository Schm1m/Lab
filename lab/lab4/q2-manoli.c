/*
	Author: Manoli
*/

#include <stdio.h>

#define BUFFER_SIZE 40

int main()
{
	char buffer[BUFFER_SIZE];

	scanf("%s", buffer);

	int i = -1;	   // loop counter
	int count = 0; // assume there is none

	while (++i < BUFFER_SIZE) // increment BEFORE comparing or entering the loop
	{
		// NULL or NewLine ==> get out of here
		if (buffer[i] == '\0' || buffer[i] == '\n')
		{
			break; // escapes the loop
		}
		// Ascii 'a' --> 97
		// Ascii 'z' --> 122
		// ==> range [97, 122]
		// lower bound `i > 97-1`
		// upper bound `i < 122+1`
		// both bound must be respected!
		if (buffer[i] > 96 && buffer[i] < 123)
		{ // increment count if within range
			count++;
		}
	}

	printf("%d Kleinbuchstaben\n", count);

	return 0;
}
