#include <stdio.h>

float t;
int m;

void show (int [], int);	// just for show

void func2(int iArr[], int m)
{
	iArr[1] = 55; // assign arr[1] = 2 <- 55
	m = 77;		  // refers to the local variable m doesn't affect i
	t = 42.5;	  // refers to the global variable t
}
void func1()
{
	int arr[] = {1, 2, 3, 4};
	int i = 5;
	func2(arr, i);
	show(arr, i);
}

int main()
{
	func1();
	return 0;
}

void show(int arr[], int i)
{
	printf("t : %f\n", t);	// will be 42.50000
	printf("m : %d\n", m);	// stays at its initial value of 0
	printf("i : %d\n", i);	// stays at its initial value of 5
	printf("arr[] : ");
	for (int lv = 0; lv < 4; lv++) printf("%d, ", arr[lv]);	// 55 will be written where 2 once was
	printf("\n");
}
