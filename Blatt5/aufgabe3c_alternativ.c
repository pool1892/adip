#include <stdio.h>
#include <stdlib.h>

typedef struct ComplexStruct Complex;
typedef struct VectStruct Vect;

///INITIALISIERUNG KOMPLEXZAHLFUNKTIONEN
struct ComplexStruct{
	double real; double imag;
};

Complex addComp(Complex, Complex);
Complex subComp(Complex, Complex);
Complex multComp(Complex, Complex);
Complex divComp(Complex, Complex);
Complex conjComp(Complex);
void printComp(Complex);
Complex readComp(void);

///INITIALISIERUNG VEKTORFUNKTIONEN
struct VectStruct{
	Complex * dim; //dynamisches Array mit komplexen Zahlen als Einträge
	int dimension; //Speichert Arraylänge
};

Vect* newVect(int);
void delVect(Vect *);
Vect* addVect(Vect*, Vect*);
Vect* scalarmult(Complex, Vect*);
Complex multVect (Vect *, Vect *);
void printVect(Vect *);
Vect* readVect(void);

///DEKLARATION KOMPLEXZAHLFUNKTIONEN
Complex addComp(Complex i, Complex j){
	Complex result={0,0};
	result.real=i.real+j.real;
	result.imag=i.imag+j.imag;

	return result;
};

Complex subComp(Complex i, Complex j){
	Complex result={0,0};
	result.real=i.real-j.real;
	result.imag=i.imag-j.imag;

	return result;
}

Complex multComp(Complex i, Complex j){
	Complex result={0,0};
	result.real=i.real*j.real-i.imag*j.imag;
	result.imag=i.imag*j.real+i.real*j.imag;

	return result;
};

Complex divComp(Complex i, Complex j){
	Complex result={0,0};
	result.real=((i.real*j.real)+(i.imag*j.imag))/((j.imag*j.imag)+(j.real*j.real));
	result.imag=((i.imag*j.real)-(i.real*j.imag))/((j.imag*j.imag)+(j.real*j.real));

	return result;
}

Complex conjComp(Complex i){
	Complex result={0,0};
	result.real=i.real;
	result.imag=-i.imag;

	return result;
}

void printComp(Complex comp){
	printf("(%f,%f)", comp.real, comp.imag);
}

Complex readComp(void){
	Complex tmp = {0,0};
	printf("Welchen Realteil (double) soll die komplexe Zahl erhalten?\n>");
	scanf("%lf",&(tmp.real));
	printf("\n");
	printf("Welchen Imaginärteil (double) soll die komplexe Zahl erhalten?\n>");
	scanf("%lf",&(tmp.imag));
	printf("\n");
	return tmp;
}

///DEKLARATION VEKTORFUNKTIONEN
//Konstruktor; In Unterroutinen erzeugte Objekte bleiben durch Speicherallokierung außerhalb erhalten
Vect* newVect(int dimension){
	//Speicherallokierung des Vektors
	Vect *tmp = malloc (sizeof(Vect));
	if(tmp == NULL){
		printf("newVektor fehlgeschlagen\n");
		return NULL;
	}
	//Speicherallokierung des Complexarrays nur bei erfolgreicher Speicherallokierung des Vektors
	tmp->dim = malloc(dimension*sizeof(Complex));
	if(tmp->dim == NULL){
		free (tmp->dim);
		free (tmp);
		printf("newVektor fehlgeschlagen\n");
		return NULL;
	}
	tmp->dimension = dimension;
	return tmp;
}

//Destruktor; Gibt allokierten Speicher der Objekte wieder frei
void delVect(Vect *vec){
	free(vec->dim); //gibt Speicher der Arrayeinträge frei
	free(vec);		//gibt Pointer auf Array frei und Integer der Dimension
}

Vect* addVect(Vect *vec1, Vect *vec2){
	int dim = vec1->dimension;
	//Falls inkompatible Vektordimensionen, return NULL
	if( dim != vec2->dimension ){
		printf("Inkompatible Dimensionen in Vektoraddition\n");
		return NULL;
	}
	//Sonst: Komponentenweise Addition der Vektoren
	else{
		Vect *result = newVect(dim);
		for (int count=0; count<dim; count++){
			result->dim[count].real = vec1->dim[count].real + vec2->dim[count].real;
			result->dim[count].imag = vec1->dim[count].imag + vec2->dim[count].imag;
		}
		return result;
	}
}

Vect* scalarmult(Complex comp, Vect *vec){
	int dim = vec->dimension;
	Vect * result = newVect(dim);
	//Komponentenweise Komplexzahlmultiplikation
	for(int count = 0; count<dim; count++)
		result->dim[count] = multComp(comp,vec->dim[count]);
	return result;
}

Complex multVect (Vect *vec1, Vect *vec2){
	Complex result = {0,0};
	int dim = vec1->dimension;
	//Falls inkompatible Vektordimensionen, return 0+0i
	if(dim != vec2->dimension){
		printf("inkompatible Dimensionen in Vektormultiplikation");
		return result;
	}
	//Sonst: Addition der komponentenweisen Produkte
	for(int count = 0; count<dim; count++){
		result = addComp(result, multComp(vec1->dim[count], vec2->dim[count]));
	}
	return result;	
}

