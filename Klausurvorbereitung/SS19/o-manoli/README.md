# Lösung zur Klausur Programmieren SS 2019

## By: [@O-Manoli](https://github.com/O-Manoli)

# Aufgabe 1: Allgemeine Fragen

## a) Finden und unterstreichen Sie im fol enden Code dies taktischen Fehler.

```c
double square(double a) {
	a *= a;
	return a
}

integer main(int argc, char * argv[]) {
	double zahl;
	printf("Geben Sie eine Zahl ein: ");
	scanf("%lf", zahl);
	printf("\n%.2lf²=%.2lf", zahl, (*square)(zahl);
	return 0;
}
```

### LOE:

```c
// header file for `printf, scanf` is missing
//    #include <stdio.h>

double square(double a) {
	a *= a;
	return a  // missing semicolon ;
}

// integer is not a data type in C should be `int main`
integer main(int argc, char *argv[]) {
	double zahl;
	printf("Geben Sie eine Zahl ein: "); // defined in <stdio.h>

	// scanf needs an address to write into `scanf("%lf", &zahl);`
	scanf("%lf", zahl); // defined in <stdio.h>

	printf("\n%.2lf²=%.2lf", zahl, (*square)(zahl); // missing ) before the semicolon
	// square <=> (*square) <=> (*****square)...
	// dereferencing a function or even a function pointer,
	//    can be doe AS MANY TIME AS YOU WANT!
	// the result is always the same. Just a pointer to the code block,
	//    where the function is defined in memory
	// It is as futile , as me trying to understand `Elektrotechnik` :(.
	return 0;
}
```

