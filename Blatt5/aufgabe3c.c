#include <stdio.h>
struct KomplexStruct{double real; double imag;};
typedef struct KomplexStruct Komplex;
Komplex add(Komplex, Komplex);
Komplex sub(Komplex, Komplex);
Komplex mult(Komplex, Komplex);
Komplex div(Komplex, Komplex);
Komplex conjunct(Komplex);



struct Vektorraum {
	Komplex dim[3]; //////////Hier muss die Dimension natürlich angepasst werden//////////////
};
typedef struct Vektorraum Vektor;
Vektor vadd(Vektor, Vektor, int);
Vektor skalar(Vektor, Komplex, int);
Komplex vmult (Vektor, Vektor, int);




int main(){




//////////////////Vektorzeugs///////////////////////////
//Sei n die Dimension des komplexen Vektorraums
int n=3;
Komplex scaling={2,0}; /////////////Skalar///////////////////
Vektor test1, test2, test3, test4;
Komplex prod;

////////////////////////////Vektoren festlegen für 3 Dimensionen/////////
test1.dim[0].real=1;
test1.dim[0].imag=2;
test1.dim[1].real=1;
test1.dim[1].imag=3;
test1.dim[2].real=2;
test1.dim[2].imag=4;

test2.dim[0].real=2;
test2.dim[0].imag=2;
test2.dim[1].real=2;
test2.dim[1].imag=2;
test2.dim[2].real=2;
test2.dim[2].imag=2;

test3=vadd(test1,test2, n);
test4=skalar(test1, scaling, n);
prod=vmult(test1, test2, n);

printf("Vektoraddition\n");
for(int count =0; count<n; count++){
	printf("Dimension %d: (%lf + %lf i)\n", count+1, test3.dim[count].real, test3.dim[count].imag);
}

printf("Skalarmultiplikation\n");
for(int count =0; count<n; count++){
	printf("Dimension %d: (%lf + %lf i)\n", count+1, test4.dim[count].real, test4.dim[count].imag);
}
printf("Vektormultiplikation\n");
printf("Das Ergebnis ist ( %lf + %lf i)\n", prod.real, prod.imag );
}


///////////////////////Komplexzahlfunktionen//////////////////////////////////////////
Komplex add(Komplex i, Komplex j){
Komplex result={0,0};
result.real=i.real+j.real;
result.imag=i.imag+j.imag;

return result;
};



Komplex sub(Komplex i, Komplex j){
Komplex result={0,0};
result.real=i.real-j.real;
result.imag=i.imag-j.imag;

return result;
}


Komplex mult(Komplex i, Komplex j){
Komplex result={0,0};
result.real=i.real*j.real-i.imag*j.imag;
result.imag=i.imag*j.real+i.real*j.imag;

return result;
};
Komplex div(Komplex i, Komplex j){
Komplex result={0,0};
result.real=((i.real*j.real)+(i.imag*j.imag))/((j.imag*j.imag)+(j.real*j.real));
result.imag=((i.imag*j.real)-(i.real*j.imag))/((j.imag*j.imag)+(j.real*j.real));

return result;

}
Komplex conjunct(Komplex i){
Komplex result={0,0};
result.real=i.real;
result.imag=-i.imag;

return result;

}

/////////////////////////Vektorfunktionen//////////////////////////////
Vektor vadd( Vektor i, Vektor j,int n){
Vektor result;
for (int l=0;l<n; l++){
	result.dim[l].real=i.dim[l].real+j.dim[l].real;
	result.dim[l].imag=i.dim[l].imag+j.dim[l].imag;
}
return result;
}
Vektor skalar(Vektor i, Komplex j, int n){
Vektor result;
for(int count =0; count<n; count++){
result.dim[count]=mult(j,i.dim[count]);

}

return result;
}

Komplex vmult (Vektor i, Vektor j, int n){
Komplex result;
for(int count =0; count<n; count++){
result=add(result, mult(i.dim[count], j.dim[count]));

}

return result;	
}
