#include <stdbool.h>
#define NB_COLONNE 10
#define NB_LIGNE 10

typedef struct{
    int size;
    char Grille[NB_LIGNE][NB_COLONNE];
} TypeGrille;

TypeGrille init_grille(void);

void affiche_grille(TypeGrille grille);

void add_bateau(TypeGrille *grille, int latitude, int longitude);

void tirer (TypeGrille *grille, int latitude, int longitude);

bool check_touche (TypeGrille grille, int latitude, int longitude);

void generate_random_bateaux(TypeGrille *grille, int nb_bateaux);


void tirer_UI(TypeGrille *grille);