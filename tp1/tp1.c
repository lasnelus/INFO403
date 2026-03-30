#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp1.h"

int main(void)
{
    srand(time(NULL));


    TypeGrille grjoueur = init_grille();
    TypeGrille grbot = init_grille();

    affiche_grille(grjoueur);
    add_bateau(&grjoueur, 5, 5);

    generate_random_bateaux(&grbot, 3);


    affiche_grille(grjoueur);
    affiche_grille(grbot);
    return 0;
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


void affiche_grille(TypeGrille grid)
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

void add_bateau(TypeGrille *grid, int latitude, int longitude)
{
    grid->Grille[latitude][longitude] = 'B';
}

void tirer (TypeGrille *grid, int latitude, int longitude)
{
    if (check_touche(*grid, latitude, longitude))
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

bool check_touche (TypeGrille grid, int latitude, int longitude){
    return grid.Grille[latitude][longitude] == 'B';
}

void generate_random_bateaux(TypeGrille *grille, int nb_bateaux)
{
    int latitude;
    int longitude;
    for(int i=0; i<nb_bateaux; i++)
    {
        latitude = (rand()/RAND_MAX) * 10;
        longitude = (rand()/RAND_MAX) * 1;
        add_bateau(grille, latitude, longitude);
    }
}



void tirer_UI(TypeGrille *grille){
    int latitude;
    int longitude;
    printf("Entrez les coordonnées de tir (ligne colonne) :");
    scanf("%d, %d", &latitude, &longitude);
    tirer(grille, latitude, longitude);
}