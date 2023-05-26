/*
	Author: Manoli Owes
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// LinkedList Implementation

typedef struct customer
{
	int ID; // Identification NUmber
	char first_name[16];
	char last_name[16];
	struct customer *Next;
} customer;

// ----------------------

// Modifying the LinkedList

void clearList(customer *R)
{
	customer *Tmp; // Temporary Variable
	while (R)
	{
		Tmp = R->Next; // holds next until R is freed
		free(R);
		R = Tmp;
	}
}

void printList(customer *R)
{
	while (R)
	{
		printf("%d: %s %s\n", R->ID, R->first_name, R->last_name);
		R = R->Next;
	}
}

int customerCount(customer *R)
{ // start count with R
	int headcount = 0;
	while (R) // as long as R points somewhere
	{
		headcount++;
		R = R->Next; // reassign R to the node down the tree
	}
	return headcount;
}

void addCustomer(customer *R, customer *N)
{ // adds N list starting with R
	// compare the ID to insert before to keep the IDs sorted
	// R i surely not NULL!
	while (R->Next) // as long as R has a Next
	{
		if (N->ID < R->Next->ID) // append before R->Next
		{
			N->Next = R->Next;
			R->Next = N;
			return;
		}
		R = R->Next; // look for the node that doesn't
	}
	R->Next = N; // append after R->Next
}

customer *createCustomer(int ID, char *first_name, char *last_name)
{ // persistent storage
	customer *N = malloc(sizeof(customer));
	// Copying values
	N->ID = ID;
	strcpy(N->first_name, first_name);
	strcpy(N->last_name, last_name);
	N->Next = NULL;
	return N;
}

// ---------

int main(int argc, char *argv[])
{
	customer *root = NULL;
	root = createCustomer(1, "Hans", "Maurer");
	addCustomer(root, createCustomer(3, "Tatjana", "Roth"));
	addCustomer(root, createCustomer(2, "Anna-Maria", "Schmidt"));
	printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
	printList(root);
	clearList(root);
	root = NULL;

	printf("Momentan sind %u Kunden erfasst.\n", customerCount(root));
	printList(root);
	return 0;
}
