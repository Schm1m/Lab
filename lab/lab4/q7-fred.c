#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    int i = 0, j, k = 0;

    char input[40];
    char output[40];
    scanf("%s", input);

    /* length check :D */
    while (input[k] != '\0') {
        k++;
    }

    /* not the escape character */
    j = k - 1;

    for (i = 0; i < k; i++) {
        output[i] = input[j];
        j--;
    }

    printf("%s", output);

    return 0;

}