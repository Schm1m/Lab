// cody by tim, L4Q9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= 200; i++) {
        if ((i % a == 0) && (i % b != 0)) {  // only if a is a multiple of i
            printf("fizz\n");
        } else if ((i % b == 0) && (i % a != 0)) {  // only if b is a multiple of i
            printf("buzz\n");
        } else if ((i % a == 0) && (i % b == 0)) {  // if a and b are multiples of i
            printf("fizzbuzz\n");
        } else {
            printf("%d\n", i);
        }
    }
    return 0;
}
