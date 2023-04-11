#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* initializing the variables */
    int i = 0;
    char input[42]; /* !!! do not use 40, will give a error @last test */

    /* using fgets, like it! */
    fgets(input, sizeof(input), stdin);

    /* condition */
    while (input[i] != '\0') {

        /* like the if, could be done as a switch */
        if (input[i] >= 'a' && input[i] <= 'z') {

            input[i] -= 32;

        } else if (input[i] >= 'A' && input[i] <= 'Z') {

            input[i] += 32;

        }

        i++;

    }

    printf("%s", input);

    return 0;

}