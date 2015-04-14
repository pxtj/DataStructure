//MergeSort;

#include "AllSort.h"

void MSort(int* arr, int* tempArr, int left, int right)
{
	int center;
	if (left < right)
	{
		center = (left + right)/2;
		MSort(arr, tempArr, left, center);
		MSort(arr, tempArr, center+1, right);
		Merge(arr, tempArr, left, center + 1, right); 
	}
}


void MergeSort(int* arr, int N)
{
	int* tempArr;
	tempArr = (int*)malloc(N*sizeof(int));

	if (tempArr != NULL)
	{
		MSort(arr, tempArr, 0, N - 1);
		free(tempArr);
	}
	else
		printf("tempArr malloc failed!\n");
}

void Merge(int* arr, int* tempArr, int lPos, int rPos, int rightEnd)
{
	int i, leftEnd, numElements, tempPos;
	leftEnd = rPos - 1;
	tempPos = lPos;
	numElements = rightEnd - lPos + 1;

	//copy arr to tempArr:
	while(lPos <= leftEnd && rPos <= rightEnd)
	{
		if (arr[lPos] <= arr[rPos])
			tempArr[tempPos++] = arr[lPos++];
		else
			tempArr[tempPos++] = arr[rPos++];
	}

	while (lPos <= leftEnd)
	{
		tempArr[tempPos++] = arr[lPos++];
	}
	while (rPos <= rightEnd)
	{
		tempArr[tempPos++] = arr[rPos++];
	}

	//copy tempArr back to arr
	for (i = 0; i < numElements; i++, rightEnd--)
	{
		arr[rightEnd] = tempArr[rightEnd];
	}
}



