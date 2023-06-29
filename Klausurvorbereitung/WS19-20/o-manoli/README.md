# Lösung zur Klausur Programmieren WS 2019-2020

## By: [@O-Manoli](https://github.com/O-Manoli)

# Aufgabe 1: Allgemeine Fragen

## a) Finden und unterstreichen Sie im folgenden Code die syntaktischen Fehler

```c
include <stdio.h>
void echo() {
printf("%s", cArr);
}
int main(void) {
char[10] cArr;
print("Eingabe: ");
scanf("%s", cArr);
echo(cArr);
return 0;
}
```

### LOE:

```c
include <stdio.h> // # fehlt

void echo() {		// Eingabe wahrscheinlich fehlt. Kein globale Variable cArr
   printf("%s", cArr);	// cArr ist nicht definiert
}

int main(void) {
   char[10] cArr;	// [] muss nach cArr sein. char cArr[10];
   print("Eingabe: ");	// muss printf heißen
   scanf("%s", cArr);
   echo(cArr);	// nimmt eigentlich keine Eingabewerte. Muss erst korrigiert werden
   return 0;
}
```

```c
#include <stdio.h>

void echo(char cArr[]) {
   printf("%s", cArr);
}

int main(void) {
   char cArr[10];
   printf("Eingabe: ");
   scanf("%s", cArr);
   echo(cArr);
   return 0;
}
```

## b) Gegeben ist folgender C-Code. Geben Sie den Wert der Variablen vl und v2 nach der Ausführung an.

```c
int v1, v2;
char feld[] = "1234WVXYZ";
v1 = sizeof feld;
v2 = strlen(feld);
```

## LOE:

```bash
--------------------
v1: 10
v2: 9
--------------------
```

```c
#include <stdio.h>
#include <string.h>

int main(){

	int v1, v2;
	char feld[] = "1234WVXYZ"; // 1234 XYZ WV = 9
	v1 = sizeof feld;		// including '\0' -> 10
	v2 = strlen(feld);	// just 9 chars without \0'

	printf("v1: %d\n", v1);
	printf("v2: %d\n", v2);

	return 0;
}

```

## b) Gegeben ist folgender C-Code:

Geben Sie die Ausgabe (printf) auf dem Bildschirm an.

```c
enum farbe {rot, blau, gruen, gelb, schwarz};

enum farbe blume;

for (blume=rot; blume<=gelb; blume++)
{
	if (blume==rot)			printf("Farbe rot\n");
	else if (blume==blau)	printf("Farbe blau\n");
	else							printf("andere Farbe\n");
}

```

### LOE:

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
#include <string.h>

int main()
{

	enum farbe { rot, blau, gruen, gelb, schwarz};

	enum farbe blume;

	// rot, blau, gruen, gelb
	for (blume = rot; blume <= gelb; blume++)
	{
		if (blume == rot)				printf("Farbe rot\n");
		else if (blume == blau)		printf("Farbe blau\n");
		else								printf("andere Farbe\n");
	}

	return 0;
}

```

## d)Ersetzen Sie nun die else-if-Anweisung durch eine entsprechende switch-Anweisung. Geben Sie den zugehörigen C-Code an.

```c
enum farbe { rot, blau, gruen, gelb, schwarz};

enum farbe blume;

// rot, blau, gruen, gelb
for (blume = rot; blume <= gelb; blume++)
{
	switch(blume)
	{
		case rot:
			printf("Farbe rot\n");
			break;
		case blau:
			printf("Farbe blau\n");
			break;
		default:
			printf("andere Farbe\n");
			break;
	}
}
```

## e) Wahr Oder Falsch? Prüfen Sie, 0b die folgenden Aussagen wahr/richtig Oder falsch Sind.

- Bei einer Endlosrekursion kommt es zum Stapelspeicherüberlauf. `wahr`

- Die Zeichenkette (String) ist ein Datentyp in C. `falsch`

- Das Array `int iArr[32]` hat 32 Speicherplätze für Ganzzahlvariablen. `wahr`

- `%x` im Formatstring von printf druckt im Hexadezimalformat. `wahr`

- Die Schleifen `for(;X;){...}` und `while(X){...}` sind äquivalent. `wahr`

## f) Schreiben Sie eine Funktion uppercase, die einen gegebenen String in Großbuchstaben ausgibt. Beschränken Sie sich bei der Umwandlung der Kleinbuchstaben auf die 26 Buchstaben des Alphabets. Alle anderen Zeichen, Zahlen Oder Buchstaben (Z.B. ü, ö, ä) werden unverändert ausgegeben.

```c
const char SHIFT = 'a' - 'A'; // The same difference lower-upper

