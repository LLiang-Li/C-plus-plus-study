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


//初始化
CircleLinkList* Init_Circle_Link_List();

//插入
void Insert_Circle_Link_List(CircleLinkList * list, int  pos, Node* val);

//删除位置
void Remove_bypos_Circle_Link_List(CircleLinkList* list, int pos);

//删除值
void Remove_value_Circle_Link_List(CircleLinkList* list, Node* val, COMPARE Compare);

//返回size
int Size_Circle_Link_List(CircleLinkList* list);

//返回头节点
Node* Size_Head_Link_List(CircleLinkList* list);

//打印
void Pirnt_Head_Link_List(CircleLinkList* list, MYPRINT Prin);

void free_Head_Link_List(list);

#endif // !CIRCLELINKLIST
