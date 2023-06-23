#include <stdio.h>

void druckeFeld(int array[], unsigned int n_anzahl)
{
	int i;
	for (i = 0; i < n_anzahl; i++)
		printf("%d, ", array[i]);
	printf("\n");
}

int main()
{
	int test[10], i;

	for (i = 0; i <= 10; i++)
		test[i] = i;

	druckeFeld(test, 10); // Segfault!!!
}
