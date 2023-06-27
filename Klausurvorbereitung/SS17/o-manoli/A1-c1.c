#include <stdio.h>

int main()
{
// enumeration means numbering items of a list
// ==> each keyword will have a numerical value
// The compiler will replace each keyword with its numerical value and treat it as `const int`
// by default enum start count at 0
// N-Vals:		0,		1,		2,			3,		4
	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;	// new variable of type enum

// for loop is composed of:
//		initializing command; loop condition evaluation; loop index increment/decrement

// this loop will initialize the `LaufVariable` with the value of  blume = rot <=> 0
// the loop will continue to run until the condition `blume <= gelb` where gelb <=> 3.
// loop interval of [0, 3], [0, 4)
// at the end of each loop run the value of `blume` will be incremented by 1
// incrementing the enum variable will shifts the label to corresponding numerical value
	for (blume = rot; blume <= gelb; blume++)
	{
		if (blume == rot) printf("Farbe rot\n");		// will run with first loop run

		else if (blume == blau) printf("Farbe blau\n");		// will run with second loop run

		else printf("andere Farbe\n");	// will run twice with the third and fourth loop run
	}
	return 0;
}
