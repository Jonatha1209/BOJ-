#include <stdio.h>
int main ()
{
    int a,b,c,d,e,f,g,h,i;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    g = a*a+b*b+c*c+d*d+e*e;
    printf("%d", g%10);
}
