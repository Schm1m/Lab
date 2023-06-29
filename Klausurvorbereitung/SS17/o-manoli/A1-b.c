
#include <stdio.h>

// anything before this line will NOT be packed
#pragma pack(1) // tells the compiler to pack structs elements as close to each other as possible
// anything after this line will be packed

typedef struct typ1
{
	char text[8]; // 1 char -> 1 Byte >-> 8*char = 8 Byte
	int zahl;	  // int is by default int-32 in bits = 4 Byte
} TYP1;			  // 8*char + 1*int = 8 Byte + 4 Byte = 12 Byte

typedef struct typ2
{
	float zahlen[5]; // 1 float = 4 Byte >-> 5 * float = 20 Byte
	double wert;	  // double ==> double precision floating point number = 2*float = 4 Byte
	TYP1 s1;			  // 12 Byte
	struct typ2 *p1; // using a 32-bit CPU -> 4 Byte, using 64-bit CPU -> 8 Byte. Let's go with 8
} TYP2;				  // 5*float + 1*double + 1*TYP1 + 1*(struct type2*) = 20 + 8 + 12 + 8 = 48 Byte

TYP2 s2, *p2;

// lu unsigned long for size_t
#define SizeOf(type, Label) printf("\nsizeof %8s: %6lu Byte\n", Label, sizeof(type)); // sizeof -> Bytes

int main()
{
	SizeOf(char, "char");
	SizeOf(int, "int");
	SizeOf(float, "float");
	SizeOf(double, "double");
	SizeOf(TYP2 *, "TYP2 *"); // pointer type
	printf("\n- - - - - -\n\n# ANS:\n");
	SizeOf(TYP1, "TYP1");
	SizeOf(TYP2, "TYP2");
	return 0;
}
