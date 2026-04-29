#include "annuaire.h"

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
                lister_contacte_annuaire(*annuaire);
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
    printf("n : nom\n t: n° telephone\n m: mail\n");
    scanf("%s\n", param);
    printf("a chercher : ");
    scanf("%s", valeur);
    rechercher_contacte_annuaire(annuaire, valeur, param);
}

void affiche_menu_extraction(Annuaire annuaire)
{
    char param[7];
    printf("Quel information rechercher ?\n");
    printf("n: nom\n p: prenom\n t: n° telephone\n m: mail\n");
    printf("écrire tout attaché les informations voulues\n");
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