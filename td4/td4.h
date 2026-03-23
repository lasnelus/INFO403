typedef struct match{
    char *nomJ1;
    char *nomJ2;
    int (*score)[2];
    int nombre_sets;
    struct _match *suivant;
} Match;

typedef Match *Tournoi;

void ajouterResultatMatch(Tournoi *tournoi, char *joueur1, char *joueur2, int sets[][2], int nombreSets);

void afficherTournoi(Tournoi tournoi);