#include "contact.h"
#include <stdio.h>
#include <string.h>

Contacte init_contacte(char *nom, char* prenom, char *tel, char *mail) // TODO des free ?
{
    Contacte c;
    strcpy(c.nom, nom);
    strcpy(c.prenom, prenom);
    strcpy(c.tel, tel);
    strcpy(c.mail, mail);

    return c;
}

void afficher_contacte(Contacte contacte)
{
    printf("nom: %s\n", contacte.nom);
    printf("prenom: %s\n", contacte.prenom);
    printf("tel: %s\n", contacte.tel);
    printf("mail: %s\n", contacte.mail);
}