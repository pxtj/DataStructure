/***************************************************************************************************
* 16. 数组中数字都两两相同，只有一个不同，找出该数字：
* 17. 题目二：数组中数字两两相同，有两个不同，找出这两个：
* //先全部异或，得到两个不同值的异或结果；
* //然后判断这个异或结果的第几位为第一个1(从后往前),记为第n位
* //根据第n位是否为1将数组分成两组，在每一组中分别异或，分别得出一个不同值；
* 20140808
***************************************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//16.找出只有一个不同的数
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


//17.找出两个不相同的数：
//得到所有元素的异或值
int GetXorValue(int* arr, int len)
{
	return FindUniqueNumber(arr, len);
}

//得到异或值中第一个为1的位
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


//测试16
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

//测试17
void Test2()
{
	int arr[10];
	int first = 0;
	int second = 0;
	cout << "输入数组： " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	FindTwoUnique(arr, 10, &first, &second);

	cout << "输出两个不同值： ";
	cout << first << " " << second << endl;


}


int main()
{
	//找出一个不同值
	//Test1();

	//找出两个不同值
	Test2();
	return 0;

}