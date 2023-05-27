/*
	Author: Manoli
*/

#include <stdio.h>

// Square Grid Bounds
#define GRID 20

// Two Board to represent evolution
int Board[2][GRID][GRID]; // can't change the current generation state!

enum CellState
{
	Dead, // Value of 0
	Alive // Value of 1
};

// Oscillator between 1 and zero to access the current generation configuration from the Board Array
int CurrentGeneration = 0;

int GenerationalShift()
{ // protects CurrentGeneration variable from mis-use #hopefully
	CurrentGeneration = 1 - CurrentGeneration;
	return CurrentGeneration;
}

// number of generation to be simulated
int Generations; // will be overwritten/set be setup()

// Dead-Alive Ascii char used
char State[] = ".#";

void MassExtinction(int board[GRID][GRID])
{ // rests the given board
	int j, i = GRID;
	while (i--)
	{
		j = GRID;
		while (j--)
		{
			board[i][j] = Dead;
		}
	}
}

int isAlive(int Gen[GRID][GRID], int i, int j)
{
	if (0 <= i && i < GRID) // Row-Bounds			-> [0, GRID]
	{
		if (0 <= j && j < GRID) // Column-Bounds	-> [0, GRID]
		{
			return Gen[i][j]; // only read value if index within bounds
		}
	}
	return Dead; // otherwise assume dead
}

int AliveNeighbors(int Gen[GRID][GRID], int i, int j)
{
	int headcount = 0;
	int S[] = {0, 1, -1}; // access Sequence

	int m = 0; // shift
	int n = 1; // skip 0 for first run
	do
	{
		do
		{ // isAlive checks if within bounds
			headcount += isAlive(Gen, i + S[m], j + S[n]);
		} while (++n < 3);
		n = 0; // rest for the next run
	} while (++m < 3);

	return headcount;
}

int LiveDieOrBeBorn(int Gen[GRID][GRID], int i, int j)
{
	int neighbors = AliveNeighbors(Gen, i, j);

	if (Gen[i][j])
	{ // the cell is alive // only need a reason to kill it
		// interval (1,4) <==> [2, 3]
		// if fewer than 2 neighbors or more the 3 ==> cell will die
		return (neighbors < 2 || neighbors > 3) ? Dead : Alive; // or not
	}
	// the cell is dead
	// need exactly three neighbors to revive
	return (neighbors == 3) ? Alive : Dead;
}

void transition(int Gen[GRID][GRID], int nextGen[GRID][GRID])
{
	for (int i = 0; i < GRID; i++)
	{
		for (int j = 0; j < GRID; j++)
		{
			nextGen[i][j] = LiveDieOrBeBorn(Gen, i, j);
		}
	}
}

void show(int board[GRID][GRID])
{
	for (int i = 0; i < GRID; i++)
	{
		for (int j = 0; j < GRID; j++)
		{
			putchar(State[board[i][j]]);
		}
		putchar('\n');
	}
}

void SimulateLife()
{
	int i = 0;
	int Gen, nextGen;
	do
	{
		printf("-- Generation: %d\n", i);
		Gen = CurrentGeneration;
		show(Board[Gen]);
		nextGen = GenerationalShift();
		transition(Board[Gen], Board[nextGen]);
	} while (i++ < Generations); // i <= G -> [0, G]
}

void populate() // reads initial cell states
{
	char buffer;
	scanf("\n%c", &buffer);

	int i, j; // cell coordinates

	while (buffer == 'a')
	{
		scanf("%d %d", &j, &i);
		Board[CurrentGeneration][i][j] = Alive;
		scanf("\n%c", &buffer);
	}
}

void setupSim() // get number of Simulation needed
{
	MassExtinction(Board[CurrentGeneration]); // clean up the board first
	scanf("%d", &Generations);
	populate();
}

int main(int argc, char *argv[])
{
	setupSim();
	SimulateLife();
	return 0;
}
