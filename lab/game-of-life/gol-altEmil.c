/*gol-Emil.c but with subfunctions and a different evolution structure (neigbour check for all cells before evolution)*/
/*gol-Emil.c for more info*/

//                            /|、
//                          (˚ˎ 。7
//                           |、˜〵
//                          じしˍ,)ノ (cursive cat)



#include <stdio.h>
#define size 20

void printer(int arr[size][size], int gen) // function to print "#" for a living cell and "." for a dead cell
{
    printf("-- Generation: %d\n", gen);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%c", arr[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
}

void neighbours(int arr[size][size], int count[size][size]) // function to log the number of neighbours of all cells
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = -1; k < 2; k++) // k and l used as a 3x3 grid with the observed cell in the center
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!(l == 0 && k == 0) && i + k < size && // this "if" only adds to the neighbour count when the neighbouring cell is visible (on the array)
                        i + k >= 0 &&
                        j + l < size &&
                        j + l >= 0 && arr[i + k][j + l] == 1)
                    {
                        count[i][j]++; // count saves the neighbour count for every index of arr
                    }
                }
            }
        }
    }
}

void evolve(int arr[size][size]) // evolves the array to it's next state
{
    int count[size][size] = {{0}};

    neighbours(arr, count);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1 && (count[i][j] == 2 || count[i][j] == 3)) // living cell with 2 or 3 living neighbours stays alive
            {
                arr[i][j] = 1;
            }
            else if (arr[i][j] == 0 && count[i][j] == 3) // dead cell with 3 living neighbours gets resurrected
            {
                arr[i][j] = 1;
            }
            else // everything else stays dead/dies
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    int arr[size][size] = {{0}};
    int iterations, gen = 0;

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

            arr[y][x] = 1;
        }
        else
            break;
    }

    printer(arr, gen);

    while (gen <= iterations) //prints the array for every generation up to the number of iterations which are input
    {
        evolve(arr);
        gen++;
        printer(arr, gen);
    }

    return 0;
}