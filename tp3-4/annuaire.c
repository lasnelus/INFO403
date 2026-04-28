#include "annuaire.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    Annuaire annuaire;

    if (argc < 2) {
        printf("Utilisation : ./annuaire [option]\n");
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        affiche_aide();
        return 1;
    }

    else if (strcmp(argv[1], "-l") == 0) {
        if (argc != 3) {
            printf("Usage: ./annuaire -l fichier\n");
            return 1;
        }

        charger_annuaire(&annuaire, argv[2]);
        lister_contacte_annuaire(annuaire);
    }
    else if (strcmp(argv[1], "-a") == 0) {
        if (argc != 7) {
            printf("Usage: ./annuaire -a nom prenom tel mail fichier\n");
            return 1;
        }

        charger_annuaire(&annuaire, argv[6]);

        Contacte c = init_contacte(argv[2], argv[3], argv[4], argv[5]);
        ajouter_contacte_annuaire(&annuaire, c);

        sauvegarder_annuaire(annuaire, argv[6]);
    }
    else if (strcmp(argv[1], "-e") == 0){
        charger_annuaire(&annuaire, argv[3]);

        extraire_contacte_annuaire(annuaire, argv[2]);
    }
    else if (strcmp(argv[1], "-f") == 0){
        if (argc != 4) {
            printf("Usage: ./annuaire -f fichier1 fichier2\n");
            return 1;
        }
        Annuaire annuaire2;
        charger_annuaire(&annuaire, argv[2]);
        charger_annuaire(&annuaire2, argv[3]);

        fusionner_annuaire(&annuaire, annuaire2);
    }
    else if (strcmp(argv[1], "-r") == 0){
        if (argc != 5){
            printf("Usage: ./annuaire -r [n|t|m] valeur fichier\n");
            return 1;
        }

        charger_annuaire(&annuaire, argv[4]);

        rechercher_contacte_annuaire(annuaire, argv[3], argv[2]);
    }
    else if (strcmp(argv[1], "-s") == 0){
        if (argc != 4){
            printf("Usage: ./annuaire -s nom fichier\n");
            return 1;
        }

        charger_annuaire(&annuaire, argv[3]);
        supprimer_contacte_annuaire(&annuaire, argv[2]);
    }
    else if (strcmp(argv[1], "-i") == 0){
        charger_annuaire(&annuaire, argv[2]);
        affiche_menu(&annuaire);
        return 1;
    }
    else {
        printf("Option inconnue. Utilise -h pour l'aide.\n");
    }

    sauvegarder_annuaire(annuaire, "sauvegarde.sav");
    return 0;
}

void affiche_aide(void)
{
    printf("Options disponibles :\n");
    printf("-a nom prenom tel mail fichier : ajouter un contact\n");
    printf("-l fichier : lister les contacts\n");
    printf("-r [n|t|m] valeur fichier : rechercher\n");
    printf("-s nom fichier : supprimer\n");
    printf("-f fichier1 fichier2 : fusionner\n");
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

// MENU INTERACTIF

void affiche_menu(Annuaire *annuaire)
{
    int choix = 0;

    do{
    printf("Que souhaitez-vous faire ?\n");
    printf("1. Ajouter un contact\n");
    printf("2. Afficher tout les contacts\n");
    printf("3. Afficher l'aide\n");
    printf("4. Rechercher un contact\n");
    printf("5. Extraire certaine information\n");
    printf("6. Supprimer un contact\n");
    printf("7. Fusionner des fichiers\n");
    printf("8. Quitter\n");
    scanf("%d", &choix);
    switch (choix)
        {
            case 1:
                affiche_menu_ajout(annuaire);
                break;

            case 2:
                lister_contacte_annuaire(annuaire);
                break;

            case 3:
                affiche_aide();
                break;

            case 4:
                affiche_menu_recherche(*annuaire);
                break;

            case 5:
                affiche_menu_extraction(*annuaire);
                break;

            case 6:
                affiche_menu_suppression(annuaire);
                break;

            case 7:
                affiche_menu_fusion(annuaire);
                break;

            case 8:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez recommencer.\n");
                break;
        }

    } while (choix != 8);

}

void affiche_menu_ajout(Annuaire *annuaire)
{
    char nom[NOM_MAX_LENGTH];
    char prenom[PRENOM_MAX_LENGTH];
    char tel[TEL_LENGTH];
    char mail[MAIL_MAX_LENGTH];
    printf("Nom : ");
    scanf("%s\n", nom);
    printf("Prenom : ");
    scanf("%s\n", prenom);
    printf("N° telephone : ");
    scanf("%s\n", tel);
    printf("Mail : ");
    scanf("%s\n", mail);
    Contacte contacte = init_contacte(nom, prenom, tel, mail);
    ajouter_contacte_annuaire(annuaire, contacte);
}

void affiche_menu_recherche(Annuaire annuaire)
{
    char param[5];
    char valeur[120];
    printf("Sur quel paramètre rechercher ?\n");
    printf("n : nom\n t: n° telephone\n m: mail");
    scanf("%s", param);
    scanf("à chercher : %s", valeur);
    rechercher_contacte_annuaire(annuaire, valeur, param);
}

void affiche_menu_extraction(Annuaire annuaire)
{
    char param[7];
    printf("Quel information rechercher ?\n");
    printf("n: nom\n p: prenom\n t: n° telephone\n m: mail");
    printf("écrire tout attaché les informations vouluts");
    scanf("%s", param);
    extraire_contacte_annuaire(annuaire, param);
}

void affiche_menu_suppression(Annuaire *annuaire)
{
    char nom[NOM_MAX_LENGTH];
    scanf("nom du contact à supprimer: %s", nom);
    supprimer_contacte_annuaire(annuaire, nom);
}

void affiche_menu_fusion(Annuaire *annuaire)
{
    char nom_fichier[99];
    Annuaire annuaire2;
    scanf("nom du fichier à ajouter à l'annuaire: %s", nom_fichier);
    charger_annuaire(&annuaire2, nom_fichier);
    fusionner_annuaire(annuaire, annuaire2);
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