#include "annuaire.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    Annuaire annuaire = {0};  // initialise tout à NULL


    Contacte contacte;
    strcpy(contacte.nom, "etienne");
    strcpy(contacte.prenom, "malabre");
    strcpy(contacte.tel, "0699858666");
    strcpy(contacte.mail, "malabretienne@gmail.com");

    Contacte contacte2;
    strcpy(contacte2.nom, "eddy");
    strcpy(contacte2.prenom, "guyon");
    strcpy(contacte2.tel, "0627523669");
    strcpy(contacte2.mail, "eddy.guyon@cmi-info.fr");

    ajouter_contacte_annuaire(&annuaire, contacte);
    ajouter_contacte_annuaire(&annuaire, contacte2);

    lister_contacte_annuaire(annuaire);
    sauvegarder_annuaire(annuaire, "sauvegarde.txt");
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

// AFFICHAGE DE L'ANNUAIRE

void lister_contacte_annuaire(Annuaire annuaire)
{
    for(int i = 0; i<SIZE; i++)
    {
        afficher_contacte_liste_contacte(annuaire[i]);
    }
}

void afficher_contacte_liste_contacte(Liste_Contacte liste_contacte)
{
    while (liste_contacte != NULL)
    {
        afficher_contacte(liste_contacte->contacte);
        printf("\n");
        liste_contacte = liste_contacte->suiv;
    }
}

void afficher_contacte(Contacte contacte)
{
    printf("prenom: %s\n", contacte.prenom);
    printf("tel: %s\n", contacte.tel);
    printf("nom: %s\n", contacte.nom);
    printf("mail: %s\n", contacte.mail);
}


// SYSTEME D'AJOUT A L'ANNUAIRE

void ajouter_contacte_liste_contacte(Liste_Contacte *liste_contacte, Contacte contacte)
{
    if (*liste_contacte == NULL)
    {
        *liste_contacte = malloc(sizeof(**liste_contacte));
        (*liste_contacte)->contacte = contacte;
        (*liste_contacte)->suiv = NULL;
    }
    else
    {
        Liste_Contacte temp = *liste_contacte;
        while (temp->suiv != NULL)
        {
            temp = temp->suiv;
        }
        temp->suiv = malloc(sizeof(**liste_contacte));
        temp->suiv->contacte = contacte;
        temp->suiv->suiv = NULL;
    }
}

void ajouter_contacte_annuaire(Annuaire *annuaire, Contacte contacte)
{
    int index = hash(contacte.nom, contacte.prenom);
    ajouter_contacte_liste_contacte(&(*annuaire)[index], contacte);
}


// SYSTEME SAUVEGARDE FICHIER

void sauvegarder_annuaire(Annuaire annuaire, char *chemin_sauvegarde)
{
    FILE* f = fopen(chemin_sauvegarde, "w");
    if(f != NULL)
    {
        for(int i = 0; i < SIZE; i++)
        {
            while(annuaire[i] != NULL)
            {
                fprintf(f, "%s %s %s %s\n", annuaire[i]->contacte.nom, annuaire[i]->contacte.prenom, annuaire[i]->contacte.tel, annuaire[i]->contacte.mail);
                annuaire[i] = annuaire[i]->suiv;
            }
        }
        printf("Partie sauvegardée avec succès !\n");
    } else {
        printf("Erreur lors de la sauvegarde !\n");
    }
    fclose(f);
}


// SYSTEME CHARGE FICHIER

void charger_annuaire(Annuaire *annuaire, char *chemin_charge)
{
    FILE* f = fopen(chemin_charge, "r");
    if(f == NULL)
    {
        perror("Fichier non ouvert");
        exit(EXIT_FAILURE);
    }

    char nom[NOM_MAX_LENGTH];
    char prenom[PRENOM_MAX_LENGTH];
    char tel[TEL_LENGTH];
    char mail[MAIL_MAX_LENGTH];

    init_annuaire(annuaire);

    int nbElts = fscanf(f, "%[^,],%[^,],%[^,],%[^,]\n", nom, prenom, tel, mail);
    while (nbElts == 4)
    {
        ajouter_contacte_annuaire(annuaire, init_contacte(nom, prenom, tel, mail));
        nbElts = fscanf(f, "%[^,],%[^,],%[^,],%[^,]\n", nom, prenom, tel, mail);
    }
    
    fclose(f);
}

// INIT

void init_annuaire(Annuaire *annuaire)
{
    for (int i = 0; i < SIZE; i++)
    {
        annuaire[i] = NULL;
    }
}

Contacte init_contacte(char *nom, char* prenom, char *tel, char *mail) // TODO des free ?
{
    Contacte c;
    strcpy(c.nom, nom);
    strcpy(c.prenom, prenom);
    strcpy(c.tel, tel);
    strcpy(c.mail, mail);

    return c;
}