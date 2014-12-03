#include <stdio.h>

<<<<<<< Updated upstream
typedef struct DoubleNode DoubleNode;

DoubleNode *insertFirst(DoubleNode *head, double d);
void printList(DoubleNode *head);
DoubleNode *insertLast(DoubleNode *head, double d);
DoubleNode *reverseDoubleListCon(DoubleNode *head);
DoubleNode *reverseDoubleList(DoubleNode *head);

//Aufgabe 1b)a)
DoubleNode{
	DoubleNode *next;
	double value;
};

//Aufgabe 1b)b)
DoubleNode *insertFirst(DoubleNode *head, double d){
	struct DoubleNode *tmp;
	tmp	= malloc(sizeof(DoubleNode));
	tmp->value = d;
=======

///fuer Aufgabenteil (a):
///dort steht hinterher als Output: 
/// (11 7 3)
/// (14 5 11 7 3)

typedef struct DoubleNode { struct DoubleNode *next; double data;
} DoubleNode;


DoubleNode * insertFirst( DoubleNode *head, double d){ 
	DoubleNode *tmp;
	tmp= malloc(sizeof(DoubleNode));
	tmp->data = d;
>>>>>>> Stashed changes
	tmp->next = head;
	return tmp;
}

<<<<<<< Updated upstream
//Aufgabe 1b)c)
void printList(DoubleNode *head){
	DoubleNode *cursor;
	cursor = head;
	printf("(");
	while(cursor != NULL){
		printf("%d ",cursor->value);
		cursor = cursor->next;
	}
	printf(")");
}

//Aufgabe 1b)d)
DoubleNode *insertLast(DoubleNode *head, double d){
	DoubleNode *cursor, *tmp;
	cursor = head;
	if(cursor == NULL) 
		return insertFirst(head, d); 
	else{
		while(cursor->next != NULL)
			cursor = cursor->next;
		tmp = malloc(sizeof(DoubleNode));
		tmp->value = d;
		tmp->next = NULL;
		cursor->next = tmp;
		return head;
	}
}

//Aufgabe 1b)e)
DoubleNode *reverseDoubleListCon(DoubleNode *head){
	DoubleNode *cursor, *tmpnew, *headnew;
	cursor = head; 
	headnew = NULL;
	while(cursor != NULL){
		tmpnew = malloc(sizeof(DoubleNode));
		tmpnew->value = cursor->value;
		tmpnew->next = headnew;
		headnew = tmpnew;
		cursor = cursor->next;
	}
	return headnew;
}

//Aufgabe 1b)f)
DoubleNode *reverseDoubleList(DoubleNode *head){
	DoubleNode *cursor, *tmpnext, *tmpprev;
	cursor = head; 
	tmpprev = NULL;
	while(cursor != NULL){
		tmpnext = cursor->next;
		cursor->next = tmpprev;
		tmpprev = cursor;
		cursor = tmpnext;
	}
	return tmpprev;
}

int main(){

=======
void printList(DoubleNode *head){ 
	DoubleNode *cursor;
	printf ("(");
	cursor=head;
	while (cursor != NULL) {
	printf("%d",cursor->data); printf(" "); cursor=cursor->next;
} 
printf(")"); 
}

DoubleNode * insertLast(DoubleNode *head, double d) {
	DoubleNode *tmp, *cursor;	
	if (head==NULL) {
		return insertFirst(head,d);} 
	else{
		cursor=head;
		while (cursor->next != NULL){
			cursor =cursor->next;} 
		tmp= malloc(sizeof(DoubleNode));
		tmp->data = d;
		tmp->next = NULL;
		cursor->next=tmp;
		return head;
	} 
}

DoubleNode *reverseListCon(DoubleNode *head){ 
	DoubleNode *res, *tmp, *cell;
	cell=head; 
	res=NULL; 
	while (cell != NULL) {
		tmp= malloc(sizeof(DoubleNode)); 
		tmp->data=cell->data; 
		tmp->next=res;
		res=tmp;
		cell=cell->next; 
	}
	return res; 
}

void reverseList(DoubleNode * head){ 
	DoubleNode *revChain, *chain, *cell; 
	cell=head;
	revChain=NULL; 
	while (cell != NULL) {
		chain=cell->next;
//reverse next pointer in cell
		cell->next=revChain;
//add cell to revChain
		revChain=cell;
//set cell to next cell in chain
		cell=chain; 
	}
//finalize
	head=revChain; 
}








int main(){


node *head;






>>>>>>> Stashed changes
	return 0;
}