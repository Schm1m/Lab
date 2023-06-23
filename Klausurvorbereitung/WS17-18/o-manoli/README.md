# Lösung zur Klausur Programmieren WS 2017/2018

## By: [@O-Manoli](https://github.com/O-Manoli)

## Aufgabe 1: Allgemeine Fragen

### a) Gegeben ist folgender C-Code:

```c
int v1,v2;
char feld[] = "123ab";
v1 = sizeof feld;
v2 = strlen(feld);
```

Geben Sie den Wert der Variablen v1 und v2 nach der Ausführung an.

#### LOE:

```c

int v1, v2;
char feld[] = "123ab";
// Terminating char '\0' will be added
// automatically be the compiler

v1 = sizeof feld; // *including '\0'
// sizeof in Bytes where 1 char -> 1 Byte
// 5 chars + '\0' = 6

v2 = strlen(feld); // excluding '\0'
// just 5 chars

```

### b) Wieviel Speicher wird im folgenden Teil eines C-Programms reserviert Erläutern Sie Ihr Ergebnis.

```c
typedef struct typ1
{
	char text[10 + 1];
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

#### LOE:

```c

// tells the compiler to pack structs elements as close to each other as possible
#pragma pack(1)

typedef struct typ1
{
	char text[10 + 1]; // 11 chars = 11 Byte
	int zahl;
// an int is 32-bit -> 4 Byte
} TYP1;// 11*1 + 4 = 15 Byte.
// BUT sometimes it's not!
// #compiler-optimization #pragma pack(1)

typedef struct typ2
{
	float zahlen[5]; // a float is 32-bit -> 4 Bytes

	double wert;
// a double is a long float 64-bit -> 8 Bytes

	TYP1 s1;   // 15 Byte

	struct typ2 *p1;// depends on cpu architecture
//32-bit cpu -> 4 Byte, 64-bit -> 8 Byte
} TYP2; // 5*4 + 8 + 15 + 8 = 51 	# with pack(1)

TYP2 s2, *p2;
```

[Youtube Jacob Sorber: Struct packing: No, you're not going crazy.](https://youtu.be/grk4QUDveFw)

### c) Ergänzen Sie in der Funktionsdefinition (\_\_\_) sinnvoll und begründen Sie.

```c
void druckeFeld (__________________){
int i;
for (i = 0; i < n_anzahl; i++)
printf("%d; ", array[i]); printf("\n");
}
```

#### LOE:

```c
void druckeFeld (int array[], int n_anzahl){
  int i;  // local variable
  for (i = 0; i < n_anzahl; i++)    // n_anzahl is not known in this scope
  printf("%d; ", array[i]); printf("\n");  // array is also unknown
  // %d indicates that's the type of array is an integer array
  // n_anzahl must be a whole number -> int
}
```

### d) Worauf müssen Sie bei der Verwendung von malloc achten?

- Überprüfen ob es tatsächlich Speicher vom Betrieb-System für das Program reserviert wurde. Also ob `malloc` Rückgabewert `NULL` ist oder nicht.
- Das Speicher Platz freigeben, nachdem das Programm es nicht mehr braucht. Und der Zeiger auf das Speicher auf `NULL` zu setzen, um nicht erlaubter Speicher Zugriff zu verhinndern.

### e) Thema Schleifen. Was passiert hier? Bitte erläutern Sie und schlagen Sie ggf. Änderungen vor.

```c
int test[10], i;
for(i = 0; i <= 10; i++) test[i] =i;
```

#### LOE:

```c
int test[10], i;
// hier wird ein Array vom Typ `int` deklariert
// mit der Variabeln name test
// es wird auch eine `int` Variable mit dem Name `i` deklariert

