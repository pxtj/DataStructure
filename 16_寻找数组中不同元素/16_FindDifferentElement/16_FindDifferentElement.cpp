/***************************************************************************************************
* 16. ���������ֶ�������ͬ��ֻ��һ����ͬ���ҳ������֣�
* 17. ��Ŀ��������������������ͬ����������ͬ���ҳ���������
* //��ȫ����򣬵õ�������ֵͬ���������
* //Ȼ���ж����������ĵڼ�λΪ��һ��1(�Ӻ���ǰ),��Ϊ��nλ
* //���ݵ�nλ�Ƿ�Ϊ1������ֳ����飬��ÿһ���зֱ���򣬷ֱ�ó�һ����ֵͬ��
* 20140808
***************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//16.�ҳ�ֻ��һ����ͬ����
int FindUniqueNumber(int* arr, int len)
{
	int i = 0;
	int temp = arr[0];
	for (i = 1; i < len; i++)
	{
		temp = temp ^ arr[i];
	}

	return temp;
}


//17.�ҳ���������ͬ������
//�õ�����Ԫ�ص����ֵ
int GetXorValue(int* arr, int len)
{
	return FindUniqueNumber(arr, len);
}

//�õ����ֵ�е�һ��Ϊ1��λ
int FindFirstBitIs1(int xorVal)
{
	int count = 1;
	while ((xorVal ^ 1) == 0 && count < 8 * sizeof(int) )
	{
		xorVal = xorVal >> 1;
		count++;
	}

	return count;
}

int BitIs1(int a, int count)
{
	a = a >> (count - 1);
	return a&1;
}

void FindTwoUnique(int* arr, int len, int* first, int* second)
{
	if (len <= 0)
	{
		return ;
	}

	*first  = 0;
	*second = 0;
	int xorVal = GetXorValue(arr, len);
	int count = FindFirstBitIs1(xorVal);
	for (int i = 0; i < len; i++)
	{
		if (BitIs1(arr[i], count))
		{
			*first ^= arr[i];
		}
		else
		{
			*second ^= arr[i];
		}
	}

	return ;

}


//����16
void Test1()
{
	int arr[9] = {0};
	cout << "please input arr: " << endl;
	for(int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	int uniqueNum = FindUniqueNumber(arr, 9);
	if (uniqueNum == 0)
	{
		cout << "no unique numble!" << endl;
	}
	else
		cout << "output unique number: " << uniqueNum << endl;

}

//����17
void Test2()
{
	int arr[10];
	int first = 0;
	int second = 0;
	cout << "�������飺 " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	FindTwoUnique(arr, 10, &first, &second);

	cout << "���������ֵͬ�� ";
	cout << first << " " << second << endl;


}


int main()
{
	//�ҳ�һ����ֵͬ
	//Test1();

	//�ҳ�������ֵͬ
	Test2();
	return 0;

}