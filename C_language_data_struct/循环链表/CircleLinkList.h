#ifndef CIRCLELINKLIST
#define CIRCLELINKLIST

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE {
	struct NODE* next;
}Node;


typedef struct CIRCLELINKLIST {
	Node head;
	int size;
}CircleLinkList;

typedef int(*COMPARE)(Node* , Node* );

typedef void(*MYPRINT)(Node*);


//��ʼ��
CircleLinkList* Init_Circle_Link_List();

//����
void Insert_Circle_Link_List(CircleLinkList * list, int  pos, Node* val);

//ɾ��λ��
void Remove_bypos_Circle_Link_List(CircleLinkList* list, int pos);

//ɾ��ֵ
void Remove_value_Circle_Link_List(CircleLinkList* list, Node* val, COMPARE Compare);

//����size
int Size_Circle_Link_List(CircleLinkList* list);

//����ͷ�ڵ�
Node* Size_Head_Link_List(CircleLinkList* list);

//��ӡ
void Pirnt_Head_Link_List(CircleLinkList* list, MYPRINT Prin);

void free_Head_Link_List(list);

#endif // !CIRCLELINKLIST
