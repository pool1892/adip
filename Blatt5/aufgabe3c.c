#include <stdio.h>
struct KomplexStruct{double real; double imag;};
typedef struct KomplexStruct Komplex;
Komplex add(Komplex, Komplex);
Komplex sub(Komplex, Komplex);
Komplex mult(Komplex, Komplex);
Komplex div(Komplex, Komplex);
Komplex conjunct(Komplex);



struct Vektorraum {
	Komplex dim[3];
};
typedef struct Vektorraum Vektor;
Vektor vadd(Vektor, Vektor);
Vektor skalar(Vektor, Komplex);
Komplex vmult (Vektor, Vektor);




int main(){
//Sei n die Dimension des komplexen Vektorraums

Vektor test1;
test1.dim[0].real=1;
test1.dim[0].imag=1;
test1.dim[1].real=1;
test1.dim[1].imag=1;
test1.dim[2].real=1;
test1.dim[2].imag=1;




}

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
};
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


Vektor vadd( Vektor i, Vektor j){
Vektor result;



return result;
}
Vektor skalar(Vektor i, Komplex j){
Vektor result;



return result;
}

Komplex vmult (Vektor i, Vektor j){
Komplex result;


return result;	
}
