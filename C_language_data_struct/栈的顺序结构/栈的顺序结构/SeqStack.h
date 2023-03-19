#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<stdio.h>
#include<stdlib.h>

#define MAX_Stack 1024

typedef struct SEQSTACK {
	void* data[2014];
	int size;
}SeqStack;

SeqStack* Init_SeqStack();

void Push_SeqStack(SeqStack* list,void * data);

void* Top_SeqStack(SeqStack* list);

void Pop_SeqStack(SeqStack* list);

int Size_SeqStack(SeqStack* list);


#endif // !SEQSTACK_H

