#include <stdio.h>
#include "tp1.h"

void main(void)
{
    affiche_Grille();
}

void affiche_Grille(void)
{
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0; i<10;i++)
    {
        printf("%d",i);
        for(int j=0;j<10;j++)
        {
            // printf("%s", grid[i][j]);
            printf(".");
        }
    }
}