#include <stdio.h>
#include <stdlib.h>

#define DIM 8

float *myfunc(int *, int);

int main(void)
{
	int i;
	int k = 1;
	int fa[DIM];
	int *p1;
	float *p3;
	float **p2;
	const char *abeitstag[] = {"Mo", "Di", "Mi", "Do", "Fr"};

	for (i = 0; i < DIM; i++)
		fa[i] = (i + 4) % 4; // loop will break at i == DIM

	p1 = fa + 3; // same as fa[3]

	// i = 8, *p1 = fa[3] = (3+4)%4 ) = 3%4 = 3, fa[5] = 1, *(fa + 6) = fa[6] = 2
	printf("a) i=%d, *p1=%d, fa[5]=%d, *(fa+6)=%d\n", i, *p1, fa[5], *(fa + 6));

	p3 = myfunc(p1, k); // will rewrite *p1 with 122, won't k and returns k+2 as a float

	// k = 1, *p1 = fa[3] = p as %c, sizeof(fa[3])=sizeof(int) = 4, *p3 = 3.0000
	printf("b) k=%d, *p1=%c, sizeof(fa[3])=%ld, *p3=%f\n", k, *p1, sizeof(fa[3]), *p3);

	p2 = &p3;
	**(p2) = DIM + 6;
	// *p2 = x<ADRESS OF p3>, **p2 = (DIM is 8) + 6 = 14.0000, *(abeitstag + 2) = Mi, **p2 / 2 = 7.0000
	printf("c) *p2=%p, **p2=%f, *(abeitstag+2)=%s, p2/7=%f\n", *p2, **p2, *(abeitstag + 2), **p2 / 2);

	return 0;
}

float *myfunc(int *b, int k)
{
	float *p;
	k = k + 1; // only effect local var k
	p = (float *)malloc(sizeof(float));
	*p = k + 1; // k refers to local variable which have been incremented
	*b = 'p';	// 'p' has the numerical value of 112 which will be casted to an int and written in *b
	return p;

	// This function will do:
	// rewrite *b with the value of 112
	// return a float with the value k+2
}
