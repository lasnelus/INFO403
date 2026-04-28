#define SIZE 100
#define NOM_MAX_LENGTH 50
#define PRENOM_MAX_LENGTH 50
#define TEL_LENGTH 15 //le ptn de \0
#define MAIL_MAX_LENGTH 120
#define CHEMIN_SAUVEGARDE "sauvegarde.txt"


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

typedef Liste_Contacte Annuaire[SIZE];

void affiche_menu(void);

void affiche_aide(void);

int hash(char *name, char *first_name);

Liste_Contacte init_liste_contacte(Contacte contacte);

void ajouter_contacte_liste_contacte(Liste_Contacte *liste_contacte, Contacte contacte);

void ajouter_contacte_annuaire(Annuaire *annuaire, Contacte contacte);

void afficher_contacte(Contacte contacte);

void afficher_contacte_liste_contacte(Liste_Contacte liste_contacte);

void lister_contacte_annuaire(Annuaire annuaire);

void supprimer_contacte_annuaire(Annuaire *annuaire, Contacte contacte);

void rechercher_contacte_annuaire(Annuaire annuaire, char *val, char *filtre);

void extraire_contacte_annuaire(Annuaire annuaire, char *param);

void fusionner_annuaire(Annuaire *annuaire_receveur, Annuaire annuaire_donneur);

void sauvegarder_annuaire(Annuaire annuaire, char *chemin_sauvegarde);

void charger_annuaire(Annuaire *annuaire, char *chemin_charge);

void init_annuaire(Annuaire *annuaire);

Contacte init_contacte(char *nom, char* prenom, char *tel, char *mail);