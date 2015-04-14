//快速排序
//1.分解； 2.求解；3.组合（空操作）
#include "AllSort.h"

void QuickSort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pivot = QSPartition(arr, low, high);
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}

int QSPartition(int* arr, int low, int high)
{
	//取第一个值为基准
	int pivotKey = arr[low];

	int i = low;
	int j = high;

	while (i < j)
	{
		while (i < j && arr[j] >= pivotKey)
		{
			j--;
		}
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivotKey)
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = pivotKey;

	return i;
}


//GetPivot有问题
//int GetPivot(int* arr, int low, int high)
//{
//	int temp = 0;
//	int mid = (low + high) /2;
//	if (arr[low] > arr[mid])
//	{
//		temp = arr[low];
//		arr[low] = arr[mid];
//		arr[mid] = temp;
//	}
//	if (arr[low] > arr[high])
//	{
//		temp = arr[low];
//		arr[low] = arr[high];
//		arr[high] = temp;
//	}
//	if (arr[mid] > arr[high])
//	{
//		temp = arr[mid];
//		arr[mid] = arr[high];
//		arr[high] = temp;
//	}
//
//	temp = arr[low];
//	arr[low] = arr[mid];
//	arr[mid] = arr[low];
//
//	return arr[low];
//}


