// cody by tim, L8Q3

#include <stdio.h>

int faculty(int);  // function prototype

int main(int argc, char *argv[]) {
    int i;                              // initiate i
    scanf("%d", &i);                    // take input for i
    printf("%d! = %d", i, faculty(i));  // print factorial of i
}

int faculty(int n) {
    return n == 1 ? n : n * faculty(n - 1);  // re-initiate function untill n reaches 1
}
