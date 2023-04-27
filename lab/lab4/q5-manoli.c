/*
	Author: Manoli
*/

#include <stdio.h>

/****** Macros ******/

#define BUFFER_SIZE 40

char B[BUFFER_SIZE];

/***** &Globals *****/

// ############## //
// ## Strategy ## //
// ############## //

// Ascii 'A' --> 65
// Ascii 'Z' --> 90
// Upper-Case range [65, 90], (64, 91) #Math-Intervals

// Ascii 'a' --> 97
// Ascii 'z' --> 122
// Lower-Case range [97, 122], (96, 123)

// anything smaller than 65 or bigger than 122 is surly not alpha

// In the Ascii-Table
// ('a' - 'A') == ('m' - 'M') == ('z' - 'Z') == (122 - 90) => 32
// lower +32 ==> Upper
// Upper -32 ==> Lower

int main()
{
	scanf("%s", B);

	int i = -1; // loop index

	while (++i < BUFFER_SIZE)
	{
		if (B[i] == '\0' || B[i] == '\n')
		{ // escape loop if NULL or Line-Break
			break;
		}

		if (B[i] < 65 || B[i] > 122)
		{ // noting 2 shift
			continue;
			// out of alpha *possible range [65, 122] #donut-shape-range!
			// skip this loop to start the next
		}

		if (B[i] < 91)
		{				// Upper-Case-Range END = 90] or 91)
						// <= 65 is assured otherwise we wouldn't have got this far
			B[i] += 32; // shift2lower #Linksverschiebung
			continue;	// 1 match per char --> nothing to do in this loop run
		}

		// ignore anything in between

		if (B[i] > 96)
		{				// Lower-Case-Range START = [97 or (96
			B[i] -= 32; // shift2UPPER #Rechtsverschiebung
		}

	} // fetch the next one

	printf("%s\n", B);

	return 0;
}
