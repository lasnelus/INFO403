#include <stdio.h>

#include "fonctions.h"

void main(void)
{
    int mon_entier = 3;
    printf("%d\n", mon entier);
    multiplie_par_7(&mon_entier);
    printf("%d\n", mon_entier)

    scanf("%d\n", &mon_entier);
}

void multiplie_par_7(int *n)
{
    *n = 7 * (*n);
}