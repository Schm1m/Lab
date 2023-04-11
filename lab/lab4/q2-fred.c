#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* initializing new counter and i for loop */
    int count = 0, i = 0;
    char input[40];

    /* using fgets, because scanf was giving me
     * a lovely buffer overflow. love it, fgets
     * seems good and build for stuff like this */
    fgets(input, sizeof(input), stdin);

    /* checking for the ending char, technically not
     * safe and good to do this, but who cares... */
    while (input[i] != '\0') {

        if (input[i] >= 'a' && input[i] <= 'z') {

            count++;

        }

        i++;

    }

    printf("%d Kleinbuchstaben", count);

    return 0;

}