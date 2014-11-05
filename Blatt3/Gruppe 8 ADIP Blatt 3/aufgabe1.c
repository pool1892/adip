// Primfaktorzerlegung

#include <stdio.h>
#include <math.h>


int checkprime(int y){ //Check, ob eine Zahl eine Primzahl ist
int result=1;
if (y==1) {result=0;};
for(int i=2; i<y;i++){
if (y%i==0) {result=0;
break;}
}
return result;
}

int main()
{ printf("Welche Zahl soll zerlegt werden?\n");
int input=0;
 scanf("%d", &input);
 for (int i=2; i<=input; i++){ //Gehe alle Primzahlen kleiner als Input durch und teste Teilbarkeit.
 	if (checkprime(i)==1){
 		while (input%i==0){ // While, weil es multiple Primfaktoren geben kann.
 			printf("%d ist ein Primfaktor\n", i);
 			input=input/i; //Reduziere Ausgangszahl, um zu terminieren.
 		}
 	}
 }
	return 0;
}