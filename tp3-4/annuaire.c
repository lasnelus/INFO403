#include "annuaire.h"
#include <string.h>


void main(void)
{
    Contacte *contacte;
    contacte->nom = "etienne";
    contacte->prenom = "malabre";
    contacte->tel = "0699858666";
    contacte->mail = "malabretienne@gmail.com";

    afficher_contacte(contacte);
}


int hash(char *nom, char *prenom) {
    int hash = 0;
    for (int i = 0; i < strlen(nom); i++) {
       hash += nom[i];
    }
    for (int i = 0; i < strlen(prenom); i++) {
        hash += prenom[i];
    }
    return hash % SIZE;
}

void afficher_contacte(Contacte contacte)
{
    printf("nom: %s\n", contacte.nom);
    printf("prenom: %s\n", contacte.prenom);
    printf("tel: %s\n", contacte.tel);
    printf("mail: %s\n", contacte.mail);
}