# Lösung zur Klausur Programmieren SS 2017

## By: [@O-Manoli](https://github.com/O-Manoli)

# Aufgabe 1: Allgemeine Fragen

## a) Gegeben ist folgender C-Code. Geben Sie den Wert der Variablen vl und v2 nach der Ausführung an.

```c
int v1,v2;
char feld[] = "4321";
v1 = sizeof feld;
v1 = strlen(feld);
```

### LOE:

```bash
--------------------
v1: 4
v2: 0
--------------------
```

```c
#include <stdio.h>
#include <string.h>

int main()
{
	int v1, v2;
	char feld[] = "4321";
	// terminating char '\0' will be added to the allocated cha array by the compiler
	v1 = sizeof feld;	 // the size of the allocated array = 4 * chars + '\0' = 5
	v1 = strlen(feld); // just 4 * chars 4 .. 1. Will overwrite the value of v1

	printf("v1: %d\n", v1); // will be 4 because it got reassigned
	printf("v2: %d\n", v2); // will stay at its initial value. Never got assigned!

	return 0;
}

```

## b) Wieviel Speicher Wird im folgenden Teil eines C-Programms reserviert? Erläutern Sie Ihr Ergebnis.

Using `#pragma pack(1)` will disable compiler size optimization. Otherwise results may vary.

```c
typedef struct typ1
{
	char text[8];
	int zahl;
} TYP1;
typedef struct typ2
{
	float zahlen[5];
	double wert;
	TYP1 s1;
	struct typ2 *p1;
} TYP2;

TYP2 s2, *p2;
```

### LOE:

```bash
--------------------
sizeof     char:      1 Byte

sizeof      int:      4 Byte

sizeof    float:      4 Byte

sizeof   double:      8 Byte

sizeof   TYP2 *:      8 Byte

- - - - - -

# ANS:

sizeof     TYP1:     12 Byte

sizeof     TYP2:     48 Byte
--------------------
```

```c

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
	SizeOf(TYP2 *, "TYP2 *");
	printf("\n- - - - - -\n\n# ANS:\n");
	SizeOf(TYP1, "TYP1");
	SizeOf(TYP2, "TYP2");
	return 0;
}

```

