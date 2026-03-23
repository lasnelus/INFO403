#include <stdio.h>

#include "td2.h"

void increment(int *pointeur)
{
    (*pointeur)++;
}

void somme(int a, int b, int *c)
{
    *c = a+b;
}

void circular(int *a, int *b, int *c)
{
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;
}

int str_lenn (char *str)
{
    int res = 0;
    while (str[res]!= "\0"){
        res++;
    };
    return res;
}

void strcopy 