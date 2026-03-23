#include <stdio.h>

void swap(int* a, int* b);


void main (void)
{
    int a =3;
    int b = 7;

    swap(&a, &b);
}

void swap(int* a, int* b)
{
    int temp = *a;
    a = *b;
    b = temp;
}