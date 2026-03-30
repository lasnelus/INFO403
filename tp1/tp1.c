#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp1.h"

int main(void)
{
    srand((unsigned)time(NULL));

    Joueur joueur = init_joueur(3);
    Joueur bot = init_joueur(3);

    printf("Placement des bateaux du joueur:\n");
    placage_bateaux_UI(&joueur.grille, joueur.nb_bateau);

    printf("Placement aléatoire des bateaux du bot...\n");
    generer_bateaux_aleatoire(&bot.grille, bot.nb_bateau);

    int tour = 0; // 0 = joueur, 1 = bot
    while (joueur.nb_bateau > 0 && bot.nb_bateau > 0)
    {
        printf("\n--- Etat des grilles ---\n");
        printf("Joueur (vos bateaux) :\n");
        affiche_grille(joueur.grille);
        printf("Bot :\n");
        affiche_grille(bot.grille);

        if (tour == 0)
        {
            printf("\nVotre tour.\n");
            tirer_UI(&bot, &tour);
        }
        else
        {
            printf("\nTour du bot.\n");
            tire_aleatoire(&joueur, &tour);
        }
    }

    if (joueur.nb_bateau <= 0) printf("Le bot a gagné !\n");
    else printf("Vous avez gagné !\n");

    return 0;
}


TypeGrille init_grille(void)
{
    TypeGrille g;
    g.taille = SIZE;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            g.Grille[i][j] = '.';
    return g;
}

Joueur init_joueur(int nb)
{
    Joueur j;
    j.nb_bateau = nb;
    j.grille = init_grille();
    return j;
}




void affiche_grille(TypeGrille grid)
{
    printf("  ");
    for (int c = 0; c < grid.taille; c++) printf("%d ", c);
    printf("\n");
    for (int i = 0; i < grid.taille; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < grid.taille; j++)
        {
        printf("%c ", grid.Grille[i][j]);
        }
        printf("\n");
    }
}

void add_bateau(TypeGrille *grid, int latitude, int longitude)
{
    if (latitude < 0 || latitude >= grid->taille) return;
    if (longitude < 0 || longitude >= grid->taille) return;
    grid->Grille[latitude][longitude] = 'B';
}

void tirer (Joueur *joueur, int latitude, int longitude, int *tour)
{
    if (latitude < 0 || latitude >= joueur->grille.taille || longitude < 0 || longitude >= joueur->grille.taille) {
        printf("Coordonnées hors limites\n");
        return;
    }

    if (check_touche(joueur->grille, latitude, longitude))
    {
        printf("pizza sans ananas\n");
        joueur->grille.Grille[latitude][longitude] = 'X';
        if (joueur->nb_bateau > 0) joueur->nb_bateau--;
    }
    else
    {
        printf("pizza avec ananas\n");
        joueur->grille.Grille[latitude][longitude] = 'O';
        if (*tour == 1)
        {
            *tour = 0;
        }else
        {
            *tour = 1;
        }
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
        latitude = rand() % SIZE;
        longitude = rand() % SIZE;
        add_bateau(grille, latitude, longitude);
    }
}

void tire_aleatoire(Joueur *joueur, int *tour)
{
    int latitude = rand() % SIZE;
    int longitude = rand() % SIZE;
    tirer(joueur, latitude, longitude, tour);
}






void tirer_UI(Joueur *joueur, int *tour){
    int latitude;
    int longitude;
    printf("Entrez les coordonnées de tir (ligne colonne) :");
    scanf("%d %d", &latitude, &longitude);
    tirer(joueur, latitude, longitude, tour);
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