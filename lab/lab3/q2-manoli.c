/*
	Author: Manoli
*/

#include <stdio.h>

int main(int argc, char *argv[])
{

	char C[] = "*_";

	int loop;

	scanf("%d", &loop);

	int index = 0; // oscillator's starting value!

	while (loop--)
	{
		putchar(C[index]);

		index = 1 - index; // alternates between 1 and 0
	}

	putchar('\n');

	return 0;
}
