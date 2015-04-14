#include <stdio.h>
#include <stdlib.h>
#include <time.h>


////////////////////////////////////////////////////////////////
void BubbleSort(int a[], int length)
{
	int i, j;
	int temp;

	for(i = 0; i < length; i++)
	{
		for(j = 0; j < length - i; j++)
		{
			if(a[j + 1] < a[j])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}

	//	for(j = i + 1; j < length; j++)
	//	{

		//	if(a[j] < a[i])
		//	{
		//		temp = a[i];
		//		a[i] = a[j];
		//		a[j] = temp;
		//	}

	//	}

		
	}
}
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
//insert sort:O(n*n)
void InsertSort(int a[], int length)
{
	int i,j;
	int key;

	for (i = 1; i < length; ++i)
	{
		key = a[i];
		j = i - 1;
	
		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}

}
////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////
//combine sort: divide-conquer-combine:O(nlgn)
//conquer-combine:
void Merge(int a[], int p, int q, int r)
{
	int i, j, k;

	int n1 = q -p + 1; 
	int n2 = r - q;
	int *L = (int*)calloc((n1 + 1),  sizeof(int));
	int *R = (int*)calloc((n2 + 1),  sizeof(int));
//	int L[n1 + 1];
//	int R[n2 + 1];

	for (i = 0; i < n1; ++i)
	{
		L[i] = a[p + i];
	}

	for ( i = 0; i < n2; ++i)
	{
		R[i] = a[q + i + 1];
	}

	L[n1] = 10000;
	R[n2] = 10000;

	i = 0;
	j = 0;

	for(k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);

}	//end of Merge function

//divide;
void MergeSort(int a[], int left, int right)
{
	int p = left;
	int r = right;
	int q = 0;

	if(p < r)
	{
		int q = (p + r)/2;
		
		MergeSort(a, p, q);
		MergeSort(a, q + 1, r);

		Merge(a, p, q , r); 
	}
}	//end of MergeSort function
///////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////
//quick sort: O(n*n) O(nlgn)
void QuickSort(int a[], int left, int right)
{
	if(left < right)
	{
		int i = left;
		int j = right;

		int temp = a[i];

	//	while(i < j)
	//	{

			while(i < j && temp < a[j])
			{
				j--;
			}
			if(i < j)
			{
				a[i] = a[j];
				i++;
			}

			while(i < j && a[i] < temp)
			{
				i++;
			}
			if(i < j)
			{
				a[j] = a[i];
				j--;
			}
	//	}

		a[i] = temp;

		QuickSort(a, left, i);
		QuickSort(a, i + 1, right);

	}
}
///////////////////////////////////////////////////////////////

//QuickSort2:
int Partition(int a[], int l, int r);
//Random:get a random value from (l,r)
int Random(int l, int r)
{
	int value;
	if (l < r)
	{
		srand((unsigned)time(NULL));
		
		value = rand() % (r + 1 - l) + l;
	}

	return value;
	
}
//RandomizeRartition: randomize quick sort 
int RandomizeRartition(int a[], int l, int r)
{
	int i = Random(l, r);

	int temp = a[i];
	a[i] = a[r];
	a[r] = temp;

	return Partition(a, l, r);
}

//Partition:
int Partition(int a[], int l, int r)
{
    int i,j;
    int temp;
    i= l;

//	if (l < r)
	{
		for (j = l; j < r; j++)
		{
			if(a[j] < a[r])
			{
			//	i++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;

				i++;
			}
		}

		temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}

	return i;

    
}
void QuickSort2(int a[], int l, int r)
{
    int q;
 //   if(l < r)
    {
        q = Partition(a, l,r);

		//randomize quick sort: 
	//	q = RandomizeRartition(a, l, r);

         QuickSort2(a, l, q- 1);
         QuickSort2(a,  q, r);
         
    }
}



///////////////////////////////////////////////////////////////
/*******************************************************
//Max-Heap-Sort:
//step:
//	1. build max-heap:
//		for i <- down_upper(length[A]/2) to 0
//			do MaxHeapIFY(A, i)
//	2. sort:
//		for i <- length[A] to 1
//			do exchange A[i] <-> A[0]
//				MaxHeapIFY(A, 0)
// MaxHeapIFY(A, i): get a max heap structure for each node
***************************************************************/
//Max-HeapIFY:
int leftChild(int node)
{
	return 2*node + 1;
}
int rightChild(int node)
{
	return 2*node + 2;
}
int parentNode(int node)
{
	return (node - 1)/2;
}
void MaxHeapIFY(int a[], int node, int length)
{
	int largest;
	int temp;
	int l = leftChild(node);
	int r = rightChild(node); 

	if(l < length && a[l] > a[node])
	{
		largest = l;
	}
	else
	{
		largest = node;
	}

	if(r < length && a[r] > a[largest])
	{
		largest = r;
	}

	if( node != largest)
	{
		temp = a[node];
		a[node] = a[largest];
		a[largest] = temp;

		MaxHeapIFY(a, largest, length);

	}

}

//Build max-heap:
void BuildMaxHeap(int a[], int length)
{
	int i;
	for(i = (length - 1)/2; i >= 0; i--)
	{
		MaxHeapIFY(a, i, length);
	}
}

//Heap sort:
void HeapSort(int a[], int length)
{
	int i;
	int temp;

	BuildMaxHeap(a, length);

	for(i = length - 1; i > 0; i--)
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;

		MaxHeapIFY(a, 0, i);
	}
}

///////////////////////////////////////////////////////////////














int main(int argc, char const *argv[])
{
	int i;
	int n = 0;

	int a[16] = { 11,10,9,8,7,6,5,4,3,2,1,0, 13, 15, 12, 14};
	for (i = 0; i < 16; ++i)
	{
		printf("%d\t", a[i]);
		/* code */
	}
	printf("\n");

	//insert sort:
//	InsertSort(a, 11);

	//merge sort:
//	MergeSort(a, 0, 11);


	//bubble sort:
//	BubbleSort(a, 13);

	//quick sort:
//	QuickSort(a, 0, 15);

	//quick sort 2:
	QuickSort2(a, 0, 15);

	//heap sort:
//	HeapSort(a, 16);

	for (i = 0; i < 16; ++i)
	{
		printf("%d\t", a[i]);
		/* code */
	}
	printf("\n");

	printf("exchange times: %d\n", n);

	return 0;
}
