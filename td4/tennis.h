#ifndef TENNIS_H
#define TENNIS_H

#include <stdio.h>

typedef struct _match {
  char *joueur1;
  char *joueur2;
  int (*scoreParSet)[2];
  int nbSets;
  struct _match *suivant;
} Match;

typedef Match *Tournoi;

/**
Ajoute un nouveau match au tournoi avec les joueurs, les scores des sets et
le nombre de sets
*/
void ajouterResultatMatch(Tournoi *tournoi, char *joueur1, char *joueur2,
                          int sets[][2], int nombreSets);

/**
Affiche les résultats de tout les matchs dans le tournoi en listant les
joueurs et les scores de chaque set
*/
void afficherTournoi(Tournoi tournoi);

/**
Libère toute la mémoire allouée pour le tournoi
*/
void libererTournoi(Tournoi *tournoi);

/* -------------------------------------------------------------------- */
/* TD5                                                                  */
/* -------------------------------------------------------------------- */

Tournoi lireTournoi(FILE *fichier);

void sauvegarderTournoi(Tournoi t, FILE f);
#endif