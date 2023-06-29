#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int year;
	int month;
	int day;
} date;

struct s_Fridge
{
	char Product[50];
	char Name[50];
	date Ablauf;
	struct s_Fridge *next;
};

struct s_Fridge *first = NULL;

struct s_Fridge *new_entry(char Product[], char Name[], date ablauf)
{
	struct s_Fridge *ptr;

	ptr = (struct s_Fridge *)malloc(sizeof(struct s_Fridge));

	if (ptr == NULL)
		return NULL;

	strcpy(ptr->Product, Product);
	strcpy(ptr->Name, Name);
	ptr->Ablauf.day = ablauf.day;
	ptr->Ablauf.month = ablauf.month;
	ptr->Ablauf.year = ablauf.year;
	ptr->next = NULL;

	return ptr;
}

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

void print(struct s_Fridge *node)
{
	printf("\nProduktdetails: %s\n", node->Product);
	printf("Produktname: %s\n", node->Name);
	printf("Ablaufdatum: %d-%02d-%02d\n\n",
			 node->Ablauf.year, node->Ablauf.month, node->Ablauf.day);
}

void print_all()
{
	struct s_Fridge *node = first;

	while (node)
	{
		print(node);
		node = node->next;
	}
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
		print(ptr); // including today
	}
}

int main()
{
	insert("Mai", "P1", (date){1996, 5, 23});
	insert("Juni", "P1", (date){2023, 6, 23});
	insert("Juni", "P2", (date){2023, 6, 1});
	insert("July", "P3", (date){2024, 8, 23});
	insert("August", "P4", (date){2027, 7, 23});

	print_all();

	printf("-------------\n");

	print_abgelaufen((date){2023, 6, 23});

	return 0;
}
