#include <stdio.h>
#include "tp1.h"

int main(void)
{
    Grille gr1 = {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };

    affiche_Grille(gr1);
    tirer(&gr1, 5, 5);
    return 0;
}

void affiche_Grille(Grille grid)
{
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0; i<10;i++)
    {
        printf("%d ",i);
        for(int j=0;j<10;j++)
        {
            printf(" %c", grid[i][j]);
        }
        printf("\n");
    }
}

// void add_boat(Grille *grid, int latitude, int longitude)
// {
//     grid[latitude][longitude] = "B";
// }

void tirer (Grille *grid, int latitude, int longitude)
{
    if (check_Touche(*grid, latitude, longitude))
    {
        printf("pizza sans ananas");
    }else{
        printf("pizza avec ananas");
    }
}

bool check_Touche (Grille grid, int latitude, int longitude){
    grid[latitude][longitude] = 'B';
}