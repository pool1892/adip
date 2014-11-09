#include <stdio.h>

int main(void){
//Annahme: Matrix A liegt vor als mata[i][j]; Matrix B als matb[k][l]
int i,j, k,l; //Dimensionen der Matrizen
int multi[i][l]=0;
if (j!=k) printf("Die Dimensionen der Matrizen eignen sich nicht für die Multiplikation\n");
else {
for (int a=1; a<=j; a++){//Zeile wählen
for (int b=1; b<=l; b++){//Spalte wähken
for (int c=1; c<=j; c++){//Die Summe von Zeile und Spalte in die Ergebnismatrix schreiben.
multi[a][b]=multi[a][b]+mata[a][c]*matb[c][b];

}
}

}


};

	return 0;
}
