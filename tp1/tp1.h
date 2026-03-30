#include <stdbool.h>
#define NB_COLONNE 10
#define NB_LIGNE 10

typedef char Grille[NB_LIGNE][NB_COLONNE];

void affiche_Grille(Grille grid);

void add_boat(Grille *grid, int latitude, int longitude);

void tirer (Grille *grid, int latitude, int longitude);

bool check_Touche (Grille grid, int latitude, int longitude);