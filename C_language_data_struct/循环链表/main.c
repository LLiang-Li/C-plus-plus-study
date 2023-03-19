#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"CircleLinkList.h"

typedef struct STUDENT {
	Node node;
	int age;
	char name[65];
}student;

int comp(Node* val1, Node* val2) {
	student* s1 = (student*)val1;
	student* s2 = (student*)val2;
	if (strcmp(s1->name, s2->name)==0 && s1->age == s2->age)
		return 1;
	return 0;
}

void print(Node* val) {
	student* s = (student*)val;
	printf("name = %s, age = %d\n",s->name, s->age);
}





int main() 
{
	printf("------------------------\n");

	student p1,p2,p3,p4;
	strcpy(p1.name, "a");
	strcpy(p2.name, "b");
	strcpy(p3.name, "c");
	strcpy(p4.name, "d");
	p1.age = 20;
	p2.age = 30;
	p3.age = 40;
	p4.age = 50;

	CircleLinkList* list = Init_Circle_Link_List();

	Insert_Circle_Link_List(list, 0, (Node*)&(p1));
	Pirnt_Head_Link_List(list, print);
	printf("------------------------\n");
	Insert_Circle_Link_List(list, 0, (Node*)&(p2));
	Pirnt_Head_Link_List(list, print);
	printf("------------------------\n");
	Insert_Circle_Link_List(list, 0, (Node*)&(p3));
	Insert_Circle_Link_List(list, 0, (Node*)&(p4));

	Pirnt_Head_Link_List(list, print);
	printf("------------------------\n");
	Remove_bypos_Circle_Link_List(list, 2);
	Pirnt_Head_Link_List(list, print);


	Remove_value_Circle_Link_List(list, (Node*)&(p4), comp);
	printf("------------------------\n");
	Pirnt_Head_Link_List(list, print);
	free_Head_Link_List(list);

	printf("%d", strcmp("a","a"));



	return 0;
}
