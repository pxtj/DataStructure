//bit map sort:
//20140819

#include <iostream>
#include <memory.h>
using namespace std;

const int endian = 1;
#define IsBigEndian() (*(char*)&endian == 0)
#define IsLittleEndian() (*(char*)&endian == 1)

#define BYTESIZE 8 //定义成多少都可以！！！


void SetBit(char* p, int posi)
{
	for (int i = 0; i < posi/BYTESIZE; i++)
	{
		++p;
	}

	*p = *p|((0x01)<<(posi%BYTESIZE));	//不区分大小端

	//此函数以上代码即为：
	//*(p + posi/BYTESIZE) = *(p + posi/BYTESIZE) | (0x01 << (posi%BYTESIZE));

}

int GetBufferLen(int* arr, int n)
{
	int maxNum = arr[0];
	for (int i = 0; i < n ; i++)
	{
		if(arr[i] > maxNum)
			maxNum = arr[i];
	}

	int bufferLen = 0;
	if (0 == maxNum%BYTESIZE)
	{
		bufferLen = maxNum/BYTESIZE;
	}
	else
	{
		bufferLen = maxNum/BYTESIZE + 1;
	}

	cout << "bufferLen : " << bufferLen << endl;

	return bufferLen;
}


void BitMapSort(int* arr, int n)
{
	int bufferLen = GetBufferLen(arr, n);
	char* pBuffer = new char[bufferLen];
	memset(pBuffer, 0, bufferLen*sizeof(char));

	for (int i = 0; i < n; i++)
	{
		SetBit(pBuffer, arr[i]);

		//或这个直接写成：
		//*(pBuffer + arr[i]/BYTESIZE) = *(pBuffer + arr[i]/BYTESIZE) | (0x01 << (arr[i]%BYTESIZE));
	}

	//输出排序结果：
	for (int i = 0; i < bufferLen; i++)
	{
		for (int j = 0; j < BYTESIZE; j++)
		{
			if ((pBuffer[i]&(0x01<<j)) == (0x01<<j))
			{
				cout << i*BYTESIZE + j << " ";
			}
		}
	}


	delete [] pBuffer;

}

void Test()
{
	int arr[10] = {5, 2, 1, 3, 9, 6, 0, 7, 4, 8};
	// 排序：
	BitMapSort(arr, 10);
	cout << endl;

	int arr2[20] = {15, 22,37, 41, 53, 69, 76, 80, 97, 104, 118, 22,37, 41, 53, 69, 76, 80, 97, 104 };
	//去重并排序：
	BitMapSort(arr2, 20);
	cout << endl;

	return ;
}


int main()
{
	if (IsBigEndian())
	{
		cout << "Is Big Endian!" << endl;
	}
	else
		cout << "Is little Endian!" << endl;

	Test();


	return 0;
}

