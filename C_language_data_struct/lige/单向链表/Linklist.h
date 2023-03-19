#ifndef LINK_LIST_H
#define LINK_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE {
	void* data;
	struct LINKNODE* next;
} Linknode;

typedef struct LINKLIST {
	Linknode* head;
	int size;
} LinkList;

typedef void(*PRINTLINKLIST)(void*);

//��ʼ��
LinkList* Init_LinkList();
//����
void Insert_LinkList(LinkList* list, int pos, void* data);
//ɾ��
void RemoveByPos_LinkList(LinkList* list, int pos);
//����
int Size_LinkList(LinkList* list);
//���ص�һ����
void* Front_LinkList(LinkList* list);
//����
void Free_LinkList(LinkList* list);
//����
int Find_LinkList(LinkList* list, void* data);
//��ʾ
void Print_LinkList(LinkList* list, PRINTLINKLIST Print);


#endif 


