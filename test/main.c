#include <stdio.h>

void main()
{
    int a=4;
    int b=4;
    int c=*(&a);
    int *d=&b;

    printf("%d %d %d %d\n", a,b,c,*d);
    a++;
    printf("%d %d %d %d\n", a,b,c,*d);

    (*b)++
    printf("%d %d %d %d\n", a,b,c,*d);
}