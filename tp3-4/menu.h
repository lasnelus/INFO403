#ifndef MENU_H
#define MENU_H

#include "annuaire.h"

void affiche_menu(Annuaire *annuaire);
void affiche_menu_ajout(Annuaire *annuaire);
void affiche_menu_recherche(Annuaire annuaire);
void affiche_menu_extraction(Annuaire annuaire);
void affiche_menu_suppression(Annuaire *annuaire);
void affiche_menu_fusion(Annuaire *annuaire);

#endif