#define SIZE 100


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


typedef Contact_List HashTable[SIZE];


int hash(char *name, char *first_name);