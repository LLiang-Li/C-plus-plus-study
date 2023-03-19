#ifndef Dynamic_Array_H
#define Dynamic_Array_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��̬�����ڴ�
//��̬���飬�����ڴ桢�������ݣ��ͷ��ڴ�
//����
typedef struct DYNAMICARRAY {
	int* Paddr; //��ַ
	int size;	//��ǰԪ��
	int capacity;// ����
} Dynamic_Array;

//��ʼ��
Dynamic_Array* Init_Dynamic_Array();

//����
void PushBack_Array(Dynamic_Array* arr, int value);

//ɾ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos);

//ɾ��
void RemoveByValue_Array(Dynamic_Array* arr, int value);

//�ͷ��ڴ�
void FreeSpace_Array(Dynamic_Array*);

//��ӡ
void Print_Array(Dynamic_Array*);

//����
int Find_Array(Dynamic_Array* arr, int value);

//�������
void Clear_Array(Dynamic_Array* arr);

//��ȡ����
int Capacity_Array(Dynamic_Array* arr);

//��ǰ����
int Size_Array(Dynamic_Array* arr);

//��ȡλ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos);

#endif // Dynamic_Array

