#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

typedef struct St {
	Node node;
	char name[64];
	int score;
}stu;



int main() {
	printf("------------------------------\n");

	Stack* stack = Init_Stack();

	stu p1, p2, p3;

	strcpy(p1.name, "a");
	strcpy(p2.name, "b");
	strcpy(p3.name, "c");

	p1.score = 20;
	p2.score = 30;
	p3.score = 40;

	Push_Stack(stack, &p1);
	Push_Stack(stack, &p2);
	Push_Stack(stack, &p3);

	while (stack->size>0) {
		stu* s = (stu*)Top_Stack(stack);
		printf("name = %s,score = %d\n",s->name,s->score);
		Pop_Stack(stack);
	}
	Free_Stack(stack);

	return 0;
}