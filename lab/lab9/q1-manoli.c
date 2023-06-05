/*
	Author: Manoli
*/

#include <stdio.h>

/* Data-Storage */

typedef struct
{
	double Zaehler; // Numerator
	double Nenner;	 // Denominator
} Bruch;

/* Data-Manipulation */

typedef struct
{
	char Symbol;
	Bruch (*callback)(Bruch, Bruch); // mapping of f(a, b) -> c
} Operator;

/* Definition of Operations */

Bruch multiple(Bruch a, Bruch b)
{
	Bruch c;
	c.Zaehler = a.Zaehler * b.Zaehler;
	c.Nenner = a.Nenner * b.Nenner;
	return c;
}

Operator M = {'*', multiple}; // M: alias for the multiplication operator

Bruch divide(Bruch a, Bruch b)
{
	Bruch c;
	c.Zaehler = a.Zaehler * b.Nenner;
	c.Nenner = a.Nenner * b.Zaehler;
	return c;
}

Operator D = {'/', divide}; // D: alias for the division operator

/* Data-Output Formatting*/

void show(Bruch B)
{
	printf("(%.1lf/%.1lf)", B.Zaehler, B.Nenner);
}

void display(Operator O, Bruch a, Bruch b)
{
	show(a);
	putchar(O.Symbol);
	show(b);
	putchar('=');
	show((O.callback)(a, b));
	putchar('\n');
}

/* Data-Input */

void assign(Bruch *B, int buffer[])
{
	B->Zaehler = buffer[0];
	B->Nenner = buffer[1];
}

void fetch_input(int buffer[2][2], int loop)
{
	// read tuples loop-times
	int *b;
	while (loop--)
	{
		b = *(buffer++);
		scanf("%d/%d", b, b + 1);
	}
}

// -----------------------------------

int main(int argc, char *argv[])
{
	int iBuffer[2][2];

	fetch_input(iBuffer, 2);

	Bruch a, b;

	assign(&a, iBuffer[0]);
	assign(&b, iBuffer[1]);

	// Multiply
	display(M, a, b);

	// Divide
	display(D, a, b);

	return 0;
}
