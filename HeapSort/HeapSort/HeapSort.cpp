#include <iostream>
using namespace std;

int getLeftChild(int parent)
{
	return 2*parent + 1;
}


void percDown(int arr[], int index, int N)
{
	int child;
	int temp;
	for (temp = arr[index]; getLeftChild(index) < N; index = child)
	{
		child = getLeftChild(index);
		if (child != N-1 && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (temp < arr[child])
		{
			arr[index] = arr[child];
		}
		else
			break;
	}

	arr[index] = temp;

}

void HeapSort(int arr[], int N)
{
	int i = 0;
	for (i = N/2; i>=0; i--)
	{
		percDown(arr, i, N);
	}
	int temp = 0;

	for (i = N-1; i > 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		percDown(arr, 0, i);
		
	}
}

int main(int argc, char *argv[])
{
	int arr[10] = {3, 4, 6, 2, 1, 7, 9, 8, 5, 0};
	HeapSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<endl;

	return 0;
}


