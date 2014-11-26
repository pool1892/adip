#include <stdio.h>
struct KomplexStruct{double real; double imag;};
typedef struct KomplexStruct Komplex;
Komplex add(Komplex, Komplex);
Komplex sub(Komplex, Komplex);
Komplex mult(Komplex, Komplex);
Komplex div(Komplex, Komplex);
Komplex conjunct(Komplex);
int main(){
double real1,imag1,real2,imag2;
printf("Wir machen Komplexzahlarithmetik.\n");
printf("Bitte den Realteil der ersten Zahl eingeben!\n");
scanf("%lf", &real1);
printf("Bitte den Imaginärteil der ersten Zahl eingeben!\n");
scanf("%lf", &imag1);
printf("Bitte den Realteil der zweiten Zahl eingeben!\n");
scanf("%lf", &real2);
printf("Bitte den Imaginärteil der zweiten Zahl eingeben!\n");
scanf("%lf", &imag2);

Komplex test1={real1,imag1}, test2={real2, imag2}, testadd, testsub, testmult, testdiv, test1conj, test2conj;
testadd=add(test1, test2);
testsub=sub(test1, test2);
testmult=mult(test1, test2);
testdiv=div(test1, test2);
test1conj=conjunct(test1);
test2conj=conjunct(test2);
printf("Die erste eingegebene Zahl ist %lf + %lf i\n",test1.real, test1.imag );
printf("Die zweite eingegebene Zahl ist %lf + %lf i\n",test2.real, test2.imag );

printf("(%lf + %lf i) + (%lf + %lf i) = (%lf + %lf i)\n",test1.real, test1.imag, test2.real, test2.imag, testadd.real, testadd.imag );
printf("(%lf + %lf i) - (%lf + %lf i) = (%lf + %lf i)\n",test1.real, test1.imag, test2.real, test2.imag, testsub.real, testsub.imag );
printf("(%lf + %lf i) * (%lf + %lf i) = (%lf + %lf i)\n",test1.real, test1.imag, test2.real, test2.imag, testmult.real, testmult.imag );
printf("(%lf + %lf i) / (%lf + %lf i) = (%lf + %lf i)\n",test1.real, test1.imag, test2.real, test2.imag, testdiv.real, testdiv.imag );

printf("Die zu %lf + %lf i konjungierte Zahl ist %lf + %lf i.\n",test1.real, test1.imag, test1conj.real, test1conj.imag );
printf("Die zu %lf + %lf i konjungierte Zahl ist %lf + %lf i.\n",test2.real, test2.imag, test2conj.real, test2conj.imag );
	





	return 0;


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