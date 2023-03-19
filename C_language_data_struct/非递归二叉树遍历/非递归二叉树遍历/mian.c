#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"LinkStack.h"

typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* left;
	struct BINARYNODE* right;
}BinaryNode;

typedef struct BirBinary {
	Node node;
	BinaryNode* root;
	int flag;
}BinaryStcak ;

#define my_true 1
#define my_false 0

BinaryStcak* CreatBitTreeNode(BinaryNode* node, int flag) {
	BinaryStcak* new_stack = (BinaryStcak*)malloc(sizeof(BinaryStcak));
	new_stack->root = node;
	new_stack->flag = my_false;
	return new_stack;
}

void NonRecrusion(BinaryNode* root) {
	Stack* stack = Init_Stack();
	Push_Stack(stack, (Node*)CreatBitTreeNode(root, my_false));

	while (stack->size > 0)
	{
		BinaryStcak* node = (BinaryStcak*)Top_Stack(stack);
		Pop_Stack(stack);

		if (node->root == NULL)
			continue;

		if (node->flag == 1)
			printf("%c", node->root->ch);
		else {
			Push_Stack(stack, (Node*)CreatBitTreeNode(node->root->right, my_false));
			Push_Stack(stack, (Node*)CreatBitTreeNode(node->root->left, my_false));
			node->flag = my_true;
			Push_Stack(stack, (Node*)node);
		}

	}

}

void Create_Binary() {
	BinaryNode node_A = { 'a',NULL,NULL };
	BinaryNode node_B = { 'b',NULL,NULL };
	BinaryNode node_C = { 'c',NULL,NULL };
	BinaryNode node_D = { 'd',NULL,NULL };
	BinaryNode node_E = { 'e',NULL,NULL };
	BinaryNode node_F = { 'f',NULL,NULL };
	BinaryNode node_H = { 'h',NULL,NULL };
	BinaryNode node_G = { 'g',NULL,NULL };
	node_A.left = &node_B;
	node_A.right = &node_F;
	node_B.right = &node_C;
	node_C.left = &node_D;
	node_C.right = &node_E;
	node_F.right = &node_G;
	node_G.left = &node_H;
	NonRecrusion(&node_A);

}

int main() {
	printf("-------------------------\n");

	Create_Binary();



}