#include <stdio.h>

#include "fonction.h"


void main(void)
{
    int taille = 10;
    int tab[10];
    super_UI(tab, taille);
}

int addition_liste (int tab[], int taille)
{
    int res = 0;
    for(int i = 0; i<taille; i++){
        res = res + tab[i];
    }
    return res;
}

int min_liste (int tab[], int taille)
{
    int res = tab[0];
    for(int i = 1; i<taille; i++){
        if (tab[i]>res){
            res = tab[i];
        }
    }
    return res;
}

int max_liste (int tab[], int taille)
{
    int res = tab[0];
    for(int i = 1; i<taille; i++){
        if (tab[i]<res){
            res = tab[i];
        }
    }
    return res;
}

int moyennne_sport(int tab[], int taille)
{
    int min = min_liste(tab, taille);
    int max = max_liste(tab, taille);
    int add = addition_liste(tab, taille);

    return (addition_liste-(min + max))/taille; //taille -2 potentiellement
}


void super_UI(int tab[], int taille)
{
    for(int i = 0; i <taille; i++){
        printf("chiffre n° %d", i+1);
        scanf("%d", tab[i]);
    }
    printf("%d", moyenne_sport(tab, taille))
}