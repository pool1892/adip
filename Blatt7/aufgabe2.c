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
int i;
float max=5;
float average=0.0;

course *klasse=malloc(sizeof(course));
printf("Wie viele Studenten sind in der Klasse?\n");
scanf("%d", &klasse->groesse);
printf("Ok, %d Studenten\n", klasse->groesse);
klasse->member = malloc(klasse->groesse*sizeof(student));
//student klasseasse[klasse->groesse];
for (i=0; i<klasse->groesse;i++){
printf("\nDer Name von Student %d?\n", i+1 );
scanf("%s", klasse->member[i].nachname);
printf("Der Name von Student %d wurde eingetragen als: %s \n",i+1, klasse->member[i].nachname);
printf("Welche Note hat Student %d erhalten?\n",i+1 );

scanf("%f", &klasse->member[i].note);
while (klasse->member[i].note>5 | klasse->member[i].note<1){
   printf("Diese Note ist nicht legal\nBitte gib eine andere ein.\n");
   scanf("%f", &klasse->member[i].note);
}
printf("Der Note von Student %d wurde eingetragen als: %f \n",i+1, klasse->member[i].note);

}

for (i=0;i<klasse->groesse;i++){
if (klasse->member[i].note<max){max=klasse->member[i].note;}
}
printf("Die beste vergebene Note ist %f\n\n", max );
printf("Die folgenden Studenten haben die beste Note:\n");
for (i=0;i<klasse->groesse;i++){
   if (klasse->member[i].note==max) printf("%s hat eine %f\n", klasse->member[i].nachname, max);
}
for (i=0;i<klasse->groesse;i++){
average+=klasse->member[i].note;
}
average=average/klasse->groesse;
printf("Die Durchschnittsnote ist %f\n", average );
   return 0;
}