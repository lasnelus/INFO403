#define SIZE 100
#define NOM_MAX_LENGTH 50
#define PRENOM_MAX_LENGTH 50
#define TEL_LENGTH 10
#define MAIL_MAX_LENGTH 120



typedef struct {
    char nom[NOM_MAX_LENGTH];
    char prenom[PRENOM_MAX_LENGTH];
    char tel[TEL_LENGTH];
    char mail[MAIL_MAX_LENGTH];
} Contacte ;

typedef struct liste_contacte {
    Contacte contacte;
    struct liste_contacte *suiv;
} *Liste_Contacte;


typedef Liste_Contacte HashTable[SIZE];


int hash(char *name, char *first_name);

void ajouter_contacte_annuaire(Annuaire *annuaire, Contacte contacte);

void lister_contacte_annuaire(Annuaire annuaire);

void supprimer_contacte_annuaire(Annuaire *annuaire, Contacte contacte);

Contacte rechercher_contacte_nom_annuaire(Annuaire annuaire, char[NOM_MAX_LENGTH] nom);

//extraire wtf

void fusionner_annuaire(Annuaire *annuaire_receveur, Annuaire annuaire_donneur);