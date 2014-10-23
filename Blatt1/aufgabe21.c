#include <stdio.h>
int main(void)
{
    int input, result = 0;
    printf("Welche Zahl soll summiert werden?\n");
    scanf("%d", &input);
    for(int i = 1; i <= input; i++) { 
        result += i;
}
    printf("Die Gauss-Summe von %d ist %d\n", input, result);
return 0; }