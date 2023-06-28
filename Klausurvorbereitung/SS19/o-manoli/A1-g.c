#include <stdio.h>

int original_func(int a)
{
	int b;
	if (a >= 0 && a <= 2)
	{
		b = 1;
		printf("Fall 1");
	}
	else if (a >= 3 && a <= 4)
	{
		b = 2;
		printf("Fall 2");
	}
	else
	{
		b = 3;
		printf("Fall 3");
	}
	return b;
}

/*

int func(int a)
{

	switch (a){
		case 0 ... 2:		// only works in gcc, Clang
			printf("Fall 1");
			return 1;
		case 3 ... 4:
			printf("Fall 2");
			return 2;
		default:
			printf("Fall 3");
			return 3;
	}

}

*/

int func(int a)
{
	switch (a){
		case 0:
		case 1:
		case 2:
			printf("Fall 1");
			return 1;
		case 3:
		case 4:
			printf("Fall 2");
			return 2;
		default:
			printf("Fall 3");
			return 3;
	}
}

int main()
{
	func(1);
	func(3);
	func(5);
}
