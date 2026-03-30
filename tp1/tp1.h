#include <stdbool.h>
#define SIZE 10

typedef struct{
    int taille;
    char Grille[SIZE][SIZE];
} TypeGrille;

typedef struct{
    int nb_bateau;
    TypeGrille grille;
} Joueur;



Joueur init_joueur(int nb);

TypeGrille init_grille(void);

void affiche_grille(TypeGrille grille);

void add_bateau(TypeGrille *grille, int latitude, int longitude);

void tirer (TypeGrille *grille, int latitude, int longitude);

bool check_touche (TypeGrille grille, int latitude, int longitude);

void generer_bateaux_aleatoire(TypeGrille *grille, int nb_bateaux);

void tire_aleatoire(TypeGrille *grille);


void tirer_UI(TypeGrille *grille);

void placage_bateaux_UI(TypeGrille *grille, int nb_bateaux);