//Anzahl defizienter Zahlen kleiner Input
#include <stdio.h>
#include <math.h>

int checkperfect(int z){
int summe=1;
int input=z;
for (int i=2; i<input; i++){
 		if (input%i==0){
 			summe=summe+i;
 		}
 	}

if (summe==z) return 1;
else return 0;
}
int main()
{ printf("Für welche Zahl soll die Anzahl der kleineren defizienten Zahlen berechnet werden?\n");
int input=0;
 scanf("%d", &input);
int summe=1;
 for (int i=1; i<input; i++){
if (i%50000==0)printf("wir sind bei %d\n", i);

 if (checkperfect(i)==0) {summe++;
 }
}
 printf("Es gibt %d defiziente Zahlen kleiner als %d.\n", summe, input);

	return 0;
}