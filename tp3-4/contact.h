#ifndef CONTACT_H
#define CONTACT_H

#define NOM_MAX_LENGTH 50
#define PRENOM_MAX_LENGTH 50
#define TEL_LENGTH 20
#define MAIL_MAX_LENGTH 100

typedef struct {
    char nom[NOM_MAX_LENGTH];
    char prenom[PRENOM_MAX_LENGTH];
    char tel[TEL_LENGTH];
    char mail[MAIL_MAX_LENGTH];
} Contacte;

Contacte init_contacte(char *nom, char *prenom, char *tel, char *mail);

void afficher_contacte(Contacte contacte);

#endif