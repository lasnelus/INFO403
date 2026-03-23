#include <stdio.h>
#include "cm3.h"

typedef struct{
    float x;
    float y;
} Point;



void main(void)
{
    int n;
    printf("combien de point voulez vous ?");
    scanf("%d", &n);

    Point *points = (Point *(malloc(n * sizeof(Point))));
    
    for (int i = 0; i < n; i++){
        printf("Donnez les coordonées du point %d : \n,",i);
        scanf("%f, %f", &points[i].x, &points[i].y);
    }

    for (int i = 0; i < n; i++){
        printf("%f,%f", points[i].x, points[i].y);
    }
}