/* ඞ */

/*
 * LOADING THE NEEDED LIBRARY FILES FOR THIS QUIZ
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * STRUCTURE OF THE CUSTOMER
 *
 * - customerIndex is a ID (1,2,3,...)
 * - customerFirstName is a string ("LIGMA", "NICE", "BLAZE IT")
 * - customerLastName is a string ("AMUNGGG", "US")
 * - *anotherCustomer is a structure and a recursive element (like the 'cdr')
 */
typedef struct customer {

  int customerIndex;
  char customerFirstName[69];
  char customerLastName[420];
  struct customer *anotherCustomer;

} customer;

/*
 * CUSTOMER ADD, THIS IS JUST PUSHING A NEW LIST / NODE PART
 */
customer *addCustomer(customer *carCustomer, customer *cdrCustomer) {

  if (carCustomer == NULL) {
    return cdrCustomer;
  }

  customer *current = carCustomer;

  while (current->anotherCustomer != NULL) {

    current = current->anotherCustomer;
  }

  current->anotherCustomer = cdrCustomer;

  return carCustomer;
}

/*
 * SORTING ALGORITHM FOR THE LINKED LIST BASED ON THE ID
 */
void sortNodesByIndex(customer *carCustomer) {

  if (carCustomer == NULL) {
    return;
  }

  customer *index;
  customer *previous = NULL;
  customer *current = carCustomer;
  customer *tmp;

  while (current != NULL) {

    index = current->anotherCustomer;

    while (index != NULL) {

      if (current->customerIndex > index->customerIndex) {

        if (previous != NULL) {

          previous->anotherCustomer = index;

        } else {

          carCustomer = index;
        }

        tmp = index->anotherCustomer;
        index->anotherCustomer = current;
        index = current->anotherCustomer;
        current->anotherCustomer = tmp;
        current = index;
        continue;
      }

      index = index->anotherCustomer;
    }

    previous = current;
    current = current->anotherCustomer;
  }
}

/*
 * THIS WILL CREATE THE FIRST CHARACTER,
 * ABSOLUTE SHIT WAY OF DOING IT, WHAT THE HELL IS THIS LAB...
 */
customer *createCustomer(int index, const char *firstName,
                         const char *lastName) {

  customer *newCustomer = (customer *)malloc(sizeof(customer));

  if (newCustomer == NULL) {

    exit(-1);
  }

  newCustomer->customerIndex = index;
  strcpy(newCustomer->customerFirstName, firstName);
  strcpy(newCustomer->customerLastName, lastName);

  newCustomer->anotherCustomer = NULL;

  return newCustomer;
}

/*
 * FUNCTION WHICH WILL CLEAR THE LIST
 */
void clearList(customer *carCustomer) {

  customer *root = carCustomer;
  customer *nextLeaf;

  while (root != NULL) {

    nextLeaf = root->anotherCustomer;
    free(root);
    root = nextLeaf;
  }

  carCustomer = NULL;
}

/*
 * COUNTING, WOOO
 * TBH. JUST COUNTING.
 */
int customerCount(customer *carCustomer) {
  int count = 0;

  while (carCustomer != NULL) {
    count++;
    carCustomer = carCustomer->anotherCustomer;
  }

  return count;
}

/*
 * THE PRINT FUNCTION
 * IT'LL PRINT, MUCH WOW...
 */
void printList(customer *carCustomer) {

  /*
   * SO, IT WAS MY ERROR, STILL A SHIT LAB.
   * SORTING IS NEEDED...
   */
  sortNodesByIndex(carCustomer);
  while (carCustomer != NULL) {

    printf("%u: %s %s\n", carCustomer->customerIndex,
           carCustomer->customerFirstName, carCustomer->customerLastName);
    carCustomer = carCustomer->anotherCustomer;
  }
}

/*
 * THE MAIN FUNCTION
 * JUST COPY AND PASTED HERE, NOT EVEN FORMATTED / SPACED CORRECTLY
 */
int main(int argc, char *argv[]) {
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
