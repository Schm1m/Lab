#include <stdio.h>
#include <string.h>

const char SHIFT = 'a' - 'A'; // The same difference lower-upper

void uppercase(char S[])
{
	while (*S != '\0') // stop printing at '\0'
	{ // not within range [a, z] -> pass through
		putchar((*S < 'a' || *S > 'z') ? *S : *S - SHIFT);
		S++; // seek next char
	}
}

int main()
{
	char S[] = "Hello World";

	printf("String:\t%s\n", S);
	printf("UpperCase:\t");
	uppercase(S);
	putchar('\n');

	return 0;
}
