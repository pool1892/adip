#include <stdio.h>

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
	tmp->next = head;
	return tmp;
}

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

	return 0;
}