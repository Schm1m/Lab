#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* new variables */
    int i = 0;
    char str[40];
    char vowel;

    /* scanning, yay */
    scanf(" %c %s", &vowel, str);

    while (str[i] != '\0') {

        /* switch case for characters */
        switch (str[i]) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'o':
            case 'U':
            case 'u':
                str[i] = vowel;
                break;
            default:
                break;

        }

        i++;

    }

    printf("%s", str);

    return 0;

}