#include <stdio.h>

#include "tableaux.h"

void main(void)
{
    int tab[3] = {3,4,6};

    // tab[0] = 1;
    // tab[1] = 3;
    // tab[2] = 7;

    printf("%d\n", tab[1]);

    int res = power(2,6);
}

int power(int value, int exp)
{
    int res = 1;
    for(int i = 1; i <= 10; i++){
        res = res * value;
    }
    return res;
}