#include"LinkStack.h"

Stack* Init_Stack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->size = 0;
	stack->node.next = NULL;
	return stack;
	}

void Push_Stack(Stack* stack, Node* node) {
	if (stack == NULL)
		return;
	if (node == NULL)
		return;

	node->next = stack->node.next;
	stack->node.next = node;
	stack->size++;
}

Node* Top_Stack(Stack* stack) {
	if (stack == NULL)
		return;
	return stack->node.next;
}

void Pop_Stack(Stack* stack) {
	if(stack == NULL)
		return;
	if (stack->size == 0)
		return;
	stack->node.next = stack->node.next->next;
	stack->size--;
}
 
void Clear_Stack(Stack* stack) {
	if (stack == NULL)
		return;
	stack->node.next = NULL;
	stack->size = 0;
}

void Free_Stack(Stack* stack) {
	if (stack == NULL)
		return;
	free(stack);
}