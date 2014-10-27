#include <stdio.h>
int main(void)
{
    int zahl, expo;
    printf("Welche Zahl soll exponentiert werden?\n");
    scanf("%d", &zahl);
	printf("Mit welchem ganzzahligen Exponenten?\n");
    scanf("%d", &expo);
	if (expo<0) {
	printf("Das Ergbnis wäre ein Bruch, das beachten wir nicht. \n");
	}
	else{
		

		
		printf("Das Ergebnis ist %d\n", exponentiation(zahl, expo));
	}
return 0;}

int exponentiation(a, n){
/*if (n==1)
	return a;*/
if (n==0)
	return 1;
else if (n%2==0) return(exponentiation(a, n/2)*exponentiation(a, n/2));
else return(a*exponentiation(a,(n-1)/2)*exponentiation(a,(n-1)/2));
}