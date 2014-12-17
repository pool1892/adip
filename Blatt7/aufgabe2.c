#include <stdio.h>
#include <stdlib.h>

typedef struct
{
char nachname[30];
float note;
} student;
typedef struct {
	student *member;
	int groesse;
} course;


int main(){
int anzahl;
int i;
float max=5;
float average=0.0;
printf("Wie viele Studenten sind in der Klasse?\n");
scanf("%d", &anzahl);
printf("Ok, %d Studenten\n", anzahl);
course *kl=malloc(sizeof(course));
kl->groesse = anzahl;
kl->member = malloc(anzahl*sizeof(student));
//student klasse[anzahl];
for (i=0; i<anzahl;i++){
printf("\nDer Name von Student %d?\n", i+1 );
scanf("%s", kl->member[i].nachname);
printf("Der Name von Student %d wurde eingetragen als: %s \n",i+1, kl->member[i].nachname);
printf("Welche Note hat Student %d erhalten?\n",i+1 );

scanf("%f", &kl->member[i].note);
while (kl->member[i].note>5 | kl->member[i].note<1){
   printf("Diese Note ist nicht legal\nBitte gib eine andere ein.\n");
   scanf("%f", &kl->member[i].note);
}
printf("Der Note von Student %d wurde eingetragen als: %f \n",i+1, kl->member[i].note);

}

for (i=0;i<anzahl;i++){
if (kl->member[i].note<max){max=kl->member[i].note;}
}
printf("Die beste vergebene Note ist %f\n\n", max );
printf("Die folgenden Studenten haben die beste Note:\n");
for (i=0;i<anzahl;i++){
   if (kl->member[i].note==max) printf("%s hat eine %f\n", kl->member[i].nachname, max);
}
for (i=0;i<anzahl;i++){
average+=kl->member[i].note;
}
average=average/anzahl;
printf("Die Durchschnittsnote ist %f\n", average );
   return 0;
}