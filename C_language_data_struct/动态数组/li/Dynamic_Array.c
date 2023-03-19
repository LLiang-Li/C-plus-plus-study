#include "Dynamic_Array.h"	
	
//初始化
Dynamic_Array* Init_Dynamic_Array() {
	Dynamic_Array* my_array = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	my_array->size = 0;
	my_array->capacity = 20;
	my_array->Paddr = (int*)malloc(sizeof(int)*my_array->capacity);
	return my_array;
}

//插入
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

//删除
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

//删除
void RemoveByValue_Array(Dynamic_Array* arr, int value) {
	if (arr == NULL)
		return;
	int pos;
	pos = Find_Array(arr, value);
	RemoveByPos_Array(arr, pos);
}

//释放内存
void FreeSpace_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	if (arr->Paddr != NULL)
		free(arr->Paddr);
	free(arr);
}

//打印
void Print_Array(Dynamic_Array* arr) {
	printf("%d,%d\n",arr->capacity,arr->size);
	for (int i = 0; i < arr->size ; i++) {
		printf("%d\n", arr->Paddr[i]);
	}
		
}

//查找
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

//清除数组
void Clear_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return;
	arr->size = 0;
}

//获取容量
int Capacity_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -254;
	return arr->capacity ;
}

//当前个数
int Size_Array(Dynamic_Array* arr) {
	if (arr == NULL)
		return -254;
	return arr->size;
}

//获取位置元素
int At_Array(Dynamic_Array* arr, int pos) {
	if (arr == NULL)
		return -254;
	if (arr->size > pos)
		return arr->Paddr[pos];
	else
		return -254;
}