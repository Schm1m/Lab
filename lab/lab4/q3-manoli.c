/*
	Author: Manoli
*/

#include <stdio.h>

#define BUFFER_SIZE 40

#define KNOWN_VOWELS 10		  // Macros
char vowels[] = "aeiouAEIOU"; // Global
// KLEIN UND GROss

int main()
{

	char B[BUFFER_SIZE];

	int i, v; // loop indexers
	int count = 0;

	fgets(B, BUFFER_SIZE, stdin); // read into buffer

	// process input
	i = -1; // initialize outer-loop # over the buffer

	while (++i < BUFFER_SIZE)
	{ // NULL or Newline means that we are done
		if (B[i] == '\0' || B[i] == '\n')
		{
			break;
		}

		v = -1; // reset inner-loop index

		while (++v < KNOWN_VOWELS)
		{ // compare to all known vowels
			if (vowels[v] == B[i])
			{
				count++; // increment if you find one
				// there can be only one match
				break; // break inner loop
			}
			// otherwise just an empty loop
		}
	}
	// don't forget to show me
	printf("%d Vokale\n", count);

	return 0;
}
