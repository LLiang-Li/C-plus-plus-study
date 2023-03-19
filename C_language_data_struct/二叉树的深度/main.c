#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* left;
	struct BINARYNODE* right;
}BinaryNode;

int num = 0;

int Calculate_Binary_deep(BinaryNode* Binary) {
	if (Binary == NULL)
		return 0;
	int l_depth = Calculate_Binary_deep(Binary->left);
	int r_depth = Calculate_Binary_deep(Binary->right);
	return  l_depth > r_depth ? l_depth + 1 : r_depth + 1;
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
	int  de = Calculate_Binary_deep(&node_A);
	printf("%d", de);

}

int main() {
	printf("-------------------------\n");

	Create_Binary();



}