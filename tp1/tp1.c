#include <stdio.h>
#include "tp1.h"

int main(void)
{
    TypeGrille grjoueur = init_grille();
    TypeGrille grbot = init_grille();

    affiche_Grille(grjoueur);
    add_boat(&grjoueur, 5, 5);

    affiche_Grille(grjoueur);
    tirer_UI(&grbot);

    affiche_Grille(grbot);
    return 0;
}

void affiche_Grille(TypeGrille grid)
{
    printf("  ");
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

void tirer_UI(TypeGrille *grille){
    int latitude;
    int longitude;
    printf("Entrez les coordonnées de tir (ligne colonne) :");
    scanf("%d, %d", &latitude, &longitude);
    tirer(grille, latitude, longitude);
}