#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

int main() {
	printf("------------------------\n");

	typedef struct STUDENT {
		char name[64];
		int sorce;
	}Student;

	Student p1 = { "a",10 };
	Student p2 = { "b",20 };
	Student p3 = { "c",10 };

	SeqStack* list = Init_SeqStack();

	Push_SeqStack(list, &p1);

	Push_SeqStack(list, &p2);
	
	Push_SeqStack(list, &p3);

	while (list->size >0)
	{
		//Student* temp = (Student*)Top_seqstack(list);
		//printf("%s,%d\n", temp->name, temp->sorce);
		list->size--;
	}
	system("pause");

}