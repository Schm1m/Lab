// cody by tim, Game-of-Life
// possibly the most fucked up code i´ve ever written

#include <stdio.h>
#define fieldsize 20  // size of playable field

void printArray(int[][fieldsize]);                             // printArray prototype
int neighbours(unsigned int, unsigned int, int[][fieldsize]);  // neighbours prototype

int main(void) {
    int gens;
    int field[fieldsize][fieldsize] = {{0}};
    int tempfield[fieldsize][fieldsize] = {{0}};
    unsigned int posx, posy;
    /* define number of generations, the field,     *
     * a copy of the field an the psoition integers */

    scanf("%d", &gens);  // get the number of generations
    while (1) {
        char end;
        scanf(" %c", &end);
        if (end == 'a') {  // set the given point as alive in the field
            scanf("%u %u", &posy, &posx);
            field[posx][posy] = 1;
        } else {  // break the infinite while, if the submitted char was not an 'a'
            break;
        }
    }
    for (int i = 0; i <= gens; i++) {      // run for the amount of generations given
        printf("-- Generation: %d\n", i);  // print a short info
        printArray(field);                 // and the whole field
        for (int g = 0; g < fieldsize; g++) {
            for (int h = 0; h < fieldsize; h++) {  // iterate through all field positions and save cell states in copy of field
                int nbs;
                nbs = neighbours(g, h, field);       // calculate all neighbours
                if (field[g][h] == 0 && nbs == 3) {  // revive cell if its dead AND has 3 neighbours
                    // revive
                    tempfield[g][h] = 1;
                } else if (field[g][h] == 1) {
                    switch (nbs) {
                        case 2:
                        case 3:
                            // stays alive
                            tempfield[g][h] = 1;  // keep cell alive if it has 2 or 3 neighbours
                            break;
                        default:
                            // dies
                            tempfield[g][h] = 0;  // kill cell if it does NOT have 2 or 3 neighbours
                            break;
                    }
                }
            }
        }
        for (int a = 0; a < fieldsize; a++) {
            for (int b = 0; b < fieldsize; b++) {
                field[a][b] = tempfield[a][b];  // overrite every position of the field with the new cell states
            }
        }
    }
    return 0;
}

/* printArray() prints every position of the array       *
 * if the value on the position is 0 it prints "."       *
 * if the value on the position is 1 it prints "#"       *
 * also a new line after the lenght of the array         *
 * to be able to see it in a 2 dimensional way instead   *
 * of every position in one line                         */

void printArray(int array[][fieldsize]) {
    for (int i = 0; i < fieldsize; i++) {
        for (int j = 0; j < fieldsize; j++) {
            array[i][j] == 0 ? printf(".") : printf("#");
            // printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
/* neighbours() calculates the number of neighbours     *
 * that are alive, by adding up the state of all cells  *
 * around it. if the position of the neighbour does not *
 * does not exist, it will simply skip the position     */

int neighbours(unsigned int x, unsigned int y, int array[][fieldsize]) {
    int nb = 0;
    if (x != 0 && y != 0) {
        nb += array[x - 1][y - 1];
    }
    if (y != 0) {
        nb += array[x][y - 1];
    }
    if (x != (fieldsize - 1) && y != 0) {
        nb += array[x + 1][y - 1];
    }
    if (x != 0) {
        nb += array[x - 1][y];
    }
    if (x != (fieldsize - 1)) {
        nb += array[x + 1][y];
    }
    if (x != 0 && y != (fieldsize - 1)) {
        nb += array[x - 1][y + 1];
    }
    if (y != (fieldsize - 1)) {
        nb += array[x][y + 1];
    }
    if (x != (fieldsize - 1) && y != (fieldsize - 1)) {
        nb += array[x + 1][y + 1];
    }
    return nb;
}