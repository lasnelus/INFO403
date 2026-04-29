#include "annuaire.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>

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