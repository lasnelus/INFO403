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
    placage_bateaux_UI(&grjoueur,3);

    generer_bateaux_aleatoire(&grbot, 3);

    tire_aleatoire(&grjoueur);
    affiche_grille(grjoueur);
    affiche_grille(grbot);
    return 0;
}

TypeGrille init_grille(void)
{
    TypeGrille g;
    g.size = SIZE;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
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

void generer_bateaux_aleatoire(TypeGrille *grille, int nb_bateaux)
{
    int latitude;
    int longitude;
    for(int i=0; i<nb_bateaux; i++)
    {
        latitude = rand()%20;
        longitude = rand()%20;
        add_bateau(grille, latitude, longitude);
    }
}

void tire_aleatoire(TypeGrille *grille)
{
    int latitude = rand()%20;
    int longitude = rand()%20;
    tirer(grille, latitude, longitude);
}






void tirer_UI(TypeGrille *grille){
    int latitude;
    int longitude;
    printf("Entrez les coordonnées de tir (ligne colonne) :");
    scanf("%d %d", &latitude, &longitude);
    tirer(grille, latitude, longitude);
}

void placage_bateaux_UI(TypeGrille *grille, int nb_bateaux)
{
    int latitude;
    int longitude;
    for(int i=0; i<nb_bateaux; i++)
    {
        printf("Entrez les coordonnées du bateau %d (ligne colonne) :", i);
        scanf("%d %d", &latitude, &longitude);
        add_bateau(grille, latitude, longitude);
    }
}