[Youtube Jacob Sorber: Struct packing: No, you're not going crazy.](https://youtu.be/grk4QUDveFw)

[Reihnwerk OpenBook: Attribute von Strukturen verändern (nicht ANSI C) topZur vorigen Überschrift](https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/015_c_strukturen_012.htm)

[IBM: #pragma pack](https://www.ibm.com/docs/en/zos/2.3.0?topic=descriptions-pragma-pack)

Any system with more than 4 GB of RAM most definitely has a 64-bit operating system, which use `8-Byte` pointers.

[3_GB_barrier](https://en.wikipedia.org/wiki/3_GB_barrier)

## c) Gegeben ist folgender C-Code:

```c
enum farbe {rot, blau, gruen, gelb, schwarz};
enum farbe blume;
for (blume=rot; blume<=gelb; blume++)
{
  if (blume==rot) printf("Farbe rot\n");
  else if (blume==blau) printf("Farbe blau\n");
  else printf("andere Farbe\n");
}
```

### c1) Geben Sie die Ausgabe (printf) auf dem Bildschirm an.

#### LOE:

```bash
--------------------
Farbe rot
Farbe blau
andere Farbe
andere Farbe
--------------------
```

```c
#include <stdio.h>

int main()
{
// enumeration means numbering items of a list
// ==> each keyword will have a numerical value
// The compiler will replace each keyword with its numerical value and treat it as `const int`
// by default enum start count at 0
// N-Vals:		0,		1,		2,			3,		4
	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;	// new variable of type enum

// for loop is composed of:
//		initializing command; loop condition evaluation; loop index increment/decrement

// this loop will initialize the `LaufVariable` with the value of blume = rot <=> 0
// the loop will continue to run until the condition `blume <= gelb` where gelb <=> 3.
// loop interval of [0, 3], [0, 4)
// at the end of each loop run the value of `blume` will be incremented by 1
// incrementing the enum variable will shifts the label to corresponding numerical value
	for (blume = rot; blume <= gelb; blume++)
	{
		if (blume == rot) printf("Farbe rot\n");		// will run with first loop run

		else if (blume == blau) printf("Farbe blau\n");		// will run with second loop run

		else printf("andere Farbe\n");	// will run twice with the third and fourth loop run
	}
	return 0;
}

```

> Wenn eine Variable mit enum definiert wird, behandelt sie der Compiler als Integerzahl. Sie kann dann jeden Wert annehmen, nicht nur die in enum festgelegten.

[enum Anweisung](https://www2.hs-esslingen.de/~zomotor/home.fhtw-berlin.de/junghans/cref/SYNTAX/enum.html)

[WiKi C-Programmierung: Aufzählung](https://de.wikibooks.org/wiki/C-Programmierung:_Komplexe_Datentypen#Aufz%C3%A4hlungen)

### c2) Ersetzen Sie nun die else-if-Anweisung durch eine entsprechende switch-Anweisung. Geben Sie den zugehörigen C-Code an.

#### LOE:

```c
#include <stdio.h>

int main()
{
// enumeration means numbering items of a list
// ==> each keyword will have a numerical value
// The compiler will replace each keyword with its numerical value and treat it as `const int`
// by default enum start count at 0
// N-Vals:		0,		1,		2,			3,		4
	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;	// new variable of type enum

// for loop is composed of:
//		initializing command; loop condition evaluation; loop index increment/decrement

// this loop will initialize the `LaufVariable` with the value of  blume = rot <=> 0
// the loop will continue to run until the condition `blume <= gelb` where gelb <=> 3.
// loop interval of [0, 3], [0, 4)
// at the end of each loop run the value of `blume` will be incremented by 1
// incrementing the enum variable will shifts the label to corresponding numerical value
	for (blume = rot; blume <= gelb; blume++)
	{
		switch (blume)		// the value to be compared
		{
		case rot:	// compare the value to this case.
		// If true do what's after the `:` otherwise seek next case
			printf("Farbe rot\n");		// will run with first loop run
			break;	// break the switch loop to stop comparing matches
		case blau:
			printf("Farbe blau\n");		// will run with second loop run
			break;
		default:	// no match found in `case`
			printf("andere Farbe\n");
		}
	}
	return 0;
}

```

[Microsoft Learn: switch Statement](https://learn.microsoft.com/en-us/cpp/c-language/switch-statement-c?view=msvc-170)

[Microsoft Learn: switch-Anweisung (C)](https://learn.microsoft.com/de-de/cpp/c-language/switch-statement-c?view=msvc-170)

[C-Programmierung: switch Anweisung](https://de.wikibooks.org/wiki/C-Programmierung:_Sprachbeschreibung:_Anweisungen#switch)

## d) Ein C-Programm enthält folgende Anweisungen:

```c
	int f[3] = {5, 2, 7}; // Feld
	int *z = f;
	f[0] = *z++;	// d1
	f[0] = (*z)++; // d2
	f[0] = *(z++); // d3
```

Geben Sie den Wert des Feldelements `f[0]` nach jeder Zuweisung (//d1-d3) an.

Erläutern Sie ihr Ergebnis

```bash
--------------------
f[0] = 3
--------------------
```

```c
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

	printf("f[0] = %d\n", f[0]);

	return 0;
}
```

[C-Programmierung: Inkrement- und Dekrement-Operator](https://de.wikibooks.org/wiki/C-Programmierung:_Operatoren#Inkrement-_und_Dekrement-Operator)

[C Referez: Inkrement und Dekrement](http://www2.hs-esslingen.de/~zomotor/home.fhtw-berlin.de/junghans/cref/CONCEPT/inc_dec.html)

[IBM Pointer Arithmetics](https://www.ibm.com/docs/en/i/7.2?topic=pointers-pointer-arithmetic)

[Youtube - Jacob Sorber: Issues with the pre- and postincrement operator in C, C++, etc.](https://youtu.be/Z4r4qJx9yds)

[Youtube - Jacob Sorber: Arrays, Pointers, and Why Arrays Start at Zero?](https://youtu.be/uT-YLEHwVS4)

# Aufgabe 2: Programm - Analyse

```c
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
	for (i = DIM; i >= 1; i--) arr[i - 1] = i;
	*(arr + 4) = 10;
	printf("a) i=%d, arr[0]=%d, *p2=%d, arr[4]=%d, *(p1+6)=%d\n", i, arr[0], *p2, arr[4], *(p1 + 6));
	printf("b) x=%d, pf[1]=%s, *(pf+2)=%s, **pf=%c\n", x, pf[1], *(pf + 2), **pf);
	p3 = func(x, p1);
	p4 = &p1;
	printf("c) x=%d, *p3=%c, arr[5]=%d, **p4=%d\n", x, *p3, arr[5], **p4);
	free(p3);
}
char *func(char x, char *p)
{
	char *p1 = (char *)malloc(sizeof(char));
	if (p1 == NULL)
		exit(1);
	*p1 = 68;
	x = 5;
	*(p + x) = 16;
	return p1;
}
```

## LOE:

```bash
--------------------
a) i=0, arr[0]=1, *p2=4, arr[4]=10, *(p1+6)=7
b) x=12, pf[1]=PG2, *(pf+2)=toll, **pf=E
c) x=12, *p3=D, arr[5]=16, **p4=1
--------------------
```

```c
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
```

# Aufgabe 3: Iteration und Rekursion

Schreiben Sie eine iterative und eine rekursive Programmlösung in C um die Zahlen eines
Arrays aufzusummieren. 1m Hauptprogramm (main) sollen die Funktionen getestet
werden. Testen Sie mit einem int array mit 5 Zahlen, gesucht ist die Summe dieser Zahlen.
`n` ist die Nummer des letzten Index-Elements des Arrays.
Ergänzen Sie die gegeben Funktionsrümpfe.

```c
#include <stdio.h>
int arr_sum_i(int arr[], int n) // iterative Lösung (6)
{
}
int arr_sum_r(int arr[], int n) // rekursive Lösung (6)
{
}
int main(void) // Hauptprogramm (4)
{
	// Testarray
	int arr[] =
}
```

## LOE:

```c
#include <stdio.h>

int arr_sum_i(int arr[], int n) // iterative Lösung (6)
{
	int Sum;

	// a count down loop
	for (Sum = 0; n-- > 0; Sum += *arr++);
	// fetch value and then shift the pointer

	return Sum;
}

int arr_sum_r(int arr[], int n) // rekursive Lösung (6)
{
	// stop when n == 0 -> 0
	// arr[0] and sum the rest starting with the element arr[1]
	return (n < 1) ? 0 : *arr++ + arr_sum_r(arr, n-1);
}

int main(void) // Hauptprogramm (4)
{
	// Testarray
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int n = sizeof(arr) / sizeof(int);

	printf("Sum Iterativ = %d\n", arr_sum_i(arr, n));
	printf("Sum Rekrusiv = %d\n", arr_sum_r(arr, n));
}

```

# Aufgabe 4: Strukturen

[See Klausur WS17-18](https://github.com/o-manoli/PGM-Lab/blob/master/Klausurvorbereitung/WS17-18/o-manoli/README.md#aufgabe-4-strukturen)
