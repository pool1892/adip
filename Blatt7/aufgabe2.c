#include <stdio.h>


typedef struct
{
char nachname[30];
float note;
} student;



int main(){
int anzahl;
int i;
float max=5;
float average=0.0;
printf("Wie viele Studenten sind in der Klasse?\n");
scanf("%d", &anzahl);
printf("Ok, %d Studenten\n", anzahl);

student klasse[anzahl];
for (i=0; i<anzahl;i++){
printf("\nDer Name von Student %d?\n", i+1 );
scanf("%s", &klasse[i].nachname);
printf("Der Name von Student %d wurde eingetragen als: %s \n",i+1, klasse[i].nachname );
printf("Welche Note hat Student %d erhalten?\n",i+1 );

scanf("%f", &klasse[i].note);
while (klasse[i].note>5 | klasse[i].note<1){
   printf("Diese Note ist nicht legal\nBitte gib eine andere ein.\n");
   scanf("%f", &klasse[i].note);
}
printf("Der Note von Student %d wurde eingetragen als: %f \n",i+1, klasse[i].note );

}

for (i=0;i<anzahl;i++){
if (klasse[i].note<max){max=klasse[i].note;}
}
printf("Die beste vergebene Note ist %f\n\n", max );
printf("Die folgenden Studenten haben die beste Note:\n");
for (i=0;i<anzahl;i++){
   if (klasse[i].note==max) printf("%s hat eine %f\n", klasse[i].nachname, max);
}
for (i=0;i<anzahl;i++){
average+=klasse[i].note;
}
average=average/anzahl;
printf("Die Durchschnittsnote ist %f\n", average );
   return 0;
}