for(i = 0; i <= 10; i++) test[i] =i;
// Die Schleife setzt die Variable i auf 0;
// Als Bedingung wird `i <= 10` gesetzt, womit überprüft wird,
//      ob der Schleifen-Code-Block ausgeführt werden soll oder nicht;
// Und am Ende vom Schleifen-Code-Block wird die vriable `i` um 1 erhöht `i++`
// Inherlab der Schleifen-Code-Block
//      wird der Wert `i` in dem Array `test` gespeichert,
//        bei der Array-Index `i`
// Es wird aber zu einem `stack smashing detected` ERROR kommen!
// Das problem ist, `test` hat Platz nur für 10 Werte
// Die Schleife wird 11 Male ausgeführt! 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
```

### f) Wahr oder Falsch?

- Bei einer Endlosrekursion kommt es zum Stapelspeicherüberlauf.`Wahr`

  - [Stack-OverFlow](https://en.wikipedia.org/wiki/Stack_overflow)

- Die Zeichenkette ist ein Datentyp in C. `FALSCH`

  - [C Referenz: Zeichenkette](https://www2.hs-esslingen.de/~zomotor/home.fhtw-berlin.de/junghans/cref/CONCEPT/string.html)

- Das Array `int iArr[32]` hat 32 Speicherplätze für Ganzzahlvariablen. `Wahr`

  - [Rheinwerk](https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/011_c_arrays_001.htm)

- `%x` im Formatstring von printf druckt im Hexadezimalformat. `Wahr`

  - [C Programming/Procedures and functions/printf](https://en.wikibooks.org/wiki/C_Programming/Procedures_and_functions/printf)
  - [C-Programmierung: Einfache Ein- und Ausgabe](https://de.wikibooks.org/wiki/C-Programmierung:_Einfache_Ein-_und_Ausgabe)

- Mit `int i=123; float fArr[i]` kann man dynamische Arrays anlegen. `FALSCH`

  - `i` muss einen konstanten Wert zum Überseztung-Zeit haben!

- Die Schleifen `for(;X;){...}` und `while(X){...}` sind äquivalent `Wahr`

## Aufgabe 2: Programm - Analyse

```c
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

```

### ANS:

```bash

--------------------
a) i=8, *p1=3, fa[5]=1, *(fa+6)=2
b) k=1, *p1=p, sizeof(fa[3])=4, *p3=3.000000
c) *p2=0x55f87e29f6b0, **p2=14.000000, *(abeitstag+2)=Mi, p2/7=7.000000
--------------------
```

## Aufgabe 3: Iteration und Rekursion

Schreiben Sie eine iterative und eine rekursive Programmlösung in C um die Zahlen eines
Arrays aufzusummieren. Im Hauptprogramm (main) sollen die Funktionen getestet
werden. Testen Sie mit einem int array mit 6 Zahlen, gesucht ist die Summe dieser Zahlen.
n ist die Nummer des letzten Index-Elements des Arrays. Ergänzen Sie die gegeben
Funktionsrümpfe und komplettieren Sie das Hauptproramm zum Testen der Funktionen.

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

### LOE:

```c

#include <stdio.h>
int arr_sum_i(int arr[], int n) // iterative Lösung (6)
{
	int Sum = 0;

	while (n-- > 0)	// a count down loop
		Sum += *arr++; // fetch value and then shift the pointer

	return Sum;
}

int arr_sum_r(int arr[], int n) // rekursive Lösung (6)
{
	return (n < 1) ? 0 : *arr + arr_sum_r(arr + 1, n - 1);
}

int main(void) // Hauptprogramm (4)
{
	// Testarray
	int arr[] = {1, 2, 3, 4, 5};

	int n = sizeof(arr) / sizeof(int);

	printf("Sum Iterativ = %d\n", arr_sum_i(arr, n));
	printf("Sum Rekrusiv = %d\n", arr_sum_r(arr, n));
}

```

## Aufgaeb 4: Strukturen

Es soll der Inhalt eines Kühlschranks verwaltet werden. Bei Eingabe des aktuellen Datums (Tag, Monat, Jahr) werden alle bis dahin abgelaufenen Produkte gelistet. Es sollen Produkte in einer dynamischen Liste verwaltet werden. Pro Produkt wird der Produktname, Produktdetails (mit je 50 Zeichen) und das Ablaufdatum sowie ein Zeiger auf das folgende Listenelement in einem Struct abgelegt.

### 1) Definieren Sie die genau passenden Structs sowie den passenden Startpointer (Anker). Finden sie die benötigten Datentypen anhand des in den Teilaufgaben vorgegebenen Codes.

```c
typedef struct
{
	int day;
	int month;
	int year;
} date;

