#include <stdlib.h>
#include <stdio.h>

struct knoten{
	int Datenelement;
	struct knoten *links;
	struct knoten *rechts;
};
typedef struct knoten *Binbaum;

//Funktionendeklaration
Binbaum insertKnot(int, Binbaum);
void printTree(Binbaum);
void printTreeUnt(Binbaum);
Binbaum searchKnot(int, Binbaum);
Binbaum deleteKnot(int, Binbaum);
void deleteTree(Binbaum);

//Aufgabe 2a)
Binbaum insertKnot(int data, Binbaum tree){
	//Allokierung des neuen Elements
	Binbaum new = malloc(sizeof(Binbaum*));
	new->Datenelement = data;
	new->links = NULL;
	new->rechts = NULL;
	//Trivialfall: Baum leer
	if(tree == NULL){
		return new;
	}
	
	Binbaum tmp = tree;
	//Suche passende Stelle zum Einfuegen	
	while(tmp != NULL){
		if(data < tmp->Datenelement){
			if(tmp->links == NULL){
				tmp->links = new;
				return tree;
			}	
			tmp = tmp->links;
		}
		else if(data > tmp->Datenelement){
			if(tmp->rechts == NULL){
				tmp->rechts = new;
				return tree;
			}	
			tmp = tmp->rechts;
		}
		//Falls schon enthalten nicht hinzufuegen
		else{
			free(new);
			return tree;
		}
	}
}

//Unterteilt in zwei Funktionen, um die Ausgabe schoener zu gestalten
void printTree(Binbaum tree){
	if(tree == NULL){
		printf("Der Baum ist leer");
		return;
	}
	printf("Ausgabe in Inorder:\n");
	printTreeUnt(tree);
	printf("\n");
}
//Hier geschieht das Inorderzeugs
void printTreeUnt(Binbaum tree){
	if(NULL == tree)
		return;
	printTreeUnt(tree->links);
	printf("%d ", tree->Datenelement);
	printTreeUnt(tree->rechts);
}

Binbaum searchKnot(int data, Binbaum tree){
	if(tree == NULL){
		printf("%d ist nicht im Baum enthalten.\n", data);
		return NULL;
	}
	while(data != tree->Datenelement){
		if(data < tree->Datenelement)
			tree = tree->links;
		else
			tree = tree->rechts; 
		if(tree == NULL){
			printf("%d ist nicht im Baum enthalten.\n", data);
			return NULL;
		}
	}
	printf("%d ist im Baum enthalten.\n", data);
	return tree;
}

Binbaum deleteKnot(int data, Binbaum tree){
	//wie obiges searchKnot, aber speichert Vorgaenger
	if(tree == NULL)
		return NULL;
	Binbaum del = tree, prev = tree;
	int isroot = 0;
	while(data != del->Datenelement){
		isroot = 1;
		prev = del;
		if(data < del->Datenelement)
			del = del->links;
		else
			del = del->rechts;
		//Falls data nicht enthalten, verschwinde unbemerkt!
		if(del == NULL)
			return tree;
	}
	
	//Falls es rechten Teilbaum unter dem LoeschKnoten gibt
	if(del->rechts != NULL){
		//Suche Minimum im rechten Teilbaum vom LoeschKnoten
		//Ersetze LoeschKnoten durch gefundenen Knoten
		Binbaum rMin = del->rechts, rMinPrev = del;
		while(rMin->links != NULL){
			rMinPrev = rMin;
			rMin = rMin->links;
		}
		if(rMinPrev != del)
			rMinPrev->links = rMin->rechts;	
		rMin->rechts = del->rechts;	
		rMin->links = del->links;
		//Minimum auf die gleiche Seite vom LoeschVorgaenger haengen, wie Loeschknoten hing
		//Sonderfall: del = Wurzel, dann prev nicht initialisiert
		if(isroot){
			free(del);
			return rMin;
		}
		else{
			if(del->Datenelement > prev->Datenelement)
				prev->rechts = rMin;
			else
				prev->links = rMin;
		}
	}
		//Falls LoeschKnoten keinen rechten Teilbaum hat, haenge den linken an Vorgaenger an
	else{
		if(isroot){
			prev = del->links; //prev ist hier ein tmp ;)
			free(del);
			return prev;
		}
		else{
			if(del->Datenelement > prev->Datenelement)
				prev->rechts = del->links;
			else
				prev->links = del->links;
		}
	}
	free(del);
	return tree;
}
//Eine Art Destruktor
void deleteTree(Binbaum tree){
	if(tree == NULL)
		return;
	deleteTree(tree->links);
	deleteTree(tree->rechts);
	free(tree);
}

int main(){
	//Aufgabe 2b)
	int yes = 0, input = 0, size = 0;
	Binbaum test;
	
	printf("Lass uns einen lustigen Baum basteln!\n\n... Freude!\n\n");
	printf("Soll ein Knoten zum Baum hinzugefuegt werden?\n0 = Ja\t1 = Nein\n>");
	scanf("%d",&yes);
	while(yes == 0)
	{
		printf("Welche Zahl(int) soll hinzugefuegt werden?\n>");
		scanf("%d", &input);
		test = insertKnot(input, test);
		printf("\nDer Baum hat nun %d Knoten. Soll ein weiterer Knoten zum Baum hinzugefuegt werden?\n0 = Ja\t1 = Nein\n>", ++size);
		scanf("%d",&yes);
	}

	printf("\n\nNach welcher Zahl(int) soll im Baum gesucht werden?\n>");
	scanf("%d", &input);
	searchKnot(input, test);
	printTree(test);
	deleteTree(test);
	return 0;
}