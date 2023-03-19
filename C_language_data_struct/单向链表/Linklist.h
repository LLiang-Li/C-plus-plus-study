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

//初始化
LinkList* Init_LinkList();
//插入
void Insert_LinkList(LinkList* list, int pos, void* data);
//删除
void RemoveByPos_LinkList(LinkList* list, int pos);
//长度
int Size_LinkList(LinkList* list);
//返回第一个点
void* Front_LinkList(LinkList* list);
//销毁
void Free_LinkList(LinkList* list);
//查找
int Find_LinkList(LinkList* list, void* data);
//显示
void Print_LinkList(LinkList* list, PRINTLINKLIST Print);


#endif 


