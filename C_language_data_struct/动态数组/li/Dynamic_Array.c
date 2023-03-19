#include "Dynamic_Array.h"	
	
//��ʼ��
Dynamic_Array* Init_Dynamic_Array() {
	Dynamic_Array* my_array = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	my_array->size = 0;
	my_array->capacity = 20;
	my_array->Paddr = (int*)malloc(sizeof(int)*my_array->capacity);
	return my_array;
}

//����
void PushBack_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return;
	if (arr->size < arr->capacity) {
		arr->Paddr[arr->size] = value;
		arr->size++;
	}
	else
	{
		int* new_addr = (int*)malloc(sizeof(int) * arr->capacity * 2);
		memcpy(new_addr, arr->Paddr, arr->capacity * sizeof(int));
		free(arr->Paddr);
		arr->Paddr = new_addr;
		arr->capacity = arr->capacity * 2;
		arr->Paddr[arr->size] = value;
		arr->size++;
	}
 }

//ɾ��
void RemoveByPos_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return;
	if (pos < 0 || pos >= arr->size)
		return;

	for (int i = pos; i < arr->size - 1; i++ ) {
		arr->Paddr[i] = arr->Paddr[i + 1];
	}
	arr->size--;
}

//ɾ��
void RemoveByValue_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return;
	int pos;
	pos = Find_Array(arr, value);
	RemoveByPos_Array(arr, pos);
}

//�ͷ��ڴ�
void FreeSpace_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	if (arr->Paddr != NULL)
		free(arr->Paddr);
	free(arr);
}

//��ӡ
void Print_Array(Dynamic_Array* arr) {
	printf("%d,%d\n",arr->capacity,arr->size);
	for (int i = 0; i < arr->size ; i++) {
		printf("%d\n", arr->Paddr[i]);
	}
		
}

//����
int Find_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return -254;
		for (int i = 0; i < arr->size; i++) {
		if (arr->Paddr[i] == value) {
			return i;
		}
	}
	return -1;
}

//�������
void Clear_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	arr->size = 0;
}

//��ȡ����
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -254;
	return arr->capacity ;
}

//��ǰ����
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -254;
	return arr->size;
}

//��ȡλ��Ԫ��
int At_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return -254;
	if (arr->size > pos)
		return arr->Paddr[pos];
	else
		return -254;
}