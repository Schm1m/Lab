#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* initializing two integers
     * C90 style, also the i int */

    unsigned int n;

    printf("\n");
    printf("Geben Sie bitte eine Note (1-5) ein: \n");

    while (1) {

        scanf("%u", &n);

        /* condition check */

        if (n >= 1 && n <= 5) {

            /* classic switch case with a default*/

            switch (n) {
                case 1:
                case 2:
                case 3:
                case 4:
                    printf("OK!");
                    break;
                case 5:
                    printf("NICHT bestanden");
                    break;
                    /* "error handling" */
                default:
                    break;
            }

            break;

        } else {

            printf("Geben Sie bitte eine Note (1-5) ein: \n");

        }

    }

    return 0;
}