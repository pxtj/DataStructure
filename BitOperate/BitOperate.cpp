/************************************************************************/
/* 位操作：编程金典8.5 p56
/* 包括：获取，置位，清零等
/* 
/* 20140909
/************************************************************************/

#include <iostream>
using namespace std;

//获取
bool GetBit(int num, int i)
{
	return (num & (1 << i));
}

//置位
int SetBit(int num, int i)
{
	return num | (1 << i);
}

//清零,其余位保持不变
int ClearBit(int num, int i)
{
	return num & (~(1 << i));
}

//将最高位到i位清零
int ClearBitMSBThroughI(int num, int i)
{
	return num & ((1 << i) - 1);
}

//将i位至0（包括0）位清零
int ClearBitIThrough0(int num, int i)
{
	return num & (~((i << (i+1)) - 1));
}

//更新：将某一位上的值更新，即将setBit与ClearBit合起来，先清零，在置位
int UpdateBit(int num, int i, int v)
{
	return (num & (~(1 << i))) | (v << i);
}

void Test()
{
	int num = 0;
	 cout << "please input num: ";
	while (cin >> num)
	{
		cout << GetBit(num, 3) << endl;
		cout << SetBit(num, 2) << endl;
		cout << ClearBit(num, 3) << endl;
		cout << ClearBitMSBThroughI(num, 3) << endl;
		cout << ClearBitIThrough0(num, 3) << endl;
		cout << UpdateBit(num, 3, 0) << endl;
		cout << "please input num: ";
	}
}

int main()
{
	Test();
	return 0;
}