void printVect(Vect *vec){
	//Falls Vektor leer, gib es zu!
	if(vec == NULL || vec->dim == NULL) printf("Vektor ist leer");
	else{
		int i=0;
		printf("[");
		while(i<(vec->dimension-1)){
			printf("(%f,%f), ",vec->dim[i].real, vec->dim[i].imag);
			i++; 
		}
		//Gesonderte Ausgabe der letzten Komponente verhindert unschöne Ausgabe mit Komma und Leerzeichen am Ende
		printf("(%f,%f)",vec->dim[vec->dimension-1].real, vec->dim[vec->dimension-1].imag); 
		printf("]");
	}
}

//Einlesen eines Vektors über die Konsole
Vect* readVect(void){
	//Dimensionseingabe
	int dim=0;
	do{
		printf("Welche Dimension (integer>0) soll der Vektor haben?\n>");
		scanf("%d", &dim);
		printf("\n");
		if(dim<1) printf("Die eingegebene Dimension ist nicht zulässig\n");
	}while(dim<1);
	//Speicherallokierung für Vektor
	Vect *vec;
	vec = newVect(dim);
	//Komponenteneingabe
	for(int i=0; i<dim; i++){
		printf("Bitte gib nun die komplexe Zahl für die %d-te Komponente des Vektors ein.\n", i+1);
		vec->dim[i] = readComp();
	}
	return vec;
}


int main(){
	int choice = 0, count = 0;
	//Eingabe, welche Berechnung getaetigt werden soll
	do{
		if(count>0){
			printf("Unzulässige Eingabe. Bitte wähle 1, 2 oder 3 aus.\n");
			if(count == 5){
				printf("Hab's mir anders überlegt. Du bist eine Stromverschwendung.");
				return 0;
			}
		}
		count++;	
		printf("Welche Berechnung soll durchgeführt werden?\n");
		printf("'1':Vektoraddition\n'2':Skalarmultiplikation\n'3'Vektormultiplikation\n>");
		scanf("%d", &choice);
		printf("\n\n");
	}while(choice < 1 || choice > 3);
	//bei zulaessiger Eingabe die geforderte Berechnung ausfuehren
	switch(choice){
		case 1:
			printf("Gewählte Berechnung: Vektoraddition\n");
			//Einlesen der beiden Vektoren
			printf("Bitte gib folgende Informationen zu Vektor1 an:\n");
			Vect *vec1 = readVect();
			printf("\n");
			printf("Vektor1 = ");printVect(vec1); printf("\n");
			printf("\n\n");

			printf("Bitte gib folgende Informationen zu Vektor2 an:\n");
			Vect *vec2 = readVect();
			printf("\n");
			printf("Vektor2 = ");printVect(vec2); printf("\n");
			printf("\n\n");
			//Berechnung
			Vect *result1 = addVect(vec1, vec2);
			//Ergebnisausgabe
			printf("  "); printVect(vec1); printf("\n+ "); printVect(vec2); printf("\n= "); printVect(result1); printf("\n");
			//Speicherfreigabe
			delVect(vec1);
			delVect(vec2);
			delVect(result1);
			break;
		case 2:
			printf("Gewählte Berechnung: Skalarmultiplikation\n");
			//Einlesen des Vektors und Skalars
			printf("Bitte gib folgende Informationen zum Vektor an:\n");
			Vect *vec = readVect();
			printf("\n");
			printf("Vektor = ");printVect(vec); printf("\n");
			printf("\n\n");

			printf("Bitte gib folgende Informationen zum Skalar an:\n");
			Complex scalar = readComp();
			printf("\n");
			printf("Skalar = ");printComp(scalar); printf("\n");
			printf("\n\n");
			//Berechnung
			Vect *result2 = scalarmult(scalar, vec);
			//Ergebnisausgabe
			printf("  "); printVect(vec); printf("\n* "); printComp(scalar); printf("\n= "); printVect(result2); printf("\n");
			//Speicherfreigabe
			delVect(vec);
			delVect(result2);
			break;
		case 3:
			printf("Gewählte Berechnung: Vektormuliplikation\n");
			//Einlesen der beiden Vektoren
			printf("Bitte gib folgende Informationen zu Vektor1 an:\n");
			Vect *vec3 = readVect();
			printf("\n");
			printf("Vektor1 = ");printVect(vec3); printf("\n");
			printf("\n\n");

			printf("Bitte gib folgende Informationen zu Vektor2 an:\n");
			Vect *vec4 = readVect();
			printf("\n");
			printf("Vektor2 = ");printVect(vec4); printf("\n");
			printf("\n\n");
			//Berechnung
			Complex result3 = multVect(vec3, vec4);
			//Ergebnisausgabe
			printf("  "); printVect(vec3); printf("\n* "); printVect(vec4); printf("\n= "); printComp(result3); printf("\n");
			//Speicherfreigabe
			delVect(vec3); 
			delVect(vec4);
			break;
		default: 
			//Easteregg
			printf("Wenn dieser Text erscheint, ist irgendwas vermutlich richtig schief gelaufen.");
	}
	return 0;
}
