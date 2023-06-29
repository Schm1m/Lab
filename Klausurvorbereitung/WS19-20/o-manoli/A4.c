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

