#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	struct NODE* next;
}Node;

typedef struct LINKLIST {
	Node head;
	int size;
}LinkList;

typedef void(*PRINTNODE)(Node* node);

LinkList* Init_LinkList();

void Insert_LinkList(LinkList* list, int pos, Node * node);

void Free_LinkList(LinkList* list);

void Remove_LinkList(LinkList* list, int pos);

void Print_LinkList(LinkList* list, PRINTNODE prin);



#endif // !LINKLIST_H

