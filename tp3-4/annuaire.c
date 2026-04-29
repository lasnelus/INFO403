#include "annuaire.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void affiche_aide(void)
{
    printf("-f fichier1 fichier2 : fusionner\n");
    printf("Options disponibles :\n");
    printf("-a nom prenom tel mail fichier : ajouter un contact\n");
    printf("-l fichier : lister les contacts\n");
    printf("-r [n|t|m] valeur fichier : rechercher\n");
    printf("-s nom fichier : supprimer\n");
}



int hash(char *nom, char *prenom) {
    int hash = 0;
    for (size_t i = 0; i < strlen(nom); i++) {
       hash += nom[i];
    }
    for (size_t i = 0; i < strlen(prenom); i++) {
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

// SYSTEME D'EXTRACTION

void extraire_contacte_annuaire(Annuaire annuaire, char *param)
{
    for (int i = 0; i < SIZE; i++)
    {
        Liste_Contacte temp = annuaire[i];

        while (temp != NULL)
        {
            for (int j = 0; param[j] != '\0'; j++)
            {
                if (param[j] == 'n')
                    printf("%s ", temp->contacte.nom);

                if (param[j] == 'p')
                    printf("%s ", temp->contacte.prenom);

                if (param[j] == 't')
                    printf("%s ", temp->contacte.tel);

                if (param[j] == 'm')
                    printf("%s ", temp->contacte.mail);
            }

            printf("\n");
            temp = temp->suiv;
        }
    }
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

// SYSTEME RECHERCHE ANNUAIRE

void rechercher_contacte_annuaire(Annuaire annuaire, char *val, char *filtre)
{
    for (int i = 0; i < SIZE; i++)
    {
        Liste_Contacte temp = annuaire[i];

        while (temp != NULL)
        {
            if (strcmp(filtre, "n") == 0 && strcmp(temp->contacte.nom, val) == 0)
                afficher_contacte(temp->contacte);

            if (strcmp(filtre, "t") == 0 && strcmp(temp->contacte.tel, val) == 0)
                afficher_contacte(temp->contacte);

            if (strcmp(filtre, "m") == 0 && strcmp(temp->contacte.mail, val) == 0)
                afficher_contacte(temp->contacte);

            temp = temp->suiv;
        }
    }
}

//SYSTEME SUPPRESSION CONTACT

void supprimer_contacte_annuaire(Annuaire *annuaire, char *nom)
{
    int trouve = false;

    for (int i = 0; i < SIZE && !trouve; i++)
    {
        Liste_Contacte temp = (*annuaire)[i];
        Liste_Contacte prec = NULL;

        while (temp != NULL && !trouve)
        {
            if (strcmp(temp->contacte.nom, nom) == 0)
            {
                if (prec == NULL)
                    (*annuaire)[i] = temp->suiv;
                else
                    prec->suiv = temp->suiv;

                free(temp);
                trouve = true;
            }
            else
            {
                prec = temp;
                temp = temp->suiv;
            }
        }
    }
}

//SYSTEME FUSION ANNUAIRE

void fusionner_annuaire(Annuaire *annuaire_receveur, Annuaire annuaire_donneur)
{
    for (int i = 0; i < SIZE; i++)
    {
        Liste_Contacte temp = annuaire_donneur[i];

        while (temp != NULL)
        {
            ajouter_contacte_annuaire(annuaire_receveur, temp->contacte);
            temp = temp->suiv;
        }
    }
}


// SYSTEME SAUVEGARDE FICHIER

void sauvegarder_annuaire(Annuaire annuaire, char *chemin_sauvegarde)
{
    FILE* f = fopen(chemin_sauvegarde, "w");
    if(f != NULL)
    {
        for(int i = 0; i < SIZE; i++)
        {
            Liste_Contacte temp = annuaire[i];
            while(annuaire[i] != NULL)
            {
                fprintf(f, "%s %s %s %s\n", temp->contacte.nom, temp->contacte.prenom, temp->contacte.tel, temp->contacte.mail);
                temp = temp->suiv;
            }
        }
        printf("Annuaire sauvegardée avec succès !\n");
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

    int nbElts = fscanf(f, "%s %s %s %s\n", nom, prenom, tel, mail);
    while (nbElts == 4)
    {
        ajouter_contacte_annuaire(annuaire, init_contacte(nom, prenom, tel, mail));
        
        nbElts = fscanf(f, "%s %s %s %s\n", nom, prenom, tel, mail);
    }
    
    fclose(f);
}

// INIT

void init_annuaire(Annuaire *annuaire)
{
    for (int i = 0; i < SIZE; i++)
    {
        (*annuaire)[i] = NULL;
    }
}