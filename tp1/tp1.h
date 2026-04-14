#include <stdbool.h>
#define SIZE 10
#define CHEMIN_SAUVEGARDE "sauvegarde.txt"
#define NB_BATEAUX_MAX 5
#define TAILLES_BATEAUX {5, 4, 3, 3, 2}

typedef struct {
    int taille;
    char Grille[SIZE][SIZE];
} TypeGrille;

typedef struct {
    int taille;
    int ligne;
    int colonne;
    int direction; // 0 = horizontal, 1 = vertical
} Bateau;

typedef struct {
    int nb_bateau;
    TypeGrille grille;
    Bateau bateaux[NB_BATEAUX_MAX];
} Joueur;



Joueur init_joueur(int nb);

TypeGrille init_grille(void);

void affiche_grille(TypeGrille grille);

void add_bateau(TypeGrille *grille, int latitude, int longitude, int taille, int direction, int num_bateau);

bool check_collision(TypeGrille *grid, int latitude, int longitude, int taille, int direction);

void tirer (Joueur *joueur, int latitude, int longitude, int *tour);

bool check_touche (TypeGrille grille, int latitude, int longitude);

void generer_bateaux_aleatoire(TypeGrille *grille, int nb_bateaux);

void tire_aleatoire(Joueur *joueur, int *tour);

void tirer_UI(Joueur *joueur, int *tour);

void placage_bateaux_UI(TypeGrille *grille, int nb_bateaux);

void sauvegarder(Joueur joueur, Joueur ordinateur);

void charger(Joueur *joueur, Joueur *ordinateur, bool *chargement_reussi);

void menu_principal(void);

void jouer_partie(Joueur joueur, Joueur ordinateur, int tour);

bool charger_partie_existante(Joueur *joueur, Joueur *ordinateur);