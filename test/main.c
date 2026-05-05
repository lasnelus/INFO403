void main()
{
    int a=4;
    int b=4;
    int c=*(&a);
    int d=&b;

    printf("%d %d %d %d", a,b,c,d);
}