typedef struct s_Fridge
{
	char Product[50];
	char Name[50];
	date Ablauf;
	struct s_Fridge *next;
};

struct s_Fridge *first = NULL;
```

### 2) Die Funktion `new_entry` erzeugt einen neuen Produkteintrag. Ergänzen Sie fehlenden Code. Die Funktion sollen Sie in Teilaufgabe 3) verwenden/aufrufen.

```c
struct s_Fridge *new_entry(char Product[], char Name[], date ablauf)
{
	struct s_Fridge *ptr;

	ptr = (struct s_Fridge *)malloc(sizeof(struct s_Fridge));

	-----------------------------------------

	strcpy(ptr->Product, Product);
	strcpy(ptr->Name, Name);
	ptr->Ablauf.day = ablauf.day;
	ptr->Ablauf.month = ablauf.month;
	ptr->Ablauf.year = ablauf.year;
	ptr->next = NULL;

	return ptr;
}

```

#### LOE:

```c
struct s_Fridge *new_entry(char Product[], char Name[], date ablauf)
{
	struct s_Fridge *ptr;

	ptr = (struct s_Fridge *)malloc(sizeof(struct s_Fridge));

	if (ptr == NULL) return NULL;

	strcpy(ptr->Product, Product);
	strcpy(ptr->Name, Name);
	ptr->Ablauf.day = ablauf.day;
	ptr->Ablauf.month = ablauf.month;
	ptr->Ablauf.year = ablauf.year;
	ptr->next = NULL;

	return ptr;
}
```

### 3) Schreiben Sie eine Function insert, die einen neuen Eintrag vorn in die Liste hinzufügt. Verwenden Sie die Funktion new_ent ry aus Teilaufgabe 2).

```c
void insert (char Product[], char Name[], date ablauf)
{

}
```

#### LOE:

```c
void insert(char Product[], char Name[], date ablauf)
{
	struct s_Fridge *N = new_entry(Product, Name, ablauf);

	if (first == NULL) // the list is empty
	{
		first = N;
		return;
	}

	struct s_Fridge *LV = first; // Lauf Variable

	while (LV->next != NULL)
		LV = LV->next;

	LV->next = N;
}
```

### 3a) Wie nennt man diese Datenstruktur genau, die hier implementiert wird?

Eine Verkette Liste #Linked-List
[Professor David Brailsford: Essentials - Pointer Power! - Computerphile](https://youtu.be/t5NszbIerYc)

### 3b) Welche andere Datenstrukturen zum Definieren von Listen kennen Sie noch?

[Datenstruktur: Liste](<https://de.wikipedia.org/wiki/Liste_(Datenstruktur)>)

- Einfach verkettete Listen
- Doppelt verkettete Liste
- FIFO
- Queue
- Stack

### 4) Schreiben Sie eine Funktion `print_abgelaufen`, die eine Liste der abgelaufenen Produkte ausgibt, d.h. wenn das Haltbarkeitsdatum kleiner gleich dem aktuellen Datum ist.

```c
void print_abgelaufen ( date heute )
{
  struct s_Fridge * ptr;
  ptr = first;
  printf("Abgelaufen sind: \n");
}
```

#### LOE:

```c

void print(struct s_Fridge *node)
{
	printf("\nProduktdetails: %s\n", node->Product);
	printf("Produktname: %s\n", node->Name);
	printf(
			"Ablaufdatum: %d-%02d-%02d\n\n",
			node->Ablauf.year,
			node->Ablauf.month,
			node->Ablauf.day
	);
}

void print_abgelaufen(date heute)
{
	struct s_Fridge *ptr;
	ptr = first;
	printf("Abgelaufen sind: \n");

	for (; ptr != NULL; ptr = ptr->next)
	{
		if (heute.year < ptr->Ablauf.year) // skip if smaller
			continue;
		if (heute.month < ptr->Ablauf.month)
			continue;
		if (heute.day < ptr->Ablauf.day)
			continue;
		print(ptr);
	}
}

```
