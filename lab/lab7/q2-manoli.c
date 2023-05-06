/*
	Author: Manoli
*/

#include <stdio.h>

void toUpper(char arr[])
{
	// shifts the pointer to the left to start the loop by incrementing first!
	arr--;			// should be okay no dereferencing
	while (*++arr) // increment then test and keep the same value you tested for
	{					// arr should be Null terminated!
		if (*arr >= 'a')
		{ // upper bound
			if (*arr <= 'z')
			{ // lower bound
				*arr -= 32;
			} // 'a' - 'A' = 32
		}	  // if not within bound do nothing
	}
}

int main()
{
	char arr[] = "Hello World";

	toUpper(arr);

	printf("%s\n", arr);

	return 0;
}
