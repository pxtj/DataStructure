//≤Â»Î≈≈–Ú£∫
//

#include "AllSort.h"

void InsertSort(int* arr, int n)
{
	int i = 0, j = 0;
	int temp = 0;

	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i; j > 0; j--)
		{
			if (arr[j - 1] > temp)
			{
				arr[j] = arr[j - 1];
			}
			else
				break;
		}
		arr[j] = temp;
	}




}