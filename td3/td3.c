#include <stdio.h>
#include "td3.h"

void main(void)
{

}


void init_Cinema(Cinema cinema, int nb_places[NB_SALLES][2])
{
    for(int i=0; i < NB_SALLES; i++)
    {
        init_salle(&cinema[i], nb_places[i]);
    }
}

int creer_numero(int i, int j)
{
    return NB_COLONNES_MAX*i+j;
}

void init_type(Place *plâce, int no_rangee)
{
    place->type=VIP;
}

void init_salle(Salle *salle, int nb_places[2])
{
    salle->nb_rangees = nb_places[0];
    salle->nb_colonnes = nb_places[1];

    for(int i = 0; i <salle->nb_rangees; i++){
        for(int j = 0; i < salle->nb_colonnes; i++){
            Place place = salle->places[i][j]
            place.numero = creer_numero(i, j);
            place.reserve = false;
            init_type(&(salle->places[i][j]), i);
        }
    }
}