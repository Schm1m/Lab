#include <stdio.h>

int main()
{
	int f[3] = {5, 2, 7}; // Feld
	// in C an array variable is just a pointer with a constant value
	//			referencing the first byte of element/cell in that array
	int *z = f; // -> pointer to the element f[0]

	f[0] = *z++;	// d1
	// the increment operator can always be written as two separate command `f[0] = *z; z = z + 1;`
	// `z+1` will be interpreted as pointer arithmetic which means that
	//			the address value saved in the pointer z will be added to 1*sizeof(int)
	// e. g. let's say z is `0x0000 00B0` z+1 will be `0x0000 00B4` where `0x4 byte` is `32 bit`
	// assign f[0] to the dereferenced value of z which is f[0] and the shifts the pointer z to next cell

	f[0] = (*z)++; // d2
	// this again can be written as two separate commands `*z = *z + 1; f[0] = *z;`
	// dereference the value of z which points to f[1] and increment that cell value by 1
	//and assign this value to f[0] to the updated value of f[1] which is f[1]+1 = 3

	f[0] = *(z++); // d3		//# same as *z++;
	// `f[0] = *z; z = z + 1;`
	// dereferencing doesn't count as a separate command
	// therefor the pointer will be dereferenced first and the shifted by 4-byte
	// this will assign the value of f[2] to f[0]


	printf("# ANS:\n\n");
	printf("f[0] = %d\n", f[0]);

	printf("\n- - - - -\n\n");

	printf("# Pointer Arithmetics:\n\n");

	int *ptr = f;
	printf("int *ptr = f;\nptr:\t\t%p\n", ptr);
	printf("ptr + 1:\t%p\n", ptr + 1);

	printf("\n((long int) (ptr + 1)) - ((long int) ptr):\t%lu\n", ((long int) (ptr + 1)) - ((long int) ptr)); // #UNFUG

	return 0;
}
