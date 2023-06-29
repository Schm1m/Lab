#include <stdio.h>

int arr_sum_i(int arr[], int n) // iterative Lösung (6)
{
	int Sum;

	// a count down loop
	for (Sum = 0; n-- > 0; Sum += *arr++);
	// fetch value and then shift the pointer

	return Sum;
}

int arr_sum_r(int arr[], int n) // rekursive Lösung (6)
{
	// stop when n == 0 -> 0
	// arr[0] and sum the rest starting with the element arr[1]
	return (n < 1) ? 0 : *arr++ + arr_sum_r(arr, n-1);
}

int main(void) // Hauptprogramm (4)
{
	// Testarray
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int n = sizeof(arr) / sizeof(int);

	printf("Sum Iterativ = %d\n", arr_sum_i(arr, n));
	printf("Sum Rekrusiv = %d\n", arr_sum_r(arr, n));
}
