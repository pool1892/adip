#include <stdlib.h> //fuer malloc(), realloc()
#include <stdio.h>	//fuer printf
#include <time.h>	//fuer clock() und time()
#include <math.h>	//fuer pow()

typedef struct DynArray{
	int actSize;
	int maxSize;
	int* arr;
} DynArray;

typedef struct DynArrayMin{
	int actSize;
	int* arr;
} DynArrayMin;

/*-------------------------------------------------------------------------*/
/* Funktionendeklaration */
DynArray* newDynArray();
void reallocDynArray(DynArray*);
void appendDynArray(int, DynArray*);
void freeDynArray(DynArray*);

DynArrayMin* newDynArrayMin();
void reallocDynArrayMin(DynArrayMin*);
void appendDynArrayMin(int, DynArrayMin*);
void freeDynArrayMin(DynArrayMin*);

void insertSortDynArray(int, DynArray*);
void insertSortDynArrayMin(int, DynArrayMin*);

/*-------------------------------------------------------------------------*/
DynArray* newDynArray(){
	/* malloct ein neues DynArray und setzt actSize=0, maxSize=1 */
	 DynArray* dynarr = malloc(sizeof(DynArray));
	 dynarr->actSize = 0;
	 dynarr->maxSize = 1;
	 /*	Das eigentliche Array muss seperat gemalloct werden, da 
		malloc(sizeof(DynArray)) nur Platz fuer den int Pointer reserviert */
	 dynarr->arr  = malloc (sizeof(int));
	 return dynarr;
}

void reallocDynArray(DynArray* dynarr){
	/* Zwischenspeichern der DynArray Eintraege */
	int* temparr = malloc(dynarr->actSize * sizeof(int));
	for(int i = 0; i < dynarr->actSize; i++)
		temparr[i] = dynarr->arr[i];
	/* Verdopplung des DynArray Speicherplatzes */
	realloc(dynarr->arr, (dynarr->maxSize * 2) * sizeof(int));
	dynarr->maxSize *= 2;
	/* Wiedereinfuegen der zwischengespeicherten Werte */
	for(int i = 0; i < dynarr->actSize; i++)
		dynarr->arr[i] = temparr[i];
	free(temparr);
}

void appendDynArray(int data, DynArray* dynarr){
	/* 	Falls maxSize durch append ueberschritten wuerde, realloc den Speicherplatz */
	if(dynarr->maxSize == dynarr->actSize)
		reallocDynArray(dynarr);
	/* Anhaengen des Elements, mit Anpassung von actSize */
	dynarr->arr[dynarr->actSize] = data;
	dynarr->actSize += 1;	
}

void freeDynArray(DynArray* dynarr){
	/* 	ein kleiner, aber wegen seperater Allokierung des 
		Arrayspeicherplatzes notwendiger Destruktor */
	free(dynarr->arr);
	free(dynarr);
}

/*-------------------------------------------------------------------------*/
DynArrayMin* newDynArrayMin(){
	 DynArrayMin* dynarr = malloc(sizeof(DynArrayMin));
	 dynarr->actSize = 0;
	 /* Pseudomalloc, damit realloc funktioniert */
	 dynarr->arr  = malloc(0 * sizeof(int));
	 return dynarr;
}

void reallocDynArrayMin(DynArrayMin* dynarr){
	int* temparr = malloc(dynarr->actSize * sizeof(int));
	for(int i = 0; i < dynarr->actSize; i++)
		temparr[i] = dynarr->arr[i];
	/* Erweiterung des Arrayspeicherplatzes um 1 int-Speicherplatz */
	realloc(dynarr->arr, (dynarr->actSize + 1) * sizeof(int));
	for(int i = 0; i < dynarr->actSize; i++)
		dynarr->arr[i] = temparr[i];
	free(temparr);
}

void appendDynArrayMin(int data, DynArrayMin* dynarr){	
	/* keine if-Abfrage, da bei diesem Datentyp immer maxSize == actSize */
	reallocDynArrayMin(dynarr);
	dynarr->arr[dynarr->actSize] = data;
	dynarr->actSize += 1;	
}

void freeDynArrayMin(DynArrayMin* dynarr){
	free(dynarr->arr);
	free(dynarr);
}

/*-------------------------------------------------------------------------*/
void insertSortDynArray(int data, DynArray* dynarr){
	int tmp;
	if(dynarr->maxSize == dynarr->actSize)
		reallocDynArray(dynarr);
	/* 	Einfuegen wie bei Insertionsort:
		neues Element am Ende einfuegen und solange nach vorne rutschen lassen, 
		bis das linke Nachbarelement nicht mehr groesser ist*/
	dynarr->arr[dynarr->actSize] = data;
	/* 	mit && veknuepfte for-Bedingung erlaubt Abbruch, 
		wenn passender Einfuegeplatz des Elements gefunden ist */
	for(int i = dynarr->actSize-1; i > 0 && dynarr->arr[i] > data; i--){
		tmp = dynarr->arr[i+1];
		dynarr->arr[i+1] = dynarr->arr[i];
		dynarr->arr[i] = tmp;
	}
}

void insertSortDynArrayMin(int data, DynArrayMin* dynarr){
	int tmp;
	reallocDynArrayMin(dynarr);
	dynarr->arr[dynarr->actSize] = data;
	for(int i = dynarr->actSize-1; i > 0 && dynarr->arr[i] > data; i--){
		tmp = dynarr->arr[i+1];
		dynarr->arr[i+1] = dynarr->arr[i];
		dynarr->arr[i] = tmp;
	}
}

int main(){
	/* seed rand(), damit rand() nicht immer gleich Zahlenfolge ausgibt */
	srand(time(NULL));
	int WTF = 1000000;
	clock_t begin, end;
	int* pseudoRand = malloc(WTF*sizeof(int));
	DynArray* dynarr = newDynArray();
	//	"The cannons be ready, captain!"
	//	"Arr!" 
	DynArrayMin* dynPirateshout = newDynArrayMin();
	
	/* 	erzeuge Array mit Zufallszahlen, damit Laufzeitvergleich 
		durch gleiche Zahlenfolge repraesentativ ist */
	for(int i = 0; i < WTF; i++){
		pseudoRand[i] = (int)pow(-1,rand())*rand();
	}
	
	printf("Laufzeitenvergleich\n");
	printf("%d mal insertSort bei DynArray:\t", WTF);
	begin = clock();
	/* fuege Zufallszahlen mit insertSort DynArray hinzu */
	for(int i = 0; i < WTF; i++)
		insertSortDynArray(pseudoRand[i], dynarr);
	end = clock();
	printf("%d\n", end-begin);
	
	printf("%d mal insertSort bei DynArrayMin:\t", WTF);
	begin = clock();
	/* fuege Zufallszahlen mit insertSort DynArrayMin hinzu */
	for(int i = 0; i < WTF; i++)
		insertSortDynArrayMin(pseudoRand[i], dynPirateshout);
	end = clock();
	printf("%d\n", end-begin);
	
	/* Aufraeumen */
	freeDynArray(dynarr);
	freeDynArrayMin(dynPirateshout);
	free(pseudoRand);
	return 0;
}