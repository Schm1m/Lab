// cody by tim, L9Q1

#include <stdio.h>

struct fraction {  // struct for fraction: (dividend/divisor)
    float dividend;
    float divisor;
};

typedef struct fraction fract;  // define type for the struct

void printFraction(fract);  // function prototype

int main(void) {
    int a1, b1, a2, b2;                                             // fraction 1: (a1/b1), fraction 2: (a2/b2)
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);                       // get fractions
    struct fraction frac1 = {a1, b1};                               // define given fractions
    struct fraction frac2 = {a2, b2};                               // ""
    struct fraction multiply = {                                    // calculate fractions for output
                                (frac1.dividend * frac2.dividend),  //
                                (frac1.divisor * frac2.divisor)};   //
    struct fraction divide = {                                      //
                              (frac1.dividend * frac2.divisor),     //
                              (frac1.divisor * frac2.dividend)};    //
    printFraction(frac1);
    putchar('*');
    printFraction(frac2);
    putchar('=');
    printFraction(multiply);
    putchar('\n');
    printFraction(frac1);
    putchar('/');
    printFraction(frac2);
    putchar('=');
    printFraction(divide);
    putchar('\n');
    return 0;
}

void printFraction(fract f) {
    printf("(%0.1f/%0.1f)", f.dividend, f.divisor);  // print fraction with brackets
}
