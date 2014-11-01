//Generiere alle perfekten Zahlen kleiner Input.
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
{ printf("Für welche Zahl sollen alle kleineren perfekten Zahlen ausgegeben werden?\n");
int input=0;
 scanf("%d", &input);
 printf("Alle kleineren perfekten Zahlen:\n");

 for (int i=5; i<input; i++){


 if (checkperfect(i)==1) {printf("%d ist perfekt.\n", i);
 }
}
 printf("Das war's.\n");

	return 0;
}