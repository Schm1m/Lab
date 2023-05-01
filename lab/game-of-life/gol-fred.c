#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
 * the game of life
 * see: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 */

/* GLOBAL DEFINITIONS */
#define SIZE 20

int main(int argc, char *argv[]) {

    /* matrix for the game & copy of the matrix */
    char matrix[SIZE][SIZE] = {0};
    char matrixCopy[SIZE][SIZE] = {0};

    /* the input of generations to generate */
    unsigned int generations;

    scanf("%u", &generations);

    while (1) {

        char characterInput;
        scanf(" %c", &characterInput);

        if (characterInput == 'a') {

            /* the 2D matrix coordination */
            int i;
            int j;

            scanf("%d %d", &i, &j);

            matrix[j][i] = 1;

        } else break;

    }

    /* CALC & PRINTING THE GENERATIONS */
    int i;
    i = 0;

    while (i <= generations) {

        /* PRINTING FOR TESTS */
        printf("-- Generation: %d\n", i);

        for (int k = 0; k < SIZE; k++) {

            for (int l = 0; l < SIZE; l++) {

                /* NEXT GENERATION | ALIVE OR DEAD */
                printf("%c", matrix[k][l] == 1 ? '#' : '.');

                /* COUNTING THE NEIGHBOURS */
                int neighbors;
                neighbors = 0;

                int m;
                m = -1;
                while (m < 2) {

                    int n;
                    n = -1;
                    while (n < 2) {

                        /* CHECKING NEIGHBOURS FOR MATRIX[K][L] */
                        if (!(n == 0 && m == 0) && k + m < SIZE &&
                            k + m >= 0 &&
                            l + n < SIZE &&
                            l + n >= 0 && matrix[k + m][l + n] == 1) {

                            neighbors++;

                        }

                        n++;

                    }

                    m++;

                }

                /* RULES INPUT */

                if (matrix[k][l] == 1 && (neighbors == 2 || neighbors == 3)) {

                    matrixCopy[k][l] = 1;

                } else {

                    if (matrix[k][l] == 0 && neighbors == 3) {

                        matrixCopy[k][l] = 1;

                    } else {

                        if (matrix[k][l] == 1) {

                            matrixCopy[k][l] = 0;

                        }

                    }

                }

            }

            printf("\n");

        }

        /* READY FOR NEXT GENERATION */

        int o;
        o = 0;
        while (o < SIZE) {

            int p;
            p = 0;
            while (p < SIZE) {

                matrix[o][p] = matrixCopy[o][p];

                p++;
            }

            o++;
        }

        i++;

    }

    return 0;

}