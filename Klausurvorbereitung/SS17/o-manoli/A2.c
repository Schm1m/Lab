#include <stdio.h>
#include <stdlib.h>
#define DIM 7

char *func(char, char *);
char x = 12;

void main(void)
{
	char i;
	char arr[DIM];
	char *p1 = arr;
	char *p2 = &arr[3];
	char *p3;
	char **p4;
	char *pf[] = {"Exam", "PG2", "toll"};
	for (i = DIM; i >= 1; i--) arr[i - 1] = i;	// start writing from the end, i-1 -> i bzw. index -> index+1
	// array-index -> value : {0 -> 1, 1 -> 2 , i-1 -> i}
	*(arr + 4) = 10;	// eqv. `arr[4] = 10`
	// loop will be broken when i == 0
	// i=0,  arr[0]=1, *p2=arr[3] = 4, arr[4] = 10, *(p1+6)=*(arr+6)=arr[6]=7
	printf("a) i=%d, arr[0]=%d, *p2=%d, arr[4]=%d, *(p1+6)=%d\n", i, arr[0], *p2, arr[4], *(p1 + 6));

	// x = 12, pf[1]="PG2", *(pf+2)=pf[2]="toll", **pf= pf[0][0] = 'E' -> the first char form the first
	printf("b) x=%d, pf[1]=%s, *(pf+2)=%s, **pf=%c\n", x, pf[1], *(pf + 2), **pf);
	p3 = func(x, p1);	// x won't be affected. #pass-by-value, *(p1+5) will be overwritten with 16, returns 68 bzw. 'D'
	p4 = &p1;
	// x=12, p3 is 68 which 'D' in ascii, **p4=*p1=arr[0]=1
	printf("c) x=%d, *p3=%c, arr[5]=%d, **p4=%d\n", x, *p3, arr[5], **p4);
	free(p3);
}
char *func(char x, char *p)
{
	char *p1 = (char *)malloc(sizeof(char));		// creates space for a new variable
	if (p1 == NULL)
		exit(1);		// exits the entire program with an error code 1, if memory request is denied!
	*p1 = 68;	// writes the value 68 in the newly allocated memory
	x = 5;	// ignores the passed value of x and rewrite the function local variable
	*(p + x) = 16;	// shifts the pointer to the p+5 cell and rewrites its value with 16
	return p1;
	// this function has two effects
	//		- overwrites the value of the cell p+5 with 16
	//		- returns a heap allocated char variable with of 68
	//		#*if the system didn't allocate memory via the malloc syscall, the program will crash/terminate
}
