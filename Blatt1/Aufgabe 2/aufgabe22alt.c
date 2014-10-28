#include <stdio.h>
int main(void)
{
    int n, result = 0;
    printf("Welche Zahl soll quadratisch summiert werden?\n");
    scanf("%d", &n);
    result = (n*(n+1)*(2*n+1))/6;
    //result=((input*(input+1)*(2*input+1))/6);

    printf("Die Gauss-Quadrat-Summe von %d ist %d\n", n, result);
return 0; }