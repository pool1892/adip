
#include <stdio.h>
void fibonacci();
void parameter();
void structure();
long fib_rec(long);
int prog52();

int main(){
int auswahl=0;
while(1){
auswahl=0;

printf("Welche Aufgabe soll ausgeführt werden?\n1: Fibonacci\n2: Parameterübergabe\n3: Structs\n0: Beenden\n");
scanf("%d", &auswahl);


if(auswahl==0) {printf("\n");break;}
else if (auswahl==1) {fibonacci();printf("\n");}
else if (auswahl==2){parameter();printf("\n");}
else if (auswahl==3){structure();printf("\n");}
else {printf("Diese Eingabe entspricht keiner Zahl.\n\n");}



}
return 0;
}

//////////////////////////////////////////////////////////////////////////////
////////////////////////////////   Aufgaben   ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Blatt 5
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 1
void fibonacci(){
printf("\nBerechne Fibnoacci-Zahl\n");
int zahl=0;
	printf("Für welche Zahl soll die Fibonacci-Nummer ausgerechnet werden?\n");
	scanf("%d", &zahl);

printf("\nDie Fibonacci-Nummer von %d ist %ld.\n\n", zahl, fib_rec(zahl));

}
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 2
void parameter(){
prog52();


}
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 3
void structure(){
printf("Test3\n");

}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////   Hilfsfunktionen   ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Blatt 5
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 1
long fib_rec(long n){
if (n==0) return 0;
if (n==1) return 1;
else return (fib_rec(n-1)+fib_rec(n-2));
}
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 2
void cbR(int *x) {
printf("Ergebnis 1: %d.\n", *x); //Schreib x (mit pointer *x) hin
(*x) += 12; //+= 12 auf den wert, der in x steht
printf("Ergebnis 2: %d.\n", *x); //schreib den wert x hin, hat sich geaendert
}
void cbV(int x) {
printf("Ergebnis 4: %d. \n", x); //schreib x hin
x += 12; //addiere 12 zur temporaeren var x
printf("Ergebnis 5: %d.\n", x); schreib wieder x hin
}
int prog52() {
int a=10; // a ist 10
cbR(&a);//rufe cbr mit der adresse von a auf
printf("Ergebnis 3: %d.\n", a); //nach dem Aufruf von cbR hat a sich geandert, weil *x+=12
cbV(a);
printf("Ergebnis 6: %d.\n", a); //hier hat sich nichts geaendert, weil cbV eine temporaere Kopie von a erstellt hat
return 0; }
//////////////////////////////////////////////////////////////////////////////
// Aufgabe 3
