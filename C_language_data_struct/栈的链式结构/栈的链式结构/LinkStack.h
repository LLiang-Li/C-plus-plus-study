#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<stdio.h>
#include<stdlib.h>

typedef struct STACKNODE {
	struct STACKNODE* next;
}Node;

typedef struct LINKSTAK {
	Node node;
	int size;
}Stack;

Stack* Init_Stack();

void Push_Stack(Stack* stack, Node * node);

Node* Top_Stack(Stack* stack);

void Pop_Stack(Stack* stack);

void Clear_Stack(Stack* stack);

void Free_Stack(Stack* stack);

#endif // !LINKSTACK_H
