#include <iostream>
#include "AllSort.h"
using namespace std;

int main()
{
	//int arr[10] = {0};
	//for (int i = 0; i < 10; i++)
	//{
	//	cin>>arr[i];
	//}

	int arr[10] = {81, 94, 11, 96, 12, 35, 17, 95, 28, 58};

	for (int i = 0; i < 10; i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;

	//BubbleSort(arr, 10);
	//QuickSort(arr, 0, 9);
	//ShellSort(arr, 10);
	//InsertSort(arr, 10);
	HeapSort(arr, 10);
	//MergeSort(arr, 9);

	for (int i = 0; i < 10; i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;

	return 0;
}