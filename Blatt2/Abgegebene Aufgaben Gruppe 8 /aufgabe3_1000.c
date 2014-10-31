#include <stdio.h>
int main(void)
{
	
	int max=1;
	int zahl=1;
	for (int j=1; j<1001;j++){
if (collatz(j)>max) {
	max=collatz(j);
	zahl=j;
}
	}
	printf("Die längste Collatz-Folge der Zahlen 1 bis 1000 erzeugt die %d.\n Ihre Folge braucht %d Schritte, bis sie 1 erreicht.", zahl, max);
return 0;}
int i=1;
int collatz(n){


if (n==1) {
	int j=i;
	i=1;
	return j;
}
else if (n % 2==0) {i++;
	return(collatz(n / 2));}
else {i++;
 return(collatz(3*n + 1));
}
}