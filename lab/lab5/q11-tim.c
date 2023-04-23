// cody by tim, L5Q11

#include <stdio.h>
int main() {
    int value = 42;
    int *pointer = &value;  // set pointer as pointer of value

    printf("%d\n", *pointer);
    *pointer = 85;
    printf("%d\n", *pointer);
    (*pointer)++;
    printf("%d\n", *pointer);
    return 0;
}
