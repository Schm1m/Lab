#include <stdio.h>
#include <malloc.h>

typedef struct numberItem // has two pointers to indicate doubly linked list
{
    struct numberItem *prev;
    int num;
    struct numberItem *next;

} numberItem;

numberItem *append(numberItem *curnode, int number)
{
    numberItem *newnode = malloc(sizeof(numberItem)); // new node mem alloc

    newnode->prev = NULL;
    newnode->num = number; // new node gets created with NULL pointers in both directions and a number as a value
    newnode->next = NULL;

    if (curnode != NULL) // for when the new node isn't the first node of the list
    {
        numberItem *temp = curnode->next; // temp becomes the pointer to the next node
        curnode->next = newnode;          // the new node gets attatched behind the current node
        newnode->prev = curnode;          // the current node gets attatched in front of the new node
        newnode->next = temp;             // temp now gets attatched behind of the new node
    }

    return newnode;
}

void print(numberItem *curnode)
{
    numberItem *temp = curnode;

    while (temp != NULL) // goes through the list until the last entry is reached and prints out each entry
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
}

numberItem *first(numberItem *curnode)
{
    numberItem *temp = curnode;

    while (temp->prev != NULL)
    {
        temp = temp->prev; // goes through the list "backwards"
    }
    return temp;
}

numberItem *last(numberItem *curnode)
{
    numberItem *temp = curnode;

    while (temp->next != NULL)
    {
        temp = temp->next; // goes through the list "forwards"
    }
    return temp;
}

int main(void)
{
    numberItem *item = NULL;
    item = append(item, 42);
    item = append(item, 1);

    item = first(item);
    item = append(item, 3);
    item = append(item, 4);

    item = last(item);
    item = append(item, 99);

    item = first(item);
    print(item);
}
