// cody by tim, L8Q3

#include <stdio.h>

int faculty(int);  // function prototype
int input(void);   // -

int main(int argc, char *argv[]) {
    printf("%d! = %d", i, faculty(input()));  // print factorial of i
}

int faculty(int n) {
    return n == 1 ? n : n * faculty(n - 1);  // re-initiate function untill n reaches 1
}

int input(void) {
    int i;            // initiate i
    scanf("%d", &i);  // take input for i
    return i;
}
