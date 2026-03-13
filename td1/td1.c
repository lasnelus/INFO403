#include <stdio.h>

#include "fonction.h"

void main(void)
{
    int a,b,c;
    scanf(%d,%d,%d,&a,&b,&c);
}


void compte_char(void)
{
    int res = 0;
    char c = getchar();
    while (c != EOF){
        res++;
        c= getchar();
    }

    printf("Le nombre de caractères est : %d\n", res);8
}

int somme_tab(int tab[], int taille)
{
    int res = 0;
    for(int i = 0, i < taille, i++){
        res = res + tab[i];
    } 
    return res;
}

int moyenne(int a, int b, int c)
{
    return (a + b + c) / 3;
}

void principale(void)
{
    int choice;
    do{
        afficheMenu()
        scanf("%d", &choice);
        action(choice);
    }while(choice != 3);
}

void afficheMenu(void)
{
    prinf();
}

void action(int choice)
{
    switch (choice)
        {
        case 1:
            bienvenue();
            break;
        case 2:
            somme_floats()
            break;
        }
}

void bienvenue(void)
{
    char * nom = demandenom();
    printf("hello : %s", nom);
}

void somme(void)
{
    printf("deux entier stp")
}