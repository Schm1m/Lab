/* https://youtu.be/obmL8N3_2-0 */

#include <malloc.h>
#include <stdio.h>

typedef struct numberItem {

  struct numberItem *previousItem;
  int value;
  struct numberItem *nextItem;

} numberItem;

numberItem *append(numberItem *head, int input) {

  numberItem *newItem = malloc(sizeof(numberItem));

  newItem->previousItem = NULL;
  newItem->value = input;
  newItem->nextItem = NULL;

  if (head != NULL) {

    numberItem *temporary = head->nextItem;
    head->nextItem = newItem;
    newItem->previousItem = head;
    newItem->nextItem = temporary;
  }

  return newItem;
}

numberItem *first(numberItem *head) {

  numberItem *car = head;

  while (car->previousItem != NULL) {
    car = car->previousItem;
  }

  return car;
}

numberItem *last(numberItem *head) {

  numberItem *car = head;

  while (car->nextItem != NULL) {

    car = car->nextItem;
  }

  return car;
}

void print(numberItem *head) {

  numberItem *car = head;

  while (car != NULL) {

    printf("%d ", car->value);
    car = car->nextItem;
  }
}

int main() {

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
