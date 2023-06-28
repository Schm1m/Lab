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

