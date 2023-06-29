#include <stdio.h>
#include <string.h>

int main()
{
	int v1, v2;
	char feld[] = "123ab";
	// Terminating char '\0' will be added!
	// automatically be the compiler

	v1 = sizeof feld; // *including '\0'
	// sizeof in Bytes where 1 char -> 1 Byte
	// 5 chars + '\0' = 6

	v2 = strlen(feld); // excluding '\0'
	// just 5 chars

	printf("v1: %d\n", v1);
	printf("v2: %d\n", v2);

	return 0;
}
