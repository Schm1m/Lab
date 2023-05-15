#include <malloc.h>
#include <stdio.h>

/* structure & type definition
 * - number
 * - anotherOne (another customer)
 * */
typedef struct customer {

  int number;
  struct customer *anotherOne;

} numberItem;

/* appends a new node to the given reference
 * this would be a PP to the head
 * */
void creatCustomer(struct customer **rootReference, int newValue) {

  /* we first allocate the new reference */
  struct customer *newLeaf = (struct customer *)malloc(sizeof(struct customer));

  struct customer *last = *rootReference;

  /* data input*/
  newLeaf->number = newValue;

  /* new node, first NULL */
  newLeaf->anotherOne = NULL;

  /* if input NULL so make the new leaf */
  if (*rootReference == NULL) {
    *rootReference = newLeaf;
    return;
  }

  /* if not, go to last */
  while (last->anotherOne != NULL)
    last = last->anotherOne;

  /* set the last one to the new leaf */
  last->anotherOne = newLeaf;
}

/* this is printing the function, nothing more... */
void printList(struct customer *numberItemInput) {
  while (numberItemInput != NULL) {
    printf("%d\n", numberItemInput->number);
    numberItemInput = numberItemInput->anotherOne;
  }
}

void clearList(struct customer *headReference) {

  /* getting the real head of list */
  struct customer *root = headReference;
  struct customer *nextLeaf;

  /* simple, freeing */
  while (root != NULL) {
    nextLeaf = root->anotherOne;
    free(root);
    root = nextLeaf;
  }

  /* is needed so the headerReference will work with the real header */
  headReference = NULL;
}

int main(int argc, char *argv[]) {

  struct customer *root = NULL;
  creatCustomer(&root, 42);
  creatCustomer(&root, 1);
  creatCustomer(&root, 2);
  creatCustomer(&root, 3);
  printList(root);
  clearList(root);
  return 0;
}
