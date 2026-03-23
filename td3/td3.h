#define NB_RANGEE_MAX 10
#define NB_COLONNE_MAX 20
#define NB_SALLES 3


typedef enum {
    Standard,
    Premium,
    VIP
} TypePlace;


typedef struct {
    int num;
    bool reserve;
    TypePlace type;
} Place;


typedef struct {
    int nb_rangees;;
    int nb_colonnes;
    Place places[NB_RANGEE_MAX][NB_COLONNE_MAX];
} Salle;

typedef Salle Cinema[NB_SALLES];

void init_Cinema(Cinema cinema, int nb_places[NB_SALLES][2]);

int creer_numero(int i, int j);

void init_salle(Salle *salle, int nb_places[2])