/**
TD 4 - GESTION TOURNOIS DE TENNIS

>>>>>>>>>> TD 5 - VOIR LIGNE 117. <<<<<<<<<<

*/
#include "tennis.h"
#include <stdio.h>
#include <stdlib.h>

// Gestion d'un tournoi de tennis

/*
Ecrire un prog pour gérer les résultatus d'un tournoi de tennis, le pg doit
permettre de stocker les rés des match, incluant nom joueur, score par set
chaque match peut avoir un nb variable de joueurs et le score de chaque set est
représenté par le nb de jeux gagnés par chaque joueurs
*/

// #pragma region TD4
int main(void) {
  Tournoi tournoi = NULL;

  char *sabalenka = "Aryna Sabalenka";
  char *rybakina = "Elena Rybakina";

  int nb_sets = 3;
  int score[3][2] = {{6, 1}, {3, 6}, {5, 2}};

  ajouterResultatMatch(&tournoi, sabalenka, rybakina, score, nb_sets);

  char *federer = "Roger Federer";
  char *sampras = "Pete sampras";

  int nb_sets_2 = 4;
  int score_v2[4][2] = {{6, 3}, {5, 7}, {6, 4}, {6, 2}};

  ajouterResultatMatch(&tournoi, federer, sampras, score_v2, nb_sets_2);

  afficherTournoi(tournoi);

  return EXIT_SUCCESS;
}

void ajouterResultatMatch(Tournoi *tournoi, char *joueur1, char *joueur2,
                          int sets[][2], int nombreSets) {
  // Nouveau match
  Match *m = (Match *)malloc(sizeof(Match));
  m->joueur1 = joueur1;
  m->joueur2 = joueur2;
  m->scoreParSet = sets;
  m->nbSets = nombreSets;

  // Ajout du match en tête du tournoi
  m->suivant = *tournoi;
  *tournoi = m;
}

/*
Tournoi :
    Match 1 :
        J1 : {{J1}} - J2 : {{J2}}
        Scores  :
            Set N°1 : {{scoreParSet[1][0]}} - {{scoreParSet[1][1]}}
            Set N°... :
            Set N°n : {{scoreParSet[n][0]}} - {{scoreParSet[n][1]}}
    Match ...:
        ...
    Match n :
        J1 : {{J1}} - J2 : {{J2}}
        Scores  :
            Set N°1 : {{scoreParSet[1][0]}} - {{scoreParSet[1][1]}}
            Set N°... :
            Set N°n : {{scoreParSet[n][0]}} - {{scoreParSet[n][1]}}
*/

void afficherMatch(Match m, int no_match) {

  printf("  Match %d :\n", no_match);
  printf("    J1 : %s - J2 : %s\n", m.joueur1, m.joueur2);
  printf("    Scores :\n");

  for (int i = 0; i < m.nbSets; i++) {
    printf("      Set N°%d : %d - %d\n", i, m.scoreParSet[i][0],
           m.scoreParSet[i][1]);
  }
}

void afficherTournoi(Tournoi tournoi) {

  printf("Tournoi :\n");

  Match *m = tournoi;
  int i = 0;
  while (m != NULL) {
    afficherMatch(*m, ++i);
    m = m->suivant;
  }
}

void libererTournoi(Tournoi *tournoi) {

  Match *match = *tournoi;

  while (match != NULL) {
    Match *suiv = match->suivant;
    free(match);
    match = suiv;
  }

  tournoi = NULL;
}
// #pragma endregion TD4

/**
TD 5 - ON REPRENDS LE CODE DU TOURNOIS POUR L'AMELIORER.
*/

/*
Ajouter deux fonctions :
- lireTournoi qui lit un fichier texte contenant les résultats d’un tournoi de
tennis et renvoie un Tournoi.
- sauvegarderTournoi qui écrit un fichier texte contenant les résultats d’un
tournoi de tennis.
*/

/**
Lis un fichier de representation d'un tournoi et renvoie le tournoi correspondant
*/
Tournoi lireTournoi(FILE *fichier) {
  int nbSet;
  char *joueur1;
  char *joueur2;
  fscanf("%s, %s, %d", joueur1, joueur2, nbSet);
  int scores[nbSet][2];
  for (int i = 0; i < nbSet; i++) {
    fscanf("%d-%d", score1, score2);
    scores[1]={score1, score2};
  }
}

/**
Sauvegarde un tournoi dans un fichier selon un format défini.
Le format du fichier texte est le suivant :

Iga Swiatek,Steffi Graf,3
6-3
5-7
6-4
Steffi Graf,Serena Williams,2
5-7
4-6
*/
void sauvegarderTournoi(Tournoi t, FILE f) {
  
}
