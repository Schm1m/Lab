/*
	Author: Manoli
*/

#include <stdio.h>

// range 200] <==> 201)
#define loop 201

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	int i = 0;

	int a, b; // a, b are the rest of the division by m, n

	while (++i < loop)
	{
		// Either a word will be printed xor a number

		// when (x := k*m)%m -> 0 ==> x is divisible by m
		a = i % m; // cache the values
		b = i % n;

		// first-case print a number
		// not divisible by m nor n
		if (a && b) // <==> a > 0 && b > 0
		{
			printf("%d\n", i);
			continue; // skip the rest and start a new loop
		}

		if (!a) // a == 0 ==> divisible by m
		{
			printf("fizz");
		}

		if (!b) // b == 0 ==> divisible by n
		{
			printf("buzz");
		}

		printf("\n"); // line-break
	}

	return 0;
}
