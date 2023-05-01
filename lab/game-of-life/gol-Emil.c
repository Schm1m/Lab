/*Program which lets the user input a n array of ones and zeros                             */
/*and modifies that array according to the ruleset of Conway's "Game of Life" (GoL).        */
/*(https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)                                   */
/*                                                                                          */
/*"#" is considered a living cell while "." is considered a dead cell (in the output)       */
/*"1" is considered a living cell while "0" is considered a dead cell (inside of the code)  */

//                            /|、
//                          (˚ˎ 。7  
//                           |、˜〵          
//                          じしˍ,)ノ (cursive cat)


#include <stdio.h>
#define size 20

int main(void)
{
    int arrin[size][size] = {{0}};
    int arrout[size][size] = {{0}};
    int iterations;

    scanf("%d", &iterations);

    while (1)
    {
        char Input;
        scanf(" %c", &Input);

        /*reads in x and y values of the given living cells with the initialization "a"*/
        if (Input == 'a')
        {
            int x, y;

            scanf("%d %d", &x, &y);

            arrin[y][x] = 1;
        }
        else
            break;
    }

    for (int gen = 0; gen < iterations; gen++)
    {
        printf("-- Generation: %d\n", gen);

        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                printf("%c", arrin[row][col] == 1 ? '#' : '.'); // prints "#" for a living cell (1) and "." for a dead cell (0)

                int neighbours = 0;

                /*evolution of the cell*/
                for (int k = -1; k < 2; k++) // k and l used as a 3x3 grid with the observed cell in the center
                {
                    for (int l = -1; l < 2; l++)
                    {
                        if (!(l == 0 && k == 0) && row + k < size && // this "if" only adds to the neighbour count when the neighbouring cell is visible (on the array)
                            row + k >= 0 &&
                            col + l < size &&
                            col + l >= 0 && arrin[row + k][col + l] == 1)
                        {
                            neighbours++;
                        }

                        if (arrin[row][col] == 1 && (neighbours == 2 || neighbours == 3)) // living cell with 2 or 3 living neighbours stays alive
                        {
                            arrout[row][col] = 1;
                        }
                        else if (arrin[row][col] == 0 && neighbours == 3) // dead cell with 3 living neighbours gets ressurected
                        {
                            arrout[row][col] = 1;
                        }
                        else // everything else says dead/dies
                        {
                            arrout[row][col] = 0;
                        }
                    }
                }
            }
            printf("\n");
        }

        /*input array overwritten for the next generation*/
        for (int m = 0; m < size; m++)
        {
            for (int n = 0; n < size; n++)
            {
                arrin[m][n] = arrout[m][n];
            }
        }
    }

    return 0;
}