void uppercase(char S[])
{
	while (*S != '\0') // stop printing at '\0'
	{ // not within range [a, z] -> pass through
		putchar((*S < 'a' || *S > 'z') ? *S : *S - SHIFT);
		S++; // seek next char
	}
}

```

# Aufgabe 2: Programmanalyse

```c
#include <stdio.h>
#include <stdlib.h>
#define DIM 7

char *func(char, char *);
char x = 12;

void main(void){
	char i;
	char arr[DIM];
	char *p1 = arr;
	char *p2 = &arr[3];
	char *p3;
	char **p4;
	char *pf[] = {"Exam", "PG2", "toll"};
	for (i = DIM; i >= 1; i--) arr[i - 1] = i;

	*(arr + 4) = 10;
	printf("a) i=%d, arr[0]=%d, *p2=%d, arr[4]=%d, *(p1+6)=%d\n"
			, i, arr[0], *p2, arr[4], *(p1 + 6));

	printf("b) x=%d, pf[1]=%s, *(pf+2)=%s, **pf=%c\n", x, pf[1],
			 *(pf + 2), **pf);

	p3 = func(x, p1);
	p4 = &p1;
	printf("c) x=%d, *p3=%c, arr[5]=%d, **p4=%d\n", x, *p3,
			 arr[5], **p4);
	free(p3);
}

