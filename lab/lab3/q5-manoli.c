/*
	Author: Manoli
*/

#include <stdio.h>

// globals
char C[] = "+-";

void line(int width, int i)
{ // i is the starting index
	while (width--)
	{
		putchar(C[(i++) & 1]); // either even or odd!
	}
	putchar('\n');
}

int main(int argc, char *argv[])
{

	int lines, width;

	scanf("%d %d", &lines, &width);

	int index = 0;

	while (lines--)
	{ // ==> oscillates between being even, odd
		line(width, index++);
	}
	return 0;
}
