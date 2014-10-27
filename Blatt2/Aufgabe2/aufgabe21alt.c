#include <stdio.h>
int main(void)
{
    int zahl, expo, count=0, result;
    printf("Welche Zahl soll exponentiert werden?\n");
    scanf("%d", &zahl);
	printf("Mit welchem ganzzahligen Exponenten?\n");
    scanf("%d", &expo);
    result=zahl;
    if (expo==1) {
    printf("Das Ergebnis ist %d.\n", zahl);}
    else if (expo==0){
    	printf("Das Ergebnis ist 1.\n");
    }
	else if (expo<=0) {
	printf("Das Ergbnis wäre ein Bruch, das beachten wir nicht. \n");
	}
	else{
		for (int i=2; i<=expo;i++){
			result=result*zahl;

		}
		printf("Das Ergebnis ist %d\n", result);
	}
return 0;}