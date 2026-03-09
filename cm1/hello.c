#include <stdio.h>

void main(void)
{
    printf("Hello, World!\n");
    printf("%f et %d", 4.2, 6)

    int mon_premier_eniter_en_403 = 4;
    float flottant = 2.3f;

    char * chaine = "hello";

    printf("voici ma chaine : %s\n", chaine);

    for (int i = 0; i < 10; i++) {
        printf("i = %d\n", i);
    }

    char c;
    while (c != 'a'){
        putchar(c);
        c= getchar();
    }
}