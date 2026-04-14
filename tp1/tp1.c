#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp1.h"

int main(void)
{
    srand(time(NULL));
    int choix;
    bool continuer = true;

    while (continuer)
    {
        menu_principal();
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
            {
                // Nouvelle partie
                Joueur joueur = init_joueur(3);
                Joueur bot = init_joueur(3);

                printf("\nPlacement des bateaux du joueur:\n");
                placage_bateaux_UI(&joueur.grille, joueur.nb_bateau);

                printf("Placement aléatoire des bateaux du bot...\n");
                generer_bateaux_aleatoire(&bot.grille, bot.nb_bateau);

                jouer_partie(joueur, bot, 0);
                break;
            }
            case 2:
            {
                // Charger une partie
                Joueur joueur = init_joueur(3);
                Joueur bot = init_joueur(3);
                bool chargement_ok = charger_partie_existante(&joueur, &bot);

                if (chargement_ok)
                {
                    printf("\nPartie chargée avec succès!\n");
                    jouer_partie(joueur, bot, 0);
                }
                break;
            }
            case 3:
            {
                printf("Au revoir !\n");
                continuer = false;
                break;
            }
            default:
                printf("Choix invalide !\n");
        }
    }

    return 0;
}


TypeGrille init_grille(void)
{
    TypeGrille g;
    g.taille = SIZE;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            g.Grille[i][j] = '.';
    return g;
}

Joueur init_joueur(int nb)
{
    Joueur j;
    j.nb_bateau = nb;
    j.grille = init_grille();
    return j;
}




void affiche_grille(TypeGrille grid)
{
    printf("  ");
    for (int c = 0; c < grid.taille; c++) printf("%d ", c);
    printf("\n");
    for (int i = 0; i < grid.taille; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < grid.taille; j++)
        {
        printf("%c ", grid.Grille[i][j]);
        }
        printf("\n");
    }
}

void add_bateau(TypeGrille *grid, int latitude, int longitude, int taille, int direction, int num_bateau)
{
    if (direction == 0) // horizontal
    {
        if (longitude + taille > grid->taille) return;
        for (int j = 0; j < taille; j++)
        {
            if (latitude < 0 || latitude >= grid->taille || longitude + j < 0 || longitude + j >= grid->taille)
                return;
            grid->Grille[latitude][longitude + j] = 'B' + num_bateau; // char différent pour chaque bateau
        }
    }
    else // vertical
    {
        if (latitude + taille > grid->taille) return;
        for (int i = 0; i < taille; i++)
        {
            if (latitude + i < 0 || latitude + i >= grid->taille || longitude < 0 || longitude >= grid->taille)
                return;
            grid->Grille[latitude + i][longitude] = 'B' + num_bateau;
        }
    }
}

bool check_collision(TypeGrille *grid, int latitude, int longitude, int taille, int direction)
{
    if (direction == 0) // horizontal
    {
        if (longitude + taille > grid->taille) return true;
        for (int j = 0; j < taille; j++)
        {
            if (grid->Grille[latitude][longitude + j] != '.')
                return true;
        }
    }
    else // vertical
    {
        if (latitude + taille > grid->taille) return true;
        for (int i = 0; i < taille; i++)
        {
            if (grid->Grille[latitude + i][longitude] != '.')
                return true;
        }
    }
    return false;
}

void tirer (Joueur *joueur, int latitude, int longitude, int *tour)
{
    if (latitude < 0 || latitude >= joueur->grille.taille || longitude < 0 || longitude >= joueur->grille.taille) {
        printf("Coordonnées hors limites\n");
        return;
    }else
    {
        printf("tire en %d %d\n", latitude, longitude);
        if (check_touche(joueur->grille, latitude, longitude))
        {
            printf("BOOM\n");
            joueur->grille.Grille[latitude][longitude] = 'X';
            if (joueur->nb_bateau > 0) joueur->nb_bateau--;
        }
        else
        {
            printf("plouf\n");
            joueur->grille.Grille[latitude][longitude] = 'O';
            if (*tour == 1)
            {
                *tour = 0;
            }else
            {
                *tour = 1;
            }
        }
    }
}

bool check_touche (TypeGrille grid, int latitude, int longitude){
    return grid.Grille[latitude][longitude] != '.' && grid.Grille[latitude][longitude] != 'X' && grid.Grille[latitude][longitude] != 'O';
}

void generer_bateaux_aleatoire(TypeGrille *grille, int nb_bateaux)
{
    int tailles[] = TAILLES_BATEAUX;
    int latitude, longitude, direction;
    
    for(int i = 0; i < nb_bateaux; i++)
    {
        bool place = false;
        int tentatives = 0;
        
        while (!place && tentatives < 100)
        {
            latitude = rand() % SIZE;
            longitude = rand() % SIZE;
            direction = rand() % 2;
            
            if (!check_collision(grille, latitude, longitude, tailles[i], direction))
            {
                add_bateau(grille, latitude, longitude, tailles[i], direction, i);
                place = true;
            }
            tentatives++;
        }
        
        if (!place)
        {
            printf("Impossible de placer le bateau %d après 100 tentatives\n", i);
            i--; // Réessayer ce bateau
            // Réinitialiser la grille pour ce bateau
            for(int l = 0; l < SIZE; l++)
                for(int c = 0; c < SIZE; c++)
                    if(grille->Grille[l][c] == 'B' + i)
                        grille->Grille[l][c] = '.';
        }
    }
}

