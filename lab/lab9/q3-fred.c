#include <malloc.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /* size of array */
    int *a;

    /* size of numbers to be sorted */
    unsigned int n;

    /* walking indicator & result holder */
    int i;
    int j;
    int t;

    scanf("%u", &n);

    a = (int *)malloc(n * sizeof(int));

    i = 0;
    while (i <= n - 1) {

        scanf("%d", (a + i));
        i++;
    }

    for (i = 0; i < n; i++) {

        for (j = 0; j <= i; j++) {

            if (*(a + i) < *(a + j)) {

                t = *(a + i);

                *(a + i) = *(a + j);

                *(a + j) = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%3d: %3d", i + 1, *(a + i));
    }

    return 0;
}
