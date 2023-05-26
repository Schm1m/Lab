// cody by tim, L8Q1

#include <stdio.h>

int potenz_iter(int, int, int); // funct. prototype

int main(int argc, char *argv[]) {
    int inputA, inputB, inputN; // initiate vars
    scanf("%d %d %d", &inputA, &inputB, &inputN); // get vars
    printf("%d\n", potenz_iter(inputA, inputB, inputN)); // print calculation
}

int potenz_iter(int a, int b, int n) {
    int retVal = 1; // initiate as 1 (x^0 is always 1)
    int brackets = a + b; // simplify the calculation afterwards
    for(int i = 0; i < n; i++) {
        retVal *= brackets; // multiply retVal by brackets for each iteration
    }
    return retVal; // return retVal
}