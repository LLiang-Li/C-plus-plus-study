#define _CRT_SECURE_NOWARNING

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/timeb.h>
#include<time.h>

#define MAX 10

long getSystemTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

void Swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d,", arr[i]);
	}
	printf("\n");
}

void InsertSort(int arr[], int length) {
	int j ;
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i-1]) {
			int now_value = arr[i];
			for ( j = i - 1; j >= 0 && now_value < arr[j]; j--)
				arr[j + 1] = arr[j];

				arr[j + 1] = now_value;
		}
		
	}
}

int main() {
	printf("-------------------------\n");

	int arr[MAX];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX; i++)
	{
		int val = rand()%MAX;
		arr[i] = val;
	}

	PrintArray(arr, MAX);

	InsertSort(arr, MAX);

	PrintArray(arr, MAX);
}