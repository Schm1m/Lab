
#include <stdio.h>

int f_i(int n){	// iterative
	if (n < 1 ) return 0;
	if (n < 2 ) return 1;

	int f_2 = 0, f_1 = 1, f_n;

	// count down loop
	while (n-- > 1) // until n is reduced to a known the value of f(1)
	{
		f_n = f_2 + f_1;
		f_2 = f_1; // save values needed in the next loop
		f_1 = f_n;
	}

	return f_n;
}

int f_r(int n){ // recursive
	// 1 * (n == 1) <=> branchless 1 : 0
	return (n < 2) ? 1 * (n == 1) : f_r(n-2) + f_r(n-1);
}

void test(int (*f) (int), int N, char *Title){
	printf("\n%s\n", Title);

	for (int n = 0; n <= N; n++)
		printf("f(%d) : %d\n", n, f(n));

	printf("\n- - - - - - -\n");
}

int main(){
	test(f_i, 8, "\tIterative Fibonacci:\n");
	test(f_r, 8, "\tRecursive Fibonacci:\n");
}

