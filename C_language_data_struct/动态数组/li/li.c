#define _CRT_SECURE_NO_WARNINGD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Dynamic_Array.h"	

void test() {
	Dynamic_Array* new_arr = Init_Dynamic_Array();;
	for (int i = 0; i < 22; i++) {
		PushBack_Array(new_arr, i);
	}
	Print_Array(new_arr);
	RemoveByPos_Array(new_arr, 0);

	RemoveByValue_Array(new_arr, 15);
	Print_Array(new_arr);
	FreeSpace_Array(new_arr);

	//RemoveByPos_Array(new_arr, 0);

	//RemoveByValue_Array(new_arr, 15);

}

int main()
{
	test();

	system("pause");
}