// cody by tim, L9Q5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    int cId;                        // customer id, starting at 1
    char cSurname[13];              // customers surname
    char cLastname[37];             // customers lastname
    struct customer *nextCustomer;  // next customer item
} customer;

customer *addCustomer(customer *, customer *);              // function prototypes
void sort(customer *);                                      //
customer *createCustomer(int, const char *, const char *);  //
void clearList(customer *);                                 //
int customerCount(customer *);                              //
void printList(customer *);                                 //

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

customer *addCustomer(customer *a, customer *b) {  // add a customer to the list
    if (a == NULL) {
        return b;
    }

    customer *current = a;

    while (current->nextCustomer != NULL) {
        current = current->nextCustomer;
    }
    current->nextCustomer = b;

    return a;
}

void sort(customer *a) {  // sort customers by their id´s
    if (a == NULL) return;

    customer *num;
    customer *prev = NULL;
    customer *curr = a;
    customer *b;

    while (curr != NULL) {
        num = curr->nextCustomer;
        while (num != NULL) {
            if (curr->cId > num->cId) {
                if (prev != NULL) {
                    prev->nextCustomer = num;
                } else {
                    a = num;
                }
                b = num->nextCustomer;
                num->nextCustomer = curr;
                num = curr->nextCustomer;
                curr->nextCustomer = b;
                curr = num;
            } else {
                num = num->nextCustomer;
            }
        }
        prev = curr;
        curr = curr->nextCustomer;
    }
}

customer *createCustomer(int i, const char *first, const char *last) {  // create a new customer
    customer *new = (customer *)malloc(sizeof(customer));

    if (new == NULL) exit(-1);

    new->cId = i;
    strcpy(new->cSurname, first);
    strcpy(new->cLastname, last);

    new->nextCustomer = NULL;

    return new;
}

void clearList(customer *a) {  // clear the list of customers
    customer *root = a;
    customer *next;

    while (root != NULL) {
        next = root->nextCustomer;
        free(root);
        root = next;
    }
    a = NULL;
}

int customerCount(customer *a) {  // get the count of stored customers
    int i = 0;
    while (a != NULL) {
        i++;
        a = a->nextCustomer;
    }
    return i;
}

void printList(customer *a) {  // print out all customers
    sort(a);
    while (a != NULL) {
        printf("%u: %s %s\n", a->cId, a->cSurname, a->cLastname);
        a = a->nextCustomer;
    }
}
