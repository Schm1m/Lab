#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    /* variables */
    unsigned int MARK;

    /* printing and scanning */
    printf("Geben Sie bitte eine Note (1-5) ein:\n");
    scanf("%u", &MARK);

    /* switch case, checking MARK
     * cases 1 - 4 are a pass
     * case 5 and the default are fail
     * only using two breaks!!! should be good. */
    switch (MARK) {
        case 1:
        case 2:
        case 3:
        case 4:
            printf("OK!");
            break;
        case 5:
        default:
            printf("NICHT bestanden");
            break;

    }

    return 0;
}
