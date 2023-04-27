/*
	Author: Manoli
*/

#include <stdio.h>

char Z = '*';
char S = ' ';

/*
	A "Window" can be broken into three parts:
		- Top
		- Bottom
		- And what's in between
*/

void starts(int loop) // Top and Bottom
{
	while (loop--)
	{
		putchar(Z);
	}
	putchar('\n');
}

void middle_part(int loop)
{
	loop -= 2; // - (start + end)

	// stars wrapping a middle part

	putchar(Z); // start

	while (loop--) // just repeat until you hit zero
	{
		putchar(S);
	}
	printf("*\n"); // end
}

void draw(int lines, int s)
{
	if (lines < 3) // safe guard!
	{
		starts(s); // line line of stars and exit!
		return;
	}

	lines -= 2; // - (top + bottom)

	starts(s); // top

	while (lines--) // just a count down -2-> 0
	{				// keep drawing empty a line surrounded by stars
		middle_part(s);
	}
	starts(s); // bottom
}

int main(int argc, char *argv[])
{

	int lines, s;

	scanf("%d %d", &lines, &s);

	draw(lines, s);

	return 0;
}
