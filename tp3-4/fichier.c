#include "fichier.h"
#include <stdio.h>

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