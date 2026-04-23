#include "annuaire.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    Contacte contacte;
    strcpy(contacte.nom, "etienne");
    strcpy(contacte.prenom, "malabre");
    strcpy(contacte.tel, "0699858666");
    strcpy(contacte.mail, "malabretienne@gmail.com");

    Contacte contacte2;
    strcpy(contacte2.nom, "etienne");
    strcpy(contacte2.prenom, "malabre");
    strcpy(contacte2.tel, "0699858666");
    strcpy(contacte2.mail, "malabretienne@gmail.com");


    Liste_Contacte liste2 = malloc(sizeof(struct liste_contacte));
    liste2->contacte = contacte2;
    liste2->suiv = NULL;
    Liste_Contacte liste1 = malloc(sizeof(struct liste_contacte));
    liste1->contacte = contacte;
    liste1->suiv = liste2;

    afficher_contacte_liste_contacte(liste1);
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

void afficher_contacte_liste_contacte(Liste_Contacte liste_contacte)
{
    Contacte contacte = liste_contacte->contacte;
    while (contacte != NULL)
    {
       afficher_contacte(contacte);
       printf("\n");
       contacte = liste_contacte->suiv;
    }
    
}

void afficher_contacte(Contacte contacte)
{
    printf("nom: %s\n", contacte.nom);
    printf("prenom: %s\n", contacte.prenom);
    printf("tel: %s\n", contacte.tel);
    printf("mail: %s\n", contacte.mail);
}