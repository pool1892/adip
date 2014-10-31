#include <stdio.h>
int main(void)
{
    int zahl;
    printf("Für welche Zahl soll die Länge der Collatz-Folge berechnet werden?\n");
    scanf("%d", &zahl);
	if (zahl<=0) {
	printf("Die Collatz-Folge ist für %d nicht definiert. \n", zahl);
	}
	else{
		printf("Die Zahl der Schritte, um das erste Mal 1 zu errreichen sind %d\n", collatz(zahl));
	}
return 0;}
int i=1;
int collatz(n){


if (n==1)
	return i;
else if (n % 2==0) {i++;
	return(collatz(n / 2));}
else {i++;
 return(collatz(3*n + 1));
}
}