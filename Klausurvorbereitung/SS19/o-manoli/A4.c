#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// iterative Lösung
void reverse_i(char input[]){

	int n = strlen(input); // when n = 0 loop won't run

	char *b = input + n - 1;

	while (n--)   putchar(*b--);
}

// rekursive Lösung
void reverse_r(char input[])
{
	if (*input == '\0')  return;

	reverse_r(input+1);

	putchar(*input);
}

int main (int argc, char *arg[]){

	if (argc < 2) // first argument is the executable path
	{
		printf("\n\tA COMMAND LINE ARGUMENT is REQUIRED\n\n");
		// in case there wasn't user input
		exit(1); // from stdlib.h
	}

	char *input = arg[1];

	printf("%s\n", input);

	reverse_i(input);
	putchar('\n');

	reverse_r(input);
	putchar('\n');

	return 0;
}

