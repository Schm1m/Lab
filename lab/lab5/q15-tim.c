// cody by tim, L5Q14

#include <stdio.h>

int main(void) {
    int i;                 // define int i
    int *ptr;              // define pointer ptr as int
    int **ptrptr;          // define pointer ptrptr as pointer to pointer
    ptr = &i;              // assign adress of i to ptr
    ptrptr = &ptr;         // assign adress of ptr to ptrptr
    i = 1;                 // define i as 1
    printf("%d\n", i);     // return i
    printf("%d\n", *ptr);  // return ptr, which is i
    **ptrptr = 2;          // set ptrptr to 2, which is ptr, which is i
    printf("%d\n", i);     // return i
    return 0;
}
