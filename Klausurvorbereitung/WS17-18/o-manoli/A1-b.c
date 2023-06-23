#include <stdio.h>

// anything before this line will NOT be packed
#pragma pack(1) // tells the compiler to pack structs elements as close to each other as possible
// anything after this line will be packed

typedef struct typ1
{
	char text[10 + 1]; // 11 chars = 11 Byte
	int zahl;			 // an int is 32-bit -> 4 Byte		#*most-of-the-times
} TYP1;					 // should be 15 Byte.
// BUT sometimes it's not!
// # without compiler optimization -> will be rounded to 2^4 16 Byte

typedef struct typ2
{
	float zahlen[5]; // a float is 32-bit -> 4 Bytes
	double wert;	  // a double is a long float 64-bit -> 8 Bytes
	TYP1 s1;			  // 15 Byte
	struct typ2 *p1; // depends on cpu architecture 32-bit cpu -> 4 Byte, 64-bit -> 8 Byte
} TYP2;				  // 5*4 + 8 + 15 + 8 = 51 	# with pack(1)

TYP2 s2, *p2;

// lu unsigned long for size_t
#define SizeOf(type, Label) printf("\nsizeof %8s: %6lu Byte\n", Label, sizeof(type));

int main()
{
	SizeOf(char, "char");
	SizeOf(int, "int");
	SizeOf(float, "float");
	SizeOf(double, "double");
	SizeOf(TYP1, "TYP1");
	SizeOf(TYP2, "TYP2");
	return 0;
}
