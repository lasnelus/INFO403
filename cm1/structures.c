#include <stdio.h>
#include <string>

#include "structures.h"

struct Etud{
    char  nom[50];
    int age;
    float moyenne;
};
typedef struct Etud Etudiant

typedef int Element;

void main(void)
{
    Etudiant julien;
    strcpy(julien.nom, "Julien");
    julien.age = 42;

    printf("%d\n", julien.age);
    Element n = 3
}