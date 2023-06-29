#include <stdio.h>
int arr_sum_i(int arr[], int n) // iterative Lösung (6)
{
	int Sum = 0;

	while (n-- > 0)	// a count down loop
		Sum += *arr++; // fetch value and then shift the pointer

	return Sum;
}

int arr_sum_r(int arr[], int n) // rekursive Lösung (6)
{
	return (n < 1) ? 0 : *arr + arr_sum_r(arr + 1, n - 1);
}

int main(void) // Hauptprogramm (4)
{
	// Testarray
	int arr[] = {1, 2, 3, 4, 5};

	int n = sizeof(arr) / sizeof(int);

	printf("Sum Iterativ = %d\n", arr_sum_i(arr, n));
	printf("Sum Rekrusiv = %d\n", arr_sum_r(arr, n));
}
