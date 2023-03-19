#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

void PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

//´Ó×óµ½ÓÒµÝÔö
void Fast_Sort(int arr[], int start, int end) 
{
	int i =  start;
	int j = end;
	int temp = arr[start];
	if (i < j) {

		while (i<j)
		{
			//´ÓÓÒÏò×óÕÒ
			while (i<j && temp <= arr[j])
			{
				j--;
			}
			//Ìæ»»
			if (i < j) {
				arr[i] = arr[j];
				i++;
			} 
			//´Ó×óÏòÓÒÕÒ
			while (i < j && temp >= arr[i])
			{
				i++;
			} 
			//Ìæ»»
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
	arr[i] = temp;
	Fast_Sort(arr, start, i - 1);
	Fast_Sort(arr, i + 1, end);
	}
	
}

int main() {
	cout << "---------------------" << endl;
	int myarr[] = { 4,2,8,0,5,7,1,3,9 };
	int len = sizeof(myarr) / sizeof(int);
	PrintArray(myarr, len);
	Fast_Sort(myarr, 0, len-1);
	PrintArray(myarr, len);

	return 0;
}