char *func(char x, char *p){
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

```
# Aufgabe 3: Iteration und Rekursion

Die Fibonacci-Folge ist eine unendliche Folge von Zahlen, bei der sich die jeweils folgende Zahl durch Addition ihrer beiden vorherigen Zahlen ergibt:

$$
    0, 1, 1, 2, 3, 5, 8, 13, 21
$$

Man kann die Fibonacci-Folge mit Hilfe des folgenden rekursiven Bildungsgesetzes und den
Anfangswerten $f(0)$ und $f(1)$ berechnen: $f(0) = 0$ und $f(1) = 1$
Jede weitere Zahl ist die Summe ihrer beiden Vorgänger: $f(n) = f(n-l) + f(n-2)$ für $n \geq 2$

Schreiben Sie eine iterative Lösung zur Berechnung von $f(n)$ mit $n \geq 0$:

```c
int f_i(int n){	// iterative
	if (n < 1 ) return 0;
	if (n < 2 ) return 1;

	int f_2 = 0, f_1 = 1, f_n;

	// count down loop
	while (n-- > 1) // until n is reduced to a known the value of f(1)
	{
		f_n = f_2 + f_1;
		f_2 = f_1; // save values need in the next loop
		f_1 = f_n;
	}

	return f_n;
}
```

Schreiben Sie eine rekursive Lösung zur Berechnung von $f(n)$ mit $n \geq 0$:

```c
int f_r(int n){ // recursive
	// 1 * (n == 1) <=> branchless 1 : 0
	return (n < 2) ? 1 * (n == 1) : f_r(n-2) + f_r(n-1);
}
```

## LOE:

```c

#include <stdio.h>

int f_i(int n){	// iterative
	if (n < 1 ) return 0;
	if (n < 2 ) return 1;

	int f_2 = 0, f_1 = 1, f_n;

	// count down loop
	while (n-- > 1) // until n is reduced to a known the value of f(1)
	{
		f_n = f_2 + f_1;
		f_2 = f_1; // save values needed in the next loop
		f_1 = f_n;
	}

	return f_n;
}

int f_r(int n){ // recursive
	// 1 * (n == 1) <=> branchless 1 : 0
	return (n < 2) ? 1 * (n == 1) : f_r(n-2) + f_r(n-1);
}

void test(int (*f) (int), int N, char *Title){
	printf("\n%s\n", Title);

	for (int n = 0; n <= N; n++)
		printf("f(%d) : %d\n", n, f(n));

	printf("\n- - - - - - -\n");
}

int main(){
	test(f_i, 8, "\tIterative Fibonacci:\n");
	test(f_r, 8, "\tRecursive Fibonacci:\n");
}

```

# Aufgabe 4: Strukturen

In einem Unternehmen soll das Inventar in einer dynamischen Liste erfasst werden. Zu jedem Gegenstand soll eine numerische ID, eine Beschreibung (100 Inhaltszeichen), der Anschaffungspreis, das Anschaffungsdatum und ein Zeiger auf das nächste Listenelemen abgelegt werden.

## a) Definieren Sie die genau passende Struktur sowie den passenden Startpointer (Anker).

> **Orientieren Sie sich dabei an den Informationen aus dem Code der anderen Teilaufgaben!**

### LOE:

```c
typedef struct{
	int jahr;
	int monat;
	int tag;
} date;

struct gegenstand{

	int id;
	char beschreibung[100];
	date datum;
	float preis;
	struct gegenstand *next;
};

struct gegenstand *anker = NULL;
```

## b) Die Funktion neuerEintrag() erzeugt einen neuen Gegenstand und fügt ihn am `Anfang` der Liste ein. Ergänzen Sie fehlenden Code.

```c
void neuerEintrag(int id, char beschreibung[], date datum, float preis) {
	struct gegenstand * neu;
	// hier fehlenden Code eintragen
}
```

### LOE:

```c
struct gegenstand* newNode(int id, char beschreibung[], date datum, float preis)
{
	struct gegenstand *N  = malloc(sizeof(struct gegenstand));
	if (N == NULL) return NULL;

	N->id = id;
	strcpy(N->beschreibung, beschreibung);
	N->datum = datum;
	N->preis = preis;
	N->next = NULL;

	return N;
}

void neuerEintrag(int id, char beschreibung[], date datum, float preis)
{
	struct gegenstand * neu = newNode(id, beschreibung, datum, preis);

	neu->next = anker;	// doesn't matter where anker points to
	anker = neu;
}
```

## c ) Ergänzen Sie eine Funktion ausgabe ( ) , die eine Liste der Gegenstände ausgibt, die vor einem gegebenen Datum angeschafft wurden.

```c
void ausgabe(int jahr, int monat, int tag)
{
	struct gegenstand * ptr = anker;
	// hier fehlenden Code eintragen
}
```

### LOE:

```c
void printDate(date *D)
{
	printf("%d-%02d-%02d", D->jahr, D->monat, D->tag);
}

void print(struct gegenstand *node)
{
	printf("ID: %d\n", node->id);
	printf("Beschreibung: %s\n", node->beschreibung);
	printf("Datum: ");
	printDate(&node->datum);
	printf("\nPreis: %.2f\n\n", node->preis);
};

void ausgabe(int jahr, int monat, int tag)
{
	struct gegenstand * ptr = anker;

	for (ptr = anker; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->datum.jahr > jahr) continue;	// skip if after date
		if (ptr->datum.monat > monat) continue;
		if (ptr->datum.tag >= tag) continue; // > includes, >= excludes
		print(ptr);	// excluding today
	}
}
```

## A4-LOE:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int jahr;
	int monat;
	int tag;
} date;

struct gegenstand{

	int id;
	char beschreibung[100];
	date datum;
	float preis;
	struct gegenstand *next;
};

struct gegenstand *anker = NULL;

struct gegenstand* newNode(int id, char beschreibung[], date datum, float preis)
{
	struct gegenstand *N  = malloc(sizeof(struct gegenstand));
	if (N == NULL) return NULL;

	N->id = id;
	strcpy(N->beschreibung, beschreibung);
	N->datum = datum;
	N->preis = preis;
	N->next = NULL;

	return N;
}

void neuerEintrag(int id, char beschreibung[], date datum, float preis)
{
	struct gegenstand * neu = newNode(id, beschreibung, datum, preis);

	neu->next = anker;	// doesn't matter where anker points to
	anker = neu;
}


void printDate(date *D)
{
	printf("%d-%02d-%02d", D->jahr, D->monat, D->tag); //ISO 8601
}

void print(struct gegenstand *node)
{
	printf("ID: %d\n", node->id);
	printf("Beschreibung: %s\n", node->beschreibung);
	printf("Datum: ");
	printDate(&node->datum);
	printf("\nPreis: %.2f\n\n", node->preis);
};

void print_all(){
	for (struct gegenstand *n = anker; n != NULL; n = n->next){
		print(n);
	}
}

void ausgabe(int jahr, int monat, int tag)
{
	struct gegenstand * ptr = anker;

	// for (ptr = anker; ptr != NULL; ptr = ptr->next)

	// {
	// 	if (ptr->datum.jahr > jahr) continue;	// skip if after date
	// 	if (ptr->datum.monat > monat) continue;
	// 	if (ptr->datum.tag > tag) continue;
	// 	print(ptr);	// including today
	// }

	for (ptr = anker; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->datum.jahr > jahr) continue;	// skip if after date
		if (ptr->datum.monat > monat) continue;
		if (ptr->datum.tag >= tag) continue; // > includes, >= excludes
		print(ptr);	// excluding today
	}
}

int main(){
	neuerEintrag(0, "Hello", (date) {2023, 6, 29}, 10.0);
	neuerEintrag(1, "World", (date) {2024, 3, 14}, 3.141592);

	neuerEintrag(3, "Pruefung", (date) {2023, 7, 7}, 6.0);
	neuerEintrag(4, "PGM", (date) {2023, 7, 6}, 4.0);
	neuerEintrag(5, "Programmieren == Programmierung", (date) {2023, 7, 5}, -1.11);
	neuerEintrag(6, "?", (date) {2023, 7, 4}, 0.0);

	print_all();

	printf("\n - - - - - \n\n");

	ausgabe(2023, 7, 7);

}

```