#include <stdio.h>
#include <stdlib.h>
#define DIM 7

char *func(char, char *);
char x = 12;

void main(void) {
	char i;
	char arr[DIM];
	char *p1 = arr;
	char *p2 = &arr[3];
	char *p3;
	char **p4;
	char *pf[] = {"Exam", "PG2", "toll"};

	for (i = DIM; i >= 1; i--) arr[i - 1] = i; // {0:1, ...6:7 ,7:8}

	*(arr + 4) = 10; // overwrites where arr[4] = 5 -> 10
	// i = 0 // for-loop breaks when i >= 1 -> i == 0
	// arr[0] = 1, arr maps n -> n+1, #sometimes #initialized in the for-loop LINE17
	// p2 points-to -> arr[3] ,*p2 = arr[3] = 4
	// arr[4] = 10, #overwritten at LINE19
	// p+6 -> arr[6], *(p+6) = arr[6] = 7, #arr {n: n+1} map #when-not-overwritten
	printf("a) i=%d, arr[0]=%d, *p2=%d, arr[4]=%d, *(p1+6)=%d\n"
				,i, arr[0], *p2, arr[4], *(p1 + 6));
	// a) i=0, arr[0]=1, *p2=4, arr[4]=10, *(p1+6)=7

	// x = 12, %d as an int, x never changed from LINE6
	// pf[1] is the second indexed element from pf. INDEX STARTS AT 0! #not-julialang
	// pf+2 -> pf[2] = "toll". Third Element
	// **pf refers to the first char from the first string in pf "Exam"
	printf("b) x=%d, pf[1]=%s, *(pf+2)=%s, **pf=%c\n", x, pf[1],
				*(pf + 2), **pf);
	// b) x=12, pf[1]=PG2, *(pf+2)=toll, **pf=E

	// Exkurs
	// the dereferencing operator always works from inside outwards
	//   *pf -> return as string, *(*pf) -> dereference that string which is just an array
	//      e.g. *(*pf+1) -> x refers to the second char from the first string
	//      e.g. *(*(pf+1)+2) -> 2 refers to the third char from the second
	// printf("*(*pf+1): %c, *(*(pf+1)+2): %c\n", *(*pf+1), *(*(pf+1)+2));

	p3 = func(x, p1);	// writes p1+5: arr[5] <- 16, doesn't change x, returns 68 ASCII 'D'
	p4 = &p1; // p1 points2 arr[0] -> 1

	// x = 12, never changed
	// *p3 = 68, %c as char 'D', return value of func
	// arr[5] is *(p1+5) = 16, got overwritten in func
	// p4 point2 -> p1 -> arr[0] which is 1
	printf("c) x=%d, *p3=%c, arr[5]=%d, **p4=%d\n", x, *p3,
			 arr[5], **p4);
	// c) x=12, *p3=D, arr[5]=16, **p4=1

	free(p3);
}

char *func(char x, char *p){
	char *p1 = (char *)malloc(sizeof(char));
	if (p1 == NULL) exit(1); // crashes the program when memory is denied!
	*p1 = 68;	// 68 is 'D' in ASCII
	x = 5;
	*(p + x) = 16;	// overwrite of p+5 to 16
	return p1;
}
