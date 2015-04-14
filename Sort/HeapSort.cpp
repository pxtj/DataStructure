//������
//1.���ѣ�2.��������

#include "AllSort.h"

#define LeftChild(i) (2*(i) + 1)

void HeapSort(int* arr, int n)
{
	int i = 0;
	//����
	for (i = n/2; i >= 0; i--)
	{
		PerDown(arr, i, n);
	}

	printf("Heap:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");


	//��������
	for (i = n-1; i > 0; i--)
	{
		Swap(&arr[i], &arr[0]);
		PerDown(arr, 0, i);
	}

}

void PerDown(int* arr, int index, int n)
{
	int i = index;
	int child = LeftChild(i);
	int temp = arr[i];

	for (temp = arr[i]; LeftChild(i) < n; i = child)
	{
		child = LeftChild(i);
		if (child + 1 < n && arr[child] < arr[child + 1])
		{
			child++;
		}

		if (temp < arr[child])
		{
			arr[i] = arr[child];
		}
		else
			break;
	}

	arr[i] = temp;
}

void Swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

