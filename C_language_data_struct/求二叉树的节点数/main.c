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

void CalculateleafNum(BinaryNode* Binary) {
	if (Binary == NULL)
		return;
	if (Binary->left == NULL && Binary->right == NULL)
		num++;
	CalculateleafNum(Binary->left);
	CalculateleafNum(Binary->right);
}

/*void Recursion_fornt(BinaryNode* root) {
	if (root == NULL)
		return;
	printf("%c", root->ch);
	Recursion_fornt(root->left);
	Recursion_fornt(root->right);

}
void Recursion_zhong(BinaryNode* root) {
	if (root == NULL)
		return;
	Recursion_zhong(root->left);
	printf("%c", root->ch);

	Recursion_zhong(root->right);

}

void Recursion_hou(BinaryNode* root) {
	if (root == NULL)
		return;
	Recursion_hou(root->left);

	Recursion_hou(root->right);

	printf("%c", root->ch);
}
*/

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

	CalculateleafNum(&node_A);
	printf("叶子节点的数量：%d", num);
	/*Recursion_fornt(&node_A);
	printf("\n");

	Recursion_zhong(&node_A);
	printf("\n");

	Recursion_hou(&node_A);
	printf("\n");*/
}

int main() {
	printf("-------------------------\n");

	Create_Binary();



}