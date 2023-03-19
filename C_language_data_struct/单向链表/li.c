#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Linklist.h"

typedef struct PERSON {
	char name[64];
	int age;
	int score;
}Person;

void prin(void* data) {
	Person* da = (Person*)data;
	printf("name=%s,age = %d, score = %d\n", da->name, da->age, da->score);
}


int main()
{
	LinkList* List = Init_LinkList();

	Person p1 = { "a", 18, 98 };
	printf("%s\n", p1.name);
	Person p2 = { "b", 19, 97 };
	Person p3 = { "c", 20, 96 };
	Person p4 = { "d", 21, 95 };
	Person p5 = { "e", 22, 94 };
	Insert_LinkList(List, 0, &p1);
	Insert_LinkList(List, 0, &p2);
	Insert_LinkList(List, 0, &p3);
	Insert_LinkList(List, 0, &p4);
	Insert_LinkList(List, 0, &p5);
	printf("%d\n", List->size);
	Print_LinkList(List, prin);

	RemoveByPos_LinkList(List, 3);
	printf("\n");
	Print_LinkList(List, prin);

	printf("---------\n");
	Person* da = (Person*)Front_LinkList(List);
	printf("name=%s,age = %d, score = %d\n", da->name, da->age, da->score);

	Free_LinkList(List);





	return 0;
}