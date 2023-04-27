/*
	Author: Manoli
*/

#include <stdio.h>

#define BUFFER_SIZE 40
char B[BUFFER_SIZE];

int main()
{

	int start, end;

	// fetch input
	scanf("%s %d %d", B, &start, &end);

	// print program parameters
	printf("%s %d-%d: ", B, start, end);

	// 	if (start < 0 || end > BUFFER_SIZE-1){
	// 		printf("\nOUT-OF-BOUND!\n");
	// 	}
	// skip testing for now
	// while (end - start +1)  // works 2
	while (start <= end)
	{
		printf("%c", B[start++]);
	}

	printf("\n"); // break-line

	return 0;
}
