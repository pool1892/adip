/* Programm zum Blatt 4 */

#include "stdio.h"

int prog11 (void);
int arith11(int x,int y);
int prog12 (void);
int arith12(int w,int z);
int prog21 (void);
int arith21(int inp21);
int prog22 (void);
int arith221(int men1, int teil1);
int arith222(int men2, int teil2);
int prog23(void);
int prog3(void);



int main ()
{
	int task, subtask;
	while (1){
	printf("Das ist das Programm zum 4. Übungsblatt. Bitte wählen sie eine Aufgabe:\n 1: Potenzierung\n 2: Rekursive Funktion\n 3: Matrizenmultiplikation\n 4: Exit\n->");
	scanf("%d", &task);
	if (task==1){
		printf("Aufgabentyp 1 oder 2?\n->"); scanf("%d", &subtask);
		if(subtask==1)
			prog11( );
		if(subtask==2)
			prog12( );
	}
	if (task==2){
		printf("Aufgabentyp 1,2 oder 3?\n->"); scanf("%d", &subtask);
		if(subtask==1)
			prog21( );
		if(subtask==2)
			prog22( );
		if(subtask==3)
			prog23( );
	}
	if (task==3){
		prog3( );
	}
	if (task==4){
		break;
	}
	}
	return 0;
}

int prog11 (void)
{
	int a, n;
	printf("Geben sie eine Basis an.\n->");
	scanf("%d", &a);
	printf("Geben sie einen Exponenten an.\n->");
	scanf("%d", &n);
	printf("Das Ergebnis ist %d.\n\n", arith11(a, n));
	return 0;
}
int arith11(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	else return(x*arith11(x, y-1));
}

int prog12 (void)
{
	int b, m;
	printf("Geben sie eine Basis an.\n->");
	scanf("%d", &b);
	printf("Geben sie einen Exponenten an.\n->");
	scanf("%d", &m);
	printf("Das Ergebnis ist %d.\n\n", arith12(b, m));
	return 0;
}
int arith12(int w,int z)
{
	if(z==0) return 1;
	if(z==1) return w;
	if(z%2==0){
		return(arith12(w, z/2)*arith12(w, z/2));
	}
	else return(w*arith12(w, (z-1)/2)*arith12(w, (z-1)/2));
}

int prog21 (void)
{
	int input21;
	printf("Geben sie eine Zahl an, deren Fakultät sie berechnen wollen.\n->");
	scanf("%d", &input21);
	printf("Das Ergebnis: %d!=%d.\n\n", input21, arith21(input21));
	return 0;
}
int arith21(int inp21)
{
	if(inp21==1) return 1;
	else return(inp21*arith21(inp21-1));
}

int prog22 (void)
{
	int menge, teilmenge;
	printf("Berechnung eines Binomialkoeffizienten. Geben sie eine Menge ein.\n->");
	scanf("%d", &menge);
	printf("Geben sie eine Teilmenge an.\n->");
	scanf("%d", &teilmenge);
	if(0<=teilmenge){
		if(teilmenge<=menge){printf("Das Ergebnis von %d über %d beträgt %d.\n\n", menge, teilmenge, arith221(menge, teilmenge)/arith222(menge, teilmenge));}
		else{printf("Das Ergebnis ist 0.\n\n");}
	}
	else{printf("Das Ergebnis ist 0.\n\n");}
	return 0;
}
int arith221(int men1, int teil1)
{
	if(men1-teil1+1==1) return 1;	
	else return(men1*arith221(men1-1, teil1));
}
int arith222(int men2, int teil2)
{
	int i, result=1;
	for(i=2;i<=teil2;i++){
		result*=i;
	}
	return result;
}

int prog23 (void)
{
	int zahln, zahlk;
	printf("Modifiziertes Lottoproblem:\nWie viele Zahlen gibt es?\n->");
	scanf("%d", &zahln);
	printf("Wie viele Zahlen werden gezogen?\n->");
	scanf("%d", &zahlk);
	printf("Bei %d möglichen Zahlen können %d Zahlen, unter Berücksichtigung der Reihenfolge, auf %d-Arten gezogen werden.\n\n", zahln, zahlk, arith221(zahln, zahlk)/arith222(zahln, zahlk)*arith21(zahlk));
	return 0;
}

int prog3 (void) // Bei dem dritten Programm sollte eigentlich vorher der Speicher mit malloc allokiert werden.
{
	int i, j, k, l, d, e, f;
	printf("Geben sie die Daten der ersten Matrix an.\nAnzahl der Zeilen->");
	scanf("%d", &i);
	printf("Anzahl der Spalten->");
	scanf("%d", &j);
	printf("Geben sie die Daten der zweiten Matrix an.\nAnzahl der Zeilen->");
	scanf("%d", &k);
	printf("Anzahl der Spalten->");
	scanf("%d", &l);
	if(j!=k){printf("Die Spaltenanzahl der ersten und die Zeilenanzahl der zweiten Matrix muss übereinstimmen!\n\n");}
	else{
		int matrix1[i][j], matrix2[k][l], ergebnis[i][l];
		printf("Bitte geben sie Werte der ersten Matrix ein.\n");
		for(d=1;d<=i;d++){
			for(e=1;e<=j;e++){
				printf("Geben sie das Element in der %d.-Zeile und %d.-Spalte an.->", d, e);
				scanf("%d", &matrix1[d-1][e-1]);
			}
		}
		printf("Bitte geben sie die Werte der zweiten Matrix ein.\n");
		for(d=1;d<=k;d++){
			for(e=1;e<=l;e++){
				printf("Geben sie das Element in der %d.-Zeile und %d.-Spalte an.->", d, e);
				scanf("%d", &matrix2[d-1][e-1]);
			}
		}
		// Initialisierung der Ergebnismatrix
		for(d=1;d<=i;d++){
			for(e=1;e<=l;e++){
			ergebnis[d-1][e-1]=0;
			}
		}
		// Berechnung der Ergebnis-Matrix
		for(d=1;d<=i;d++){
			for(e=1;e<=l;e++){
				for(f=1;f<=j;f++){
					ergebnis[d-1][e-1]+=matrix1[d-1][f-1]*matrix2[f-1][e-1];
				}
			}
		}
		printf("Das Ergebnis ist folgende Matrix:\n");
		for(d=1;d<=i;d++){
			for(e=1;e<=l;e++){
				printf("-%d-", ergebnis[d-1][e-1]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	return 0;
}