#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BINARYNODE {
	char ch;
	struct BINARYNODE* left;
	struct BINARYNODE* right;
}BinaryNode;

void Recursion_fornt(BinaryNode* root) {
	if (root == NULL)
		return;
	printf("%c", root->ch);
	Recursion_fornt(root->left);
	Recursion_fornt(root->right);

}

BinaryNode* Copy_Binary(BinaryNode* Binary) {
	if (Binary == NULL)
		return NULL;
	BinaryNode* new_Binary = (BinaryNode*)malloc(sizeof(BinaryNode));
	new_Binary->left = NULL;
	new_Binary->right = NULL;
	new_Binary->ch = Binary->ch;
	BinaryNode* l_new_Binary = Copy_Binary(Binary->left);
	BinaryNode* r_new_Binary = Copy_Binary(Binary->right);
	new_Binary->left = l_new_Binary;
	new_Binary->right = r_new_Binary;
	return new_Binary;
}

void Free_Binary(BinaryNode* Binary) {
	if (Binary == NULL)
		return;
	Free_Binary(Binary->left);
	Free_Binary(Binary->right);
	free(Binary);
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
	BinaryNode* new_b = Copy_Binary(&node_A);
	Recursion_fornt(&node_A);
	printf("\n");
	Recursion_fornt(new_b);
	printf("\n");
	Free_Binary(new_b);
}

int main() {
	printf("-------------------------\n");

	Create_Binary();



}