[Stack Overflow: How does dereferencing of a function pointer happen?](https://stackoverflow.com/questions/2795575/how-does-dereferencing-of-a-function-pointer-happen)

## b) Gegeben ist folgender C-Code. Geben Sie die Ausgabe des Programms korrekt an.

```c
char feld[15] = "VWXYZ123";
int m = strlen(feld);
feld[m/2] = '\0';
printf("%4i\n%s", m, feld);
```

### LOE:

```bash
   8
VWXY
```

```c
#include <stdio.h>
#include <string.h>

int main()
{
	char feld[15] = "VWXYZ123";
	int m = strlen(feld); // 123 XYZ VW = 8
	feld[m / 2] = '\0';	 // 8/2 = 4	'\0'
	// truncates the string at the index 4
	printf("%4i\n%s", m, feld);
	//   8
	//VWXY
	return 0;
}

```

## c) Ein Array hat die Größe 123 Elemente; welchen Indexbereich hat eine Schleifenzählvariable i ?

Array Indexbereich Von $0$ bis $n - 1$ also von $0$ bis zum $122$.

Interval $[0, 122]$ bzw. $[0, 123)$, wobei $i$ eine ganze Zahl ist.

```c
// Example
int Array[123];
for (int i = 0; i < 123; i++);   // Interval [0, 123)
for (int i = 0; i <= 122; i++);  // same as [0, 122]
```

## d) Wenn in der main()-Methode einfach nur funcl() aufgerufen wird: welchen Wert haben `t, m, i und arr` am Ende der Funktion funcl und warum?

```c
float t;
int m;
void func2(int iArr[], int m)
{
	iArr[1] = 55;
	m = 77;
	t = 42.5;
}
void func1()
{
	int arr[] = {1, 2, 3, 4};
	int i = 5;
	func2(arr, i);
}
```

### LOE:

```bash
t : 42.500000
m : 0
i : 5
arr[] : 1, 55, 3, 4,
```

```c
#include <stdio.h>

float t;
int m;

void show (int [], int);  // just for show

void func2(int iArr[], int m)
{
	iArr[1] = 55; // assign arr[1] = 2 <- 55
	m = 77;		  // refers to the local variable m doesn't affect i
	t = 42.5;	  // refers to the global variable t
}
void func1()
{
	int arr[] = {1, 2, 3, 4};
	int i = 5;
	func2(arr, i);
	show(arr, i);
}

int main()
{
	func1();
	return 0;
}

void show(int arr[], int i)
{
	printf("t : %f\n", t);	// will be 42.50000
	printf("m : %d\n", m);	// stays at its initial value of 0
	printf("i : %d\n", i);	// stays at its initial value of 5
	printf("arr[] : ");
	for (int lv = 0; lv < 4; lv++) printf("%d, ", arr[lv]);	// 55 will be written where 2 once was
	printf("\n");
}

```

## e) Array Sind Pointer und Pointer Sind Arrays! Dennoch gibt es Unterschiede zwischen Pointer-Variablen und Array-Variablen. Welche?

Man kann nicht dem Array eine neue Adresse zuweisen, was natürlich mit einem Pointer erlaubt ist.

Das Ergbins vom `sizeof` Operator angewendet auf einem Array liefert die Größe von der gesamten Array in Bytes. `sizeof` Pointer ist nur die Größe der Pointer selbst. Also 4 Byte bzw. 8 Byte abhängig davon, ob man 32-bit bzw. 64-bit CPU hat.

## f) Initialisieren Sie folgendes Array vollständig mit beliebigen Werten im angegebenen Wertebereich. Achten Sie auf korrekte Klammersetzung!

```c
int arr[2][3][2] =
```

### LOE:

```c
int arr[2][3][2] = {{{1, 1}, {2, 2}, {3, 3}}, {{4, 4}, {5, 5}, {6, 6}}};
```

## g) Schreiben Sie das If-Statement um in ein Switch-Statement mit äquivalenter Semantik.

```c
int func(int a)
{
	int b;
	if (a >= 0 && a <= 2)
	{
		b = 1;
		printf("Fall 1");
	}
	else if (a >= 3 && a <= 4)
	{
		b = 2;
		printf("Fall 2");
	}
	else
	{
		b = 3;
		printf("Fall 3");
	}
	return b;
}
```

### LOE:

```c
int func(int a)
{
	switch (a){
		case 0 ... 2:		// only works in gcc, Clang
			printf("Fall 1");
			return 1;
		case 3 ... 4:
			printf("Fall 2");
			return 2;
		default:
			printf("Fall 3");
			return 3;
	}
}
```

```c
int func(int a)
{
	switch (a){
		case 0:  // or
		case 1:
		case 2:
			printf("Fall 1");
			return 1;
		case 3:
		case 4:
			printf("Fall 2");
			return 2;
		default:
			printf("Fall 3");
			return 3;
	}
}
```

# Aufgabe 2: Programmierung

Gegeben sind zwei reelle Vektoren im 3-dimensionalen Raum.

(Datentyp double) `a = (a1, a2, a3)` und `b = (b1, b2, b3)`.

Die zwei Vektoren sind orthogonal, wenn ihr inneres Produkt $0$ ergibt. Das innere Produkt zweier Vektoren $v$ und $w$ ist allgemein wie folgt definiert:

$v * w = v_1*w_1 + \cdots  + v_i*w_i + \cdots +  v_n*w_n$

## a) Schreiben Sie eine Funktion `isOrthogonal()`, die die zwei 3-dimensionalen Vektoren a und b auf Orthogonalität prüft und das Ergebnis als true (die Vektoren sind orthogonal) bzw. false (die Vektoren sind nicht orthogonal) zurückgibt. Definieren und benutzen Sie für die Rückgabe einen entsprechenden globalen Datentyp.

### LOE:

```c
typedef struct{
	double x;
	double y;
	double z;
}Vector;

double e = 1e-7;      // 10^-7

int isOrthogonal(Vector a, Vector b)
{
	double dot = a.x * b.x + a.y * b.y + a.z * b.z;

	dot = (dot < 0) ? -dot : dot;	// abs

	return dot <= e; // floating point arithmetic is never precise
}
```

## b)

### LOE:

```c
#include <stdio.h>

typedef struct{

	double x;
	double y;
	double z;

}Vector;

double e = 1e-7;      // 10^-7

int isOrthogonal(Vector a, Vector b)
{
	double dot = a.x * b.x + a.y * b.y + a.z * b.z;

	dot = (dot < 0) ? -dot : dot;	// abs

	return dot <= e; // floating point arithmetic is never precise
}

int main(){

	Vector v1 = {-1, 0, 0};
	Vector v2 = {1, 1, 0};

	printf("isOrthogonal(): %d\n", isOrthogonal(v1, v2));

	return 0;
}

```

[Struct and union initialization](https://en.cppreference.com/w/c/language/struct_initialization)

[Micosoft Learn: Brace initialization for classes, structs, and unions](https://learn.microsoft.com/en-us/cpp/cpp/initializing-classes-and-structs-without-constructors-cpp?view=msvc-170)

[Micorsoft Learn: Initialisierung mit geschweiften Klammern](https://learn.microsoft.com/de-de/cpp/cpp/initializing-classes-and-structs-without-constructors-cpp?view=msvc-170)

## c) Wahr oder Falsch?

Prüfen Sie, ob die folgenden Aussagen wahr/richtig oder falsch sind.

- `%lf` im Formatstring von printf druckt im Double-Format. `wahr`

  - a double is just a long float $ double = 2 \times float$

  - [C-Programmierung: Einfache Ein- und Ausgabe](https://de.wikibooks.org/wiki/C-Programmierung:_Einfache_Ein-_und_Ausgabe)

  - [C Referenz: printf Formatierungszeichen](https://www2.hs-esslingen.de/~zomotor/home.fhtw-berlin.de/junghans/cref/FUNCTIONS/format.html)

- Mit „return 1;" in der Main-Methode signalisiert man einen erfolgreichen Durchlauf des Programms `wahr`

  - [CS50: EXIT CODE](https://cs50.harvard.edu/ap/2020/assets/pdfs/exit_codes.pdf)

- Der Zugriff auf das 9. Element eines Arrays der Größe 8 führt zu einem Laufzeitfehler `wahr`

- Die Anweisung für das Inkrement in der For-Schleife Wird vor dem Schleifenkörper ausgeführt `falsch`

# Aufgabe 3: Programmanalyse

## a) In folgendem Programm hat sich ein Fehler eingeschlichen. Benennen Sie den Fehler, erläutern das Problem und beheben Sie den Fehler.

```c
int zahl;
printf("Geben Sie eine ganze Zahl ein: ");
scanf("%d", zahl);
```

### Fehler:

```c
scanf("%d", zahl);  // scanf braucht die Adresse von `zahl`
```

### Erläuterung:

`scanf` nimmt ein Format-String und eine Adresse als Einagbe.

[How to Use scanf( ) in C to Read and Store User Input](https://www.freecodecamp.org/news/using-scanf-in-c/)

### Behebung:

```c
int zahl;
printf("Geben Sie eine ganze Zahl ein: ");
scanf("%d", &zahl);
```

## b) Analysieren Sie das folgende Programm und geben Sie die Ausgabe an.

```c
#include <stdio.h>
unsigned short int si;
void main()
{
	int i, k;
	int *iPtr;
	int *kPtr;
	int **iPtrPtr;
	unsigned short int *siPtr;
	void *vPtr;
	i = 3;
	k = 7;
	iPtr = &i;
	kPtr = &k;
	iPtrPtr = &iPtr;
	*kPtr += 2;
	printf("a) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);
	(*iPtr)++;
	*iPtrPtr = kPtr;
	i += *iPtr;
	--(*kPtr);
	kPtr = &i;
	printf("b) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);
}
```

### LOE:

```bash
--------------------
a) i=3, k=9, *iPtr=3, *kPtr=9, **iPtrPtr=3
b) i=13, k=8, *iPtr=8, *kPtr=13, **iPtrPtr=8
--------------------
```

```c
#include <stdio.h>
unsigned short int si;
void main()
{
	int i, k;
	int *iPtr;
	int *kPtr;
	int **iPtrPtr;
	unsigned short int *siPtr;
	void *vPtr;
	i = 3;
	k = 7;
	iPtr = &i;
	kPtr = &k;
	iPtrPtr = &iPtr;
	*kPtr += 2;	// k = k + 2, k = 7 + 2 = 9

	// i = 3 initial value didn't changed
	// k = 9 #Line 16
	// *iPtr refers to the value stored at the address of i -> 3
	// *kPtr refers to the value stored at the address of k -> 9
	// **iPtrPtr: follow the address stored iPtrPtr
	//    to get the address of i
	//    and then fetch the value stored there which is i -> 3
	printf("a) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);

	// dereference then increment.
	(*iPtr)++; // Updates the value of i-> i = i+1 = 3+1 = 4

	// iPtrPtr holds the address of iPtr
	*iPtrPtr = kPtr; // rewrites the address stored in iPtr to points to kPtr

	// iPtr now points to k. therefor i will updated
	i += *iPtr; // i = i + k = 4 + 9 = 13

	// dereferening takes priority over arithmetics
	--(*kPtr); // kPtr -> k. k = k-1 = 9-1 = 8

	kPtr = &i; // kPtr now points to i
	// kPtr and iPtr have be swapped their initial values


	// i = 13.	#Line35
	// k = 8		#Line38
	// iPtr now points to k -> *iPtr = 8
	// kPtr now points to i -> *kPtr = 13
	// iPtrPtr still points to iPtr but iPtr points to k -> **iPtrPtr = 8
	printf("b) i=%d, k=%d, *iPtr=%d, *kPtr=%d, **iPtrPtr=%d \n",
			 i, k, *iPtr, *kPtr, **iPtrPtr);
}
```

# Aufgabe 4: Iteration und Rekursion

Schreiben Sie eine iterative und rekursive Programmlösung in C, um eine Zeichenkette
rückwärts auf dem Bildschirm auszugeben. Achten Sie darauf, dass die beiden Funktione
bei leeren Zeichenketten `""` der Länge O nicht abstürzen.
Das Hauptprogramm Wird wie folgt aufgerufen:

```CMD
reverseString.exe "alle bananen anabelia"
```

```c
#include <stdio.h>
#include <string.h>
// iterative Lösung
void reverse_i(
{

}
// rekursive Lösung
void reverse_r(
{

}
```

### LOE:

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// iterative Lösung
void reverse_i(char input[]){

	int n = strlen(input); // when n = 0 loop won't run

	char *b = input + n - 1;

	while (n--)   putchar(*b--);
}

// rekursive Lösung
void reverse_r(char input[])
{
	if (*input == '\0')  return;

	reverse_r(input+1);

	putchar(*input);
}

int main (int argc, char *arg[]){

	if (argc < 2) // first argument is the executable path
	{
		printf("\n\tA COMMAND LINE ARGUMENT is REQUIRED\n\n");
		// in case there wasn't user input
		exit(1); // from stdlib.h
	}

	char *input = arg[1];

	printf("%s\n", input);

	reverse_i(input);
	putchar('\n');

	reverse_r(input);
	putchar('\n');

	return 0;
}

```

# Aufgabe 5: Strukturen

Es soll der Fuhrpark eines Unternehmens mit einer dynamischen Liste verwaltet werden.
Zu jedem Fahrzeug Wird der Typ (100 Inhaltszeichen), das Kennzeichen (15 Inhaltszeichen), ein Status sowie ein Zeiger auf das folgende Listenelement in einer Struktur abgelegt werden.

Definieren Sie die genau passende Struktur `s_kfz` sowie den passenden Startpointer (Anker). Orientieren Sie sich dabei an den Informationen der anderen Teilaufgaben.
Für den Status der KFZ soll ein Datentyp mit den Werten `ausgeliehen`, `verfuegbar` und `in_reparatur` angelegt werden.

```c
enum statusDT {
	ausgeliehen,
	verfuegbar,
	in_reparatur
};

struct s_kfz{
	char Typ[100];
	char Kennzeichen[15];
	enum statusDT status;
	struct s_kfz *next;
};

struct s_kfz *first = NULL;
```

## b) Die Funktion `neues_kfz( )` erzeugt ein neues Fahrzeug. Ergänzen Sie fehlendenCode.

```c
struct s_kfz *neues_kfz(char typ[], char kennzeichen[], enum statusDT status)
{
	struct s_kfz *neues_kfz;
	// hier fehlenden Code eintragen
	neues_kfz->status = status;
	neues_kfz->next = NULL;
	return neues_kfz;
}
```

### LOE:

```c

struct s_kfz *neues_kfz(char typ[], char kennzeichen[], enum statusDT status)
{
	struct s_kfz *neues_kfz;
	neues_kfz = malloc(sizeof(struct s_kfz));
	if (neues_kfz == NULL) return NULL;
	strcpy(neues_kfz->typ, typ);
	strcpy(neues_kfz->kennzeichen, kennzeichen);
	neues_kfz->status = status;
	neues_kfz->next = NULL;
	return neues_kfz;
}
```

## c) Schreiben Sie eine Funktion `einfuegen( )` , die ein KFZ vorne in die Liste einfügt. Verwenden Sie die Funktion `neues_kfz( )` aus Teilaufgabe b).

```c
void einfuegen(char typ[], char kennzeichen[], enum statusDT status)
{
}
```

### LOE:

```c
void einfuegen(char typ[], char kennzeichen[], enum statusDT status)
{
	struct s_kfz *node = neues_kfz(typ, kennzeichen, status);

	if (first == NULL) {
		first = node;
		return;
	}

	struct s_kfz *n;

	for(n = first; n->next != NULL; n = n->next);

	n->next = node;
}
```

## d) Schreiben Sie eine Funktion `print_verfuegbar( )` , die eine Liste der nicht verliehenen Fahrzeuge mit Typ, Kennzeichen und Status in Textform ausgibt.

```c
void print_verfuegbar()
{
struct s_kfz * ptr = first;
printf("Nicht verfügbare Fahrzeuge sind:\n");
}
```


### LOE:

```c
void print_node(struct s_kfz *node){
	printf("Typ: %s\n", node->typ);
	printf("Kennzeichen: %s\n", node->kennzeichen);

	printf("Status: ");
	switch (node->status){
	case ausgeliehen:
		printf("ausgeliehen");
		break;
	case verfuegbar:
		printf("verfuegbar");
		break;
	case in_reparatur:
		printf("in_reparatur");
		break;
	default:
		printf("UNBEKANNT");
	}
	printf("\n\n");
}

void print_verfuegbar(){
	struct s_kfz *ptr;
	printf("Nicht verfügbare Fahrzeuge sind:\n");

	for (ptr = first; ptr != NULL; ptr = ptr->next){
		if (ptr->status == verfuegbar){
			print_node(ptr);
		}
	}
}
```

## A5:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum statusDT
{
	ausgeliehen,
	verfuegbar,
	in_reparatur
};

struct s_kfz
{
	char typ[100];
	char kennzeichen[15];
	enum statusDT status;
	struct s_kfz *next;
};

struct s_kfz *first = NULL;

struct s_kfz *neues_kfz(char typ[], char kennzeichen[], enum statusDT status)
{
	struct s_kfz *neues_kfz;
	neues_kfz = malloc(sizeof(struct s_kfz));
	if (neues_kfz == NULL) return NULL;
	strcpy(neues_kfz->typ, typ);
	strcpy(neues_kfz->kennzeichen, kennzeichen);
	neues_kfz->status = status;
	neues_kfz->next = NULL;
	return neues_kfz;
}

void einfuegen(char typ[], char kennzeichen[], enum statusDT status)
{
	struct s_kfz *node = neues_kfz(typ, kennzeichen, status);

	if (first == NULL) {
		first = node;
		return;
	}

	struct s_kfz *n;

	for(n = first; n->next != NULL; n = n->next);

	n->next = node;
}

void print_node(struct s_kfz *node){
	printf("Typ: %s\n", node->typ);
	printf("Kennzeichen: %s\n", node->kennzeichen);

	printf("Status: ");
	switch (node->status){
	case ausgeliehen:
		printf("ausgeliehen");
		break;
	case verfuegbar:
		printf("verfuegbar");
		break;
	case in_reparatur:
		printf("in_reparatur");
		break;
	default:
		printf("UNBEKANNT");
	}
	printf("\n\n");
}

void print_verfuegbar(){
	struct s_kfz *ptr;
	printf("Nicht verfügbare Fahrzeuge sind:\n");

	for (ptr = first; ptr != NULL; ptr = ptr->next){
		if (ptr->status == verfuegbar){
			print_node(ptr);
		}
	}
}

```