/*
	Author: Manoli
*/

#include <stdio.h>

// Globals
char S = ' ';
char Z = '*';

void starts(int loop)
{
	while (loop--)
	{
		putchar(Z);
	}
	putchar('\n');
}

void draw_line(int padding, int middle)
{
	// Form: "padding*middle*padding"
	// middle < 0 ==> 1 star

	putchar(Z); // starting star

	int loop;

	// before part
	loop = padding;

	while (loop--)
	{
		putchar(S);
	}

	putchar(Z);

	while (middle > 0)
	{
		putchar(S);

		middle--;
	}

	if (middle > -1)
	{				// no need for another star
		putchar(Z); // overlap
	}

	// after part
	loop = padding;
	while (loop--)
	{
		putchar(S);
	}

	printf("%c\n", Z); // ending star
}

void xXx(int size)
{
	/*
		We can see the two stars moving towards each other at the start
		Then they drift apart to their starting positions.

		Regardless, any line can be displayed using this form:

			padding*middle*padding

		Drawing each line will:
			- increment the padding
			- decremented the middle part

		Until the padding fill the entire width

		Then the:
			- The padding must be decrement
			- While incrementing the middle

		Back to the starting postion!
	*/

	if (size < 2)
	{
		return;
	}

	size -= 2;

	int loop, index;

	loop = size / 2;

	index = 0;

	while (loop--)
	{ // where the starts are getting closer to each other
		draw_line(index, size - 2 * index - 2);
		index++; // decrement loop while incrementing index
	}

	if (size & 1)
	{ // cross over part if size is odd!
		// middle star
		// (size - 2 * index - 2) < 0 !
		draw_line(index, size - 2 * index - 2);
	}

	while (index--)
	{ // where the starts are moving away from each other
		draw_line(index, size - 2 * index - 2);
	}
}

void draw(int lines)
{
	if (lines < 3)
	{
		starts(lines);
		return;
	}

	starts(lines); // top

	xXx(lines); // middle part

	starts(lines); // bottom
}

int main(int argc, char *argv[])
{

	int D;

	scanf("%d", &D);

	draw(D);

	return 0;
}
