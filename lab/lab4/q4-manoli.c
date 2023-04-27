/*
	Author: Manoli
*/

#include <stdio.h>

#define BUFFER_SIZE 40

//		Globals		//
char B[BUFFER_SIZE];
char vowels[] = "aeiouAEIOU";

#define KNOWN_VOWELS 10

int main()
{
	// quiet down vowels
	char silent_vowel;

	scanf("%c %s", &silent_vowel, B);

	int i = -1; // outer loop index
	int v;		// inner loop index

	while (++i < BUFFER_SIZE)
	{ // escape if NULL or Line-Break
		if (B[i] == '\0' || B[i] == '\n')
		{ // get-oot
			break;
		}
		v = -1; // reset inner loop
		while (++v < KNOWN_VOWELS)
		{ // compare against each know vowel
			if (vowels[v] == B[i])
			{ // if match ==> replace
				B[i] = silent_vowel;
				// ==> spare CPU cycles!
				break; // only one match per buffer-character!
			}		   // fetch next vowel
		}			   // looped over vowels and found no match!
	}				   // get me the next char in the buffer! Or let out of here!

	// I need to see it to believe it!
	printf("%s\n", B);

	return 0;
}
