#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkList.h"

typedef struct STU {
	Node* node;
	char name[64];
	int  socre;
} Student;

void prin(Node* node) {
	Student* data = (Student*)node;
	printf("name = %s, score = %d\n", data->name, data->socre);
}

int main() {



	Student p1, p2, p3, p4, p5;
	strcpy(p1.name, "a");
	strcpy(p2.name, "b");
	strcpy(p3.name, "c");
	strcpy(p4.name, "d");
	strcpy(p5.name, "e");

	p1.socre = 90;
	p2.socre = 80;
	p3.socre = 70;
	p4.socre = 60;
	p5.socre = 50;

	printf("-----------------\n");
	LinkList* list = Init_LinkList();
	Insert_LinkList(list, 0, (Node*)&p1);
	Insert_LinkList(list, 0, (Node*)&p2);
	Insert_LinkList(list, 0, (Node*)&p3);
	Insert_LinkList(list, 0, (Node*)&p4);
	Insert_LinkList(list, 0, (Node*)&p5);
	Print_LinkList(list, prin);
	Remove_LinkList(list, 2);
	printf("-----------------\n");
	Print_LinkList(list, prin);
	Free_LinkList(list);


}