#include"SeqStack.h"
SeqStack* Init_SeqStack() {
	SeqStack* list = (SeqStack*)malloc(sizeof(SeqStack*));
	
	/*for (int i = 1; i < MAX_Stack; i++) {
		list->data[i] = NULL;
	}*/
	list->size = 0;
	return list;
}

void Push_SeqStack(SeqStack* list, void* val) {
	if (list == NULL)
		return;
	if (list == NULL)
		return;
	list->data[list->size] = val;
	list->size++;
}

void* Top_SeqStack(SeqStack* list) {
	if (list == NULL)
		return;

	return list->data[list->size-1];
}

void Pop_SeqStack(SeqStack* list) {
	if (list == NULL)
		return;
	if (list->size == 0)
		return;
	list->size--;
}

int Size_SeqStack(SeqStack* list) {
	return list->size;
}