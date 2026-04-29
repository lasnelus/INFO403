#ifndef ANNUAIRE_H
#define ANNUAIRE_H

#include "contact.h"

#define SIZE 100



typedef struct liste_contacte {
    Contacte contacte;
    struct liste_contacte *suiv;
} *Liste_Contacte;

typedef Liste_Contacte Annuaire[SIZE];

int hash(char *name, char *first_name);

void init_annuaire(Annuaire *annuaire);

// Liste_Contacte init_liste_contacte(Contacte contacte);

void ajouter_contacte_liste_contacte(Liste_Contacte *liste_contacte, Contacte contacte);

void ajouter_contacte_annuaire(Annuaire *annuaire, Contacte contacte);

// void afficher_contacte(Contacte contacte);

void lister_contacte_annuaire(Annuaire annuaire);

void afficher_contacte_liste_contacte(Liste_Contacte liste_contacte);


void rechercher_contacte_annuaire(Annuaire annuaire, char *val, char *filtre);

void extraire_contacte_annuaire(Annuaire annuaire, char *param);


void supprimer_contacte_annuaire(Annuaire *annuaire, char *nom);

void fusionner_annuaire(Annuaire *annuaire_receveur, Annuaire annuaire_donneur);


void sauvegarder_annuaire(Annuaire annuaire, char *chemin_sauvegarde);
void charger_annuaire(Annuaire *annuaire, char *chemin_charge);


void affiche_aide(void);

#endif
// Contacte init_contacte(char *nom, char* prenom, char *tel, char *mail);


// void affiche_menu(Annuaire *annuaire);

// void affiche_menu_ajout(Annuaire *annuaire);

// void affiche_menu_recherche(Annuaire annuaire);

// void affiche_menu_extraction(Annuaire annuaire);

// void affiche_menu_suppression(Annuaire *annuaire);

// void affiche_menu_fusion(Annuaire *annuaire);