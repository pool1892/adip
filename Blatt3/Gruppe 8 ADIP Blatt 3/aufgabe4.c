//Arithmetisches Mittel und korrigierte Varianz ausrechnen mit Array.
#include <stdio.h>
#include <math.h>


int main()
{ printf("Für wie viele Zahlen soll das arithmetische Mittel und die Varianz berechnet werden?\n");
int length=0;
 scanf("%d", &length);
int test [25][25][25][25];

double array[length], summe=0, am=0, varianzsumme=0, varianz=0; 

for (int i=0; i<length; i++){
printf ("Bitte geben Sie die Zahl Nummer %d ein.\n", i);
scanf ("%lf", &array[i]);

};

for (int i=0; i<length; i++){
summe=summe+array[i];

};
am=summe/length;
for (int i=0; i<length; i++){
varianzsumme=varianzsumme+(array[i]-am)*(array[i]-am);

};
varianz=varianzsumme/(length-1);

printf("Das arithmetische Mittel ist %lf\n", am);
printf("Die korrigierte Varianz ist %lf\n", varianz);


	return 0;
}