void tire_aleatoire(Joueur *joueur, int *tour)
{
    int latitude = rand() % SIZE;
    int longitude = rand() % SIZE;
    tirer(joueur, latitude, longitude, tour);
}






void tirer_UI(Joueur *joueur, int *tour){
    int latitude;
    int longitude;
    printf("Entrez les coordonnées de tir (ligne colonne) :");
    scanf("%d %d", &latitude, &longitude);
    tirer(joueur, latitude, longitude, tour);
}

void placage_bateaux_UI(TypeGrille *grille, int nb_bateaux)
{
    int latitude, longitude, direction, taille;
    int tailles[] = TAILLES_BATEAUX;
    
    for(int i = 0; i < nb_bateaux; i++)
    {
        bool place = false;
        taille = tailles[i];
        
        while (!place)
        {
            affiche_grille(*grille);
            printf("\nBateau %d (taille %d)\n", i + 1, taille);
            printf("Entrez les coordonnées (ligne colonne) : ");
            scanf("%d %d", &latitude, &longitude);
            printf("Direction (0 = horizontal, 1 = vertical) : ");
            scanf("%d", &direction);
            
            if (check_collision(grille, latitude, longitude, taille, direction))
            {
                printf("Collision détectée ! Veuillez replaces le bateau.\n");
            }
            else
            {
                add_bateau(grille, latitude, longitude, taille, direction, i);
                printf("Bateau placé avec succès !\n");
                place = true;
            }
        }
    }
    printf("Placement terminé !\n");
}

void sauvegarder(Joueur joueur, Joueur ordinateur)
{
    FILE* f = fopen(CHEMIN_SAUVEGARDE, "w");
    if(f != NULL)
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                fprintf(f, "%d ", joueur.grille.Grille[i][j]);
            }
        }
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                fprintf(f, "%d ", ordinateur.grille.Grille[i][j]);
            }
        }
        printf("Partie sauvegardée avec succès !\n");
    } else {
        printf("Erreur lors de la sauvegarde !\n");
    }
    fclose(f);
}

void charger(Joueur *joueur, Joueur *ordinateur, bool *chargement_reussi)
{
    FILE* f = fopen(CHEMIN_SAUVEGARDE, "r");
    if(f != NULL)
    {
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                int val;
                fscanf(f, "%d", &val);
                joueur->grille.Grille[i][j] = (char)val;
            }
        }
        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                int val;
                fscanf(f, "%d", &val);
                ordinateur->grille.Grille[i][j] = (char)val;
            }
        }
        *chargement_reussi = true;
        fclose(f);
    } else {
        printf("Aucun fichier de sauvegarde !\n");
        *chargement_reussi = false;
    }
}

void menu_principal(void)
{
    printf("\n========== BATAILLE NAVALE ==========\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger une partie\n");
    printf("3. Quitter\n");
    printf("=====================================\n");
    printf("Choix : ");
}

void jouer_partie(Joueur joueur, Joueur ordinateur, int tour)
{
    while (joueur.nb_bateau > 0 && ordinateur.nb_bateau > 0)
    {
        printf("\n--- Etat des grilles ---\n");
        printf("Joueur (vos bateaux) :\n");
        affiche_grille(joueur.grille);

        if (tour == 0)
        {
            printf("\nVotre tour.\n");
            int choix_action;
            printf("1. Tirer\n");
            printf("2. Sauvegarder et quitter\n");
            printf("Choix : ");
            scanf("%d", &choix_action);

            if (choix_action == 1)
            {
                tirer_UI(&ordinateur, &tour);
            }
            else if (choix_action == 2)
            {
                char confirmation;
                printf("Êtes-vous sûr ? (o/n) : ");
                scanf(" %c", &confirmation);
                if (confirmation == 'o' || confirmation == 'O')
                {
                    sauvegarder(joueur, ordinateur);
                    printf("Partie sauvegardée. Au revoir !\n");
                    return;
                }
            }
        }
        else
        {
            printf("\nTour du bot.\n");
            tire_aleatoire(&joueur, &tour);
        }
    }

    if (joueur.nb_bateau <= 0) printf("\nLe bot a gagné !\n");
    else printf("\nVous avez gagné !\n");
    printf("\n--- Etat final des grilles ---\n");
    printf("Joueur (vos bateaux) :\n");
    affiche_grille(joueur.grille);
    printf("Bot :\n");
    affiche_grille(ordinateur.grille);

    char rejouer;
    printf("\nVoulez-vous rejouer ? (o/n) : ");
    scanf(" %c", &rejouer);
    // La réponse est gérée par le main
}

bool charger_partie_existante(Joueur *joueur, Joueur *ordinateur)
{
    bool chargement_reussi = false;
    charger(joueur, ordinateur, &chargement_reussi);
    return chargement_reussi;
}