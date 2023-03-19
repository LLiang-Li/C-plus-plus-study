#ifndef Dynamic_Array_H
#define Dynamic_Array_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//动态增长内存
//动态数组，申请内存、拷贝数据，释放内存
//定义
typedef struct DYNAMICARRAY {
	int* Paddr; //地址
	int size;	//当前元素
	int capacity;// 容量
} Dynamic_Array;

//初始化
Dynamic_Array* Init_Dynamic_Array();

//插入
void PushBack_Array(Dynamic_Array* arr, int value);

//删除
void RemoveByPos_Array(Dynamic_Array* arr, int pos);

//删除
void RemoveByValue_Array(Dynamic_Array* arr, int value);

//释放内存
void FreeSpace_Array(Dynamic_Array*);

//打印
void Print_Array(Dynamic_Array*);

//查找
int Find_Array(Dynamic_Array* arr, int value);

//清除数组
void Clear_Array(Dynamic_Array* arr);

//获取容量
int Capacity_Array(Dynamic_Array* arr);

//当前个数
int Size_Array(Dynamic_Array* arr);

//获取位置元素
int At_Array(Dynamic_Array* arr, int pos);

#endif // Dynamic_Array

