// Überprüfung, ob es sich um eine Primzahl handelt

#include "stdio.h"

int main()
{
	int input,i,var=0;
	label1: printf("Welche Zahl soll überprüft werden, ob es sich bei ihr um eine Primzahl handelt?\n->");
	scanf("%d", &input);
	if(input<=0){printf("%d gehört nicht zu den natürlichen Zahlen.\n", input); goto label1;}
	if(input==2){goto label2;}
	if(input==3){goto label2;}
	for (i=2; i*i<input; i++)
	{
		if(input%i==0){var=1; break;}
	}
	label2: if(var==0){printf("%d ist eine Primzahl\n", input);}
	if(var==1){printf("%d ist keine Primzahl\n", input);}
	return 0;
}