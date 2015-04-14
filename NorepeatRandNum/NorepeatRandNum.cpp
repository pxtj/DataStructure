//�����������������0~n-1�ڵ�m��������������ظ���

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void GetNoRepeatRandNum(int n , int m)
{
	srand(time(NULL));

	for (int i = 0; i < n; i ++)
	{
		if ((rand()%(n - i)) < m )
		{
			cout << n - i <<" " << m << " " << i << " " << endl;
			m--;
		}

	}

	cout << endl;
}


void GetNoRepeatRandNum2(int n, int m)
{
	int* arr = (int*)calloc(n, sizeof(n));
	if (arr == NULL)
		return ;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		int j = rand()%(n - i);
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}


	//��ǰm��������,�������
	//��������
	int j = 0;
	for (int i = 1; i < m; i++)
	{
		int temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}

	for (int i = 0; i < m; i++)
	{
		cout<< arr[i] << " ";
	}
	cout<<endl;

}

int main()
{
	int n, m;

	cout << "input n: ";
	cin >> n;

	cout << "input m:��";
	cin >> m;

	cout << "output rand num: " << endl;

	GetNoRepeatRandNum(n, m);
	GetNoRepeatRandNum2(n, m);

	

	return 0;


}