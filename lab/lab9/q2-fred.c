#include <stdio.h>
#include <string.h>

struct customerData {

  /* dirty way of hard-coding the array size */
  unsigned int customerNumber;
  char customerFirstName[69];
  char customerLastName[420];
};

/* not pretty */
int main(int argc, char *argv[]) {

  struct customerData customerOne;
  customerOne.customerNumber = 1;
  strcpy(customerOne.customerFirstName, "Hans");
  strcpy(customerOne.customerLastName, "Maurer");

  struct customerData customerTwo;
  scanf("%u", &customerTwo.customerNumber);
  scanf("%s", customerTwo.customerFirstName);
  scanf("%s", customerTwo.customerLastName);

  printf("%u: %s %s", customerOne.customerNumber, customerOne.customerFirstName,
         customerOne.customerLastName);
  printf("\n");
  printf("%u: %s %s", customerTwo.customerNumber, customerTwo.customerFirstName,
         customerTwo.customerLastName);

  return 0;
}
