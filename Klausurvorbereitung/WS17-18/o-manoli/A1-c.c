#include <stdio.h>

void druckeFeld(int array[], unsigned int n_anzahl)
{
	int i;								 // local variable
	for (i = 0; i < n_anzahl; i++) // n_anzahl is not known in this scope
		printf("%d; ", array[i]);	 // array is also unknown
	printf("\n");
	// %d indicates that's the type of array is an integer array
	// n_anzahl must be a whole number -> int
	// one can also use `unsigned int` which will be interpreted the same as `int` for non-negative values less 2^31
}

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	int n_anzahl = sizeof(array) / sizeof(int);
	druckeFeld(array, n_anzahl);
}
