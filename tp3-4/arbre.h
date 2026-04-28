#include "annuaire.h"

typedef struct noeud {
    Contacte contacte;
    struct noeud *gauche;
    struct noeud *droite;
} Noeud;




