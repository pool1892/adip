#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <time.h>

/* Funktionendeklaration */
void swap(double*, int, int);
void selectionsort(double*, int);
void insertionsort(double*, int);
void bubblesort(double*, int);
void quicksort(double*, int);
void mergesort(double*, int);
void merge(double*, int, double*, int);
void printArr(double*, int);
double randBet(double, double);
void CopyFirst(double*, double*, int);

void swap(double* arr, int a, int b){
	double swap = arr[a];
	arr[a] = arr[b];
	arr[b] = swap;
}

void selectionsort(double* arr, int size){
	double min;
	int pos;	
	//Durchlaufe das Restarray ab unsortierter Stelle
	for(int i = 0; i < size-1; i++){
		min = arr[i];
		pos = i;
		//Suche das Minimum im Restarray
		for(int y = i; y < size; y++){
			if(arr[y] < min){
				min = arr[y];
				pos = y;
			}
		}
		//tausche gefundenes Minimum an korrekte Stelle
		swap(arr, pos, i);
	}
}

void insertionsort(double* arr, int size){
	double tmp;
	for(int i = 1; i < size; i++){
		tmp = arr[i];
		//Durchlaufe sortiertes Array von hinten nach vorne
		//und schiebe alle zu grossen Elemente einen nach hinten
		for(int y = i-1; y >= 0 && arr[y] > tmp; y--){
			swap(arr, y, y+1);
		}
	}
}

void bubblesort(double* arr, int size){
	int hasSwapped = 1;
	//Falls Folge vor vollstaendigem Ablauf schon sortiert, brich ab
	for(int i = 0; hasSwapped == 1 && i < size; i++){
		hasSwapped = 0;
		//Durchlaufe das Restarray bis zu sortierter Stelle
		for(int y = 0; y < size-1-i; y++){
			//Falls Stellenwert groesser als Nachfolgewert, vertausche beide
			if(arr[y] > arr[y+1]){
				swap(arr, y, y+1);
				hasSwapped = 1;
			}
		}
	}
}

void quicksort(double* arr, int size){
	if(size == 0 || size == 1)
		return;
	if(size == 2){
		if(arr[0] > arr[1])
			swap(arr, 0, 1);
		return;	
	}
	double pivot = arr[size-1]; //pivot = letztes
	int lo, hi;
	/*suche in Array kleinste Stelle(hi), dessen Inhalt groesser/gleich ist als pivot
	/ und tausche es mit der groessten Stelle(lo), dessen Inhalt kleiner ist als pivot.
	*/
	//Initialisirung: lo = vorletztes, hi = erstes
	lo = size-2; 
	hi = 0;
	do{
		//i<size-1, damit pivot nicht mitgetauscht wird
		while(arr[hi] < pivot && hi < size-1)
			hi++;
		while(arr[lo] >= pivot && lo > 0)
			lo--;
		if(hi < lo)
			swap(arr, lo, hi);
		//Falls hi > lo, alles richtig aufgeteilt	
	}while(hi < lo);
	//tausche pivot an richtige Stelle; linker Rand des rechten Teilarrays
	swap(arr, size-1, hi);
	quicksort(arr, lo); 
	quicksort(&arr[hi+1], size-hi-1);
}

void mergesort(double* arr, int size){
	//((size-1)/2)+1) = size/2 aufgerundet
	if(size == 0 || size == 1)
		return;
	mergesort(arr, size/2);
	mergesort(&arr[size/2], ((size-1)/2)+1);
	merge(arr, size/2, &arr[size/2], ((size-1)/2)+1); 
}

void merge(double* arrA, int sizeA, double* arrB, int sizeB){
	double arrTmp[sizeA + sizeB];  
	int posA = 0, posB = 0, i = 0;
	//solange A oder B nicht geleert, fuege passendes Element zu Tmp hinzu
	while(posA < sizeA || posB < sizeB){
		//Falls A schon geleert, fuege den Rest von B zu Tmp hinzu
		if(posA >= sizeA)
			arrTmp[i] = arrB[posB++];
		//Falls B schon geleert, fuege den Rest von A zu Tmp hinzu
		else if(posB >= sizeB)
			arrTmp[i] = arrA[posA++];
		//Falls A und B nicht leer, fuege min(A,B) zu Tmp hinzu
		//min(A,B) ist immer erstes Element in A oder B
		else if(arrA[posA] < arrB[posB])
			arrTmp[i] = arrA[posA++];
		else
			arrTmp[i] = arrB[posB++];
		i++;
	}
	//schreibe Tmp in das urspruengliche Array
	for(i = 0; i < sizeA + sizeB; i++)
		arrA[i] = arrTmp[i];
}

void printArr(double* arr, int size){
	printf("[");
	for(int i = 0; i < size-1; i++)
		printf("%f, ",arr[i]);
	printf("%f]\n", arr[size-1]);	
}

double randBet(double min, double max){
	double range = max - min, res;
	res = (double)rand()/RAND_MAX; //Zufallszahl zwischen 0 und 1
	res = min + res * range;
	return res;
}

void CopyFirst(double* arrA, double* arrB, int size){
	for(int i = 0; i < size; i++)
		arrB[i] = arrA[i];
}

int main(){
	srand(time(NULL)); //Damit rand() nicht immer gleiche Folgen ausgibt
	clock_t begin, end;
	int size;
	
	//Aufgabe 3b)
	//Sortieralgorithmen bereits nach ihrer Laufzeit sortiert.
	printf("Welche Laenge(int) soll das Array haben?\n>");
	scanf("%d", &size);
	printf("Eingegebene Arraylaenge: %d\nAuflistung der Laufzeiten:\n", size);
	
	double* arr = malloc(size * sizeof(double));
	double* arrCopy = malloc(size * sizeof(double));
	for(int i = 0; i < size; i++){
		arr[i] = randBet(-1000, 1000);
		arrCopy[i] = arr[i];
	}
	begin = clock();
	quicksort(arrCopy, size);
	end = clock();
	printf("quicksort: %d\n",end-begin);
	
	CopyFirst(arr, arrCopy, size);
	begin = clock();
	mergesort(arrCopy, size);
	end = clock();
	printf("mergesort: %d\n",end-begin);
	
	CopyFirst(arr, arrCopy, size);
	begin = clock();
	selectionsort(arrCopy, size);
	end = clock();
	printf("Selektionsort: %d\n",end-begin);
	
	CopyFirst(arr, arrCopy, size);
	begin = clock();
	insertionsort(arrCopy, size);
	end = clock();
	printf("Insertionsort: %d\n",end-begin);
	
	CopyFirst(arr, arrCopy, size);
	begin = clock();
	bubblesort(arrCopy, size);
	end = clock();
	printf("Bubblesort: %d\n",end-begin);

	free(arr);
	free(arrCopy);
	
	return 0;
}