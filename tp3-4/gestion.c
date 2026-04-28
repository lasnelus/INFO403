#include "gestion.h"
#include "annuaire.h"
#include <stdio.h>

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
    printf("nom: %s\n", contacte.nom);
    printf("prenom: %s\n", contacte.prenom);
    printf("tel: %s\n", contacte.tel);
    printf("mail: %s\n", contacte.mail);
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

// INIT

void init_annuaire(Annuaire *annuaire)
{
    for (int i = 0; i < SIZE; i++)
    {
        (*annuaire)[i] = NULL;
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