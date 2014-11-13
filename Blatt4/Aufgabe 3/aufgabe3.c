#include <stdio.h>

int main(void){
//Annahme: Matrix A liegt vor als mata[i][j]; Matrix B als matb[k][l]
int i,j, k,l; //Dimensionen der Matrizen
int multi[i][l]=0;
if (j!=k) printf("Die Dimensionen der Matrizen eignen sich nicht für die Multiplikation\n");
else {
  for (int a=0; a<i; a++){//Zeile wählen
    for (int b=0; b<l; b++){//Spalte wählen
      for (int c=0; c<j; c++){//Die Summe von Zeile und Spalte in die Ergebnismatrix schreiben.
	multi[a][b]=multi[a][b]+mata[a][c]*matb[c][b];
	}
      }
    }
  }
return 0;
}
