//permutation

#include <iostream>
using namespace std;


template<typename T>
void Swap(T* a, T* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
void Permutation(T* arr, int n, int left, int right)
{
	if (arr == NULL || n <= 0 || left < 0 || right > n)
	{
		return ;
	}
	if (left == right)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	for (int i = left; i < right; ++i)
	{
		Swap(&arr[i], &arr[left]);
		Permutation(arr, n, left+1, right);
		Swap(&arr[i], &arr[left]);
	}
}


int main()
{
	int arr[] = {1,2,3};
	Permutation(arr, 3, 0, 3);

	char arr2[] = {'a', 'b', 'c'};
	Permutation(arr2, 3, 0, 3);

	char arr3[] = "def";
	Permutation(arr3, 3, 0, 3);

	int* p = NULL;
	Permutation(p, 3, -1, 4);

	



}