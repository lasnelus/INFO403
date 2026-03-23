#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "td4.h"

void main (void)
{

}

void ajouterResultatMatch(Tournoi *tournoi, char *joueur1, char *joueur2, int sets[][2], int nombreSets)
{
    Match *m = (Match *)malloc(sizeof(Match));
    m->nombre_sets = nombreSets;
    m->nomJ1 = joueur1;
    m->nomJ2 = joueur2;
    m->score = score;
    m->suivant = *tournoi;

    *tournoi = m;
}

void afficherMatch(Match match)
{
    printf("Nb Sets : %d\n", match.nombre_sets);
    for (int i = 0; i < match.nombre_sets; i++)
    {
        printf("%d-%d\n", match.score[i][0], match.score[i][1]);
    }
    printf("----------------\n");
}

void afficherTournoi(Tournoi tournoi)
{
    Match *m = tournoi;

    while (match != NULL)
    {
        afficherMatch(*match);
        match = match->suivant;
    }
}

void libererTournoi(Tournoi *tourniu)
{
    Match *match = *tournoi;

    while (match != NULL)
    {
        Match *suiv = match->suivant;
        free(match);
        match = suiv;
    }
    *tournoi = NULL;
}