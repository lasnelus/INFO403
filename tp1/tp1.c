#include <stdio.h>
#include "tp1.h"

int main(void)
{
    TypeGrille gr1 = init_grille();

    affiche_Grille(gr1);
    add_boat(&gr1, 5, 5);

    affiche_Grille(gr1);
    tirer(&gr1, 5, 5);
    tirer(&gr1, 0, 0);

    affiche_Grille(gr1);
    return 0;
}

void affiche_Grille(TypeGrille grid)
{
    printf("   ");
    for (int c = 0; c < grid.size; c++) printf("%d ", c);
    printf("\n");
    for (int i = 0; i < grid.size; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < grid.size; j++)
        {
            printf("%c ", grid.Grille[i][j]);
        }
        printf("\n");
    }
}

void add_boat(TypeGrille *grid, int latitude, int longitude)
{
    grid->Grille[latitude][longitude] = 'B';
}

void tirer (TypeGrille *grid, int latitude, int longitude)
{
    if (check_Touche(*grid, latitude, longitude))
    {
        printf("pizza sans ananas\n");
        grid->Grille[latitude][longitude] = 'X';
    }
    else
    {
        printf("pizza avec ananas\n");
        grid->Grille[latitude][longitude] = 'O';
    }
}

bool check_Touche (TypeGrille grid, int latitude, int longitude){
    if (latitude < 0 || latitude >= grid.size) return false;
    if (longitude < 0 || longitude >= NB_COLONNE) return false;
    return grid.Grille[latitude][longitude] == 'B';
}

TypeGrille init_grille(void)
{
    TypeGrille g;
    g.size = NB_LIGNE;
    for (int i = 0; i < g.size; i++)
        for (int j = 0; j < NB_COLONNE; j++)
            g.Grille[i][j] = '.';
    return g;
}