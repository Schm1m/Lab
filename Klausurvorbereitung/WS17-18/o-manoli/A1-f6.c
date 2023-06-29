#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList
{
	char Buffer[64];
	struct LinkedList *next;
} Linked;

Linked *createNode(char *Buffer)
{
	Linked *n = malloc(sizeof(Linked));

	if (n == NULL) return NULL;

	strcpy(n->Buffer, Buffer);

	return n;
}

void append(Linked *root, char *Buffer)
{

	if (root == NULL) return;

	while (root->next != NULL) root = root->next;

	root->next = createNode(Buffer);
}

int main(void)
{
	Linked *Root = createNode("Hello");
	append(Root, "World!");
	append(Root, ":)");
	append(Root, "):");
	append(Root, ". .");
	append(Root, " - ");

	Linked *X;

	printf("Trying it with a FOR-LOOP:\n\n");

	X = Root;

	for (; X;) // same as `X != NULL`
	{
		printf("%s\n", X->Buffer);
		X = X->next;
	}

	printf("\n- - - - - - - - - - - -\n");

	printf("Trying it with a While-LOOP:\n\n");

	X = Root;

	while (X) // same as `X != NULL`
	{
		printf("%s\n", X->Buffer);
		X = X->next;
	}

	return 0;
}
