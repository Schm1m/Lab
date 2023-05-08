// cody by tim, L8Q2
#include <stdio.h>
int potenz_rekursive();  // function prototype

int main(int argc, char *argv[]) {
    int inputA, inputB, inputN;                                // initiate vars
    scanf("%d %d %d", &inputA, &inputB, &inputN);              // get vars
    printf("%d\n", potenz_rekursive(inputA, inputB, inputN));  // print calculation
}

int potenz_rekursive(int a, int b, int n) {
    int brackets = a + b;
    return n == 0 ? 1 : brackets * potenz_rekursive(a, b, n - 1);  // recursively calculate it, untill n reaches 0
}