#include <stdbool.h>
#define NB_COLONNE 10
#define NB_LIGNE 10

typedef struct{
    int size;
    char Grille[size][size];
} TypeGrille;

void affiche_Grille(TypeGrille grille);

void add_boat(TypeGrille *grille, int latitude, int longitude);

void tirer (TypeGrille *grille, int latitude, int longitude);

bool check_Touche (TypeGrille grille, int latitude, int longitude);

TypeGrille init_grille(void);