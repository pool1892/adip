// Überprüfung, ob es sich um eine Primzahl handelt

#include <stdio.h>
#include <math.h>
int main()
{
	int input,i,var;
	label1: printf("Welche Zahl soll überprüft werden, ob es sich bei ihr um eine Primzahl handelt?\n->");
	scanf("%d", &input);
	if(input<=0){printf("%d gehört nicht zu den natürlichen Zahlen.\n", input); goto label1;}
	for (i=2; i<(int)(sqrt(input))+1; i++)
	{
		if(input%i==0){var=1; break;}
		else{var=0;}
	}
	if(var==0){printf("%d ist eine Primzahl\n", input);}
	if(var==1){printf("%d ist keine Primzahl\n", input);}
	return 0;
}