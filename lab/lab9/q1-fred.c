#include <stdio.h>

/* definition of the structure */
struct fraction {

  double upper; /* numerator */
  double lower; /* denominator */
};

/* - - - */

/* implementation of division */
struct fraction division(struct fraction fractionOne,
                         struct fraction fractionTwo) {

  struct fraction result;

  result.upper = fractionOne.upper * fractionTwo.lower;
  result.lower = fractionOne.lower * fractionTwo.upper;

  return result;
}

/* implementation of multiplication */
struct fraction multiplication(struct fraction fractionOne,
                               struct fraction fractionTwo) {

  struct fraction result;

  result.upper = fractionOne.upper * fractionTwo.upper;
  result.lower = fractionOne.lower * fractionTwo.lower;

  return result;
}

/* simple printing statement and abusing the "C" printf statement */
void printing(struct fraction result) {

  printf("(%.1lf/%.1lf)", result.upper, result.lower);
}

/* the main function, calling the sub-functions */
int main(int argc, char *argv[]) {

  struct fraction inputOne;
  struct fraction inputTwo;

  scanf("%lf %*c %lf", &inputOne.upper, &inputOne.lower);
  scanf("%lf %*c %lf", &inputTwo.upper, &inputTwo.lower);

  printf("(%.1lf/%.1lf)*(%.1lf/%.1lf)=", inputOne.upper, inputOne.lower,
         inputTwo.upper, inputTwo.lower);
  printing(multiplication(inputOne, inputTwo));

  printf("\n");

  printf("(%.1lf/%.1lf)/(%.1lf/%.1lf)=", inputOne.upper, inputOne.lower,
         inputTwo.upper, inputTwo.lower);
  printing(division(inputOne, inputTwo));

  return 0;
}
