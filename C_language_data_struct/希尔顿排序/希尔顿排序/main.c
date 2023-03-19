#define _CRT_SECURE_NO_WARNING

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

void ShellSort(int arr[], int length) {
	int i, j, k;
	int increase = length;

	do
	{
		increase = increase / 3 + 1;
		for (i = 0; i < increase; i++) {
			for (j = i + increase; j < length; j += increase) {
				if (arr[j]< arr[j-increase]) {
					int temp = arr[j];
					for (k = j - increase; k >= 0 && temp < arr[k]; k -= increase)
						arr[k + increase] = arr[k];
					arr[k + increase] = temp;
				}
			}
		}

	} while (increase>1);

}


int main() {
	printf("---------------------------\n");
	int arr[MAX];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < MAX; i++)
	{
		int val = rand() % MAX;
		arr[i] = val;
	}

	PrintArray(arr, MAX);

	ShellSort(arr, MAX);

	PrintArray(arr, MAX);


	return 0;
}