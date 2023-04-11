#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

    /* variables */
    int i, x, y;

    /* scanning 🥶 */
    scanf("%d", &x);
    scanf("%d", &y);

    i = 1;
    while (i <= 200) {

        if (i % x == 0 && i % y != 0) {

            printf("fizz\n");

            /* super terse code, we love it. */
        } else
            i % y == 0 && i % x != 0 ? printf("buzz\n") : i % x == 0 && i % y == 0 ? printf("fizzbuzz\n") : printf(
                    "%d\n", i);

        i++;

    }

    return 0;

    /* we love steve! */

}