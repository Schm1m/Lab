/*
	Author: Manoli
*/

#include <stdio.h>

// Square Grid Bounds
#define GRID 20

// Two Board to represent evolution
int Board[2][GRID][GRID]; // can't change the current generation state!

// Oscillator between 1 and zero to access the current generation configuration from the Board Array
int CurrentGeneration = 0;

int GenerationalShift()
{
	CurrentGeneration = 1 - CurrentGeneration;
	return CurrentGeneration;
}

// number of generation to be simulated
int Generations = 0; // will be overwritten be setup()

// Dead-Alive Ascii char used
char State[] = ".#";

void REST(int board[GRID][GRID], int value)
{
	int j, i = GRID;
	while (i--)
	{
		j = GRID;
		while (j--)
		{
			board[i][j] = value;
		}
	}
}

void MassExtinction()
{ // reset the board to the default value of 0
	REST(Board[CurrentGeneration], 0);
}

void showState(int *cell)
{
	putchar(State[*cell && 1]); // make sure that its either 1 or 0
}

void showBoard(int board[GRID][GRID])
{
	int j, i = -1;
	while (++i < GRID)
	{
		j = -1;
		while (++j < GRID)
		{
			showState(*(board + i) + j);
		}
		putchar('\n');
	}
}

void show()
{
	showBoard(Board[CurrentGeneration]);
}

int isAlive(int Gen[GRID][GRID], int i, int j)
{
	if (i < GRID)
	{
		if (j < GRID)
		{
			return Gen[i][j]; // only read value if within bound
		}
	}
	return 0; // otherwise assume dead
}

int AliveNeighbors(int Gen[GRID][GRID], int i, int j)
{
	int headcount = 0;
	int S[] = {0, 1, -1}; // access Sequence

	int m = -1; // shift
	int n = 0;	// skip 0 for first run

	while (++m < 3)
	{
		while (++n < 3)
		{ // isAlive checks if within bounds
			headcount += isAlive(Gen, i + S[m], j + S[n]);
		}
		n = -1; // rest for the next run
	}

	return headcount;
}

int LiveDieOrBeBorn(int Gen[GRID][GRID], int i, int j)
{
	int neighbors = AliveNeighbors(Gen, i, j);

	if (Gen[i][j])
	{ // the cell is alive // only need a reason to kill it
		// interval (1,4) <==> [2, 3]
		// if fewer than 2 neighbors or more the 3 ==> cell will die
		return (neighbors < 2 || neighbors > 3) ? 0 : 1; // or not
	}
	// the cell is dead
	// need exactly three neighbors to revive
	return (neighbors == 3) ? 1 : 0;
}

void transition(int Gen[GRID][GRID], int nextGen[GRID][GRID])
{
	REST(nextGen, 0); // setup board

	int j, i = -1;

	while (++i < GRID)
	{
		j = -1;
		while (++j < GRID)
		{
			nextGen[i][j] = LiveDieOrBeBorn(Gen, i, j);
		}
	}
}

void SimulateLife()
{
	int i = -1;
	int Gen, nextGen;

	while (++i <= Generations)
	{
		printf("-- Generation: %d\n", i);
		show();
		Gen = CurrentGeneration;
		nextGen = GenerationalShift();
		transition(Board[Gen], Board[nextGen]);
	}
}

void populate()
{
	char buffer;
	scanf("\n%c", &buffer);

	int i, j; // cell coordinates

	while (buffer == 'a')
	{
		scanf("%d %d", &j, &i);
		Board[CurrentGeneration][i][j] = 1;
		scanf("\n%c", &buffer);
	}
}

void setupSim()
{
	// get number of sim
	MassExtinction(); // clean up the board first
	scanf("%d", &Generations);
	populate();
}

int main(int argc, char *argv[])
{

	setupSim();

	SimulateLife();

	return 0;
}
