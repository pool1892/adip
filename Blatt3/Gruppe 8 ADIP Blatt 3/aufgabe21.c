//Für gegebenen Input: Teste perfekt
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
{ printf("Welche Zahl soll getestet werden?\n");
int input=0;
 scanf("%d", &input);
 
 if (checkperfect(input)==1) {printf("%d ist perfekt.\n", input);
 }
 else {printf("%d ist defizient.\n", input);}
	return 0;
}