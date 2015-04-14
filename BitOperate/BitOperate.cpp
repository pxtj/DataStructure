/************************************************************************/
/* λ��������̽��8.5 p56
/* ��������ȡ����λ�������
/* 
/* 20140909
/************************************************************************/

#include <iostream>
using namespace std;

//��ȡ
bool GetBit(int num, int i)
{
	return (num & (1 << i));
}

//��λ
int SetBit(int num, int i)
{
	return num | (1 << i);
}

//����,����λ���ֲ���
int ClearBit(int num, int i)
{
	return num & (~(1 << i));
}

//�����λ��iλ����
int ClearBitMSBThroughI(int num, int i)
{
	return num & ((1 << i) - 1);
}

//��iλ��0������0��λ����
int ClearBitIThrough0(int num, int i)
{
	return num & (~((i << (i+1)) - 1));
}

//���£���ĳһλ�ϵ�ֵ���£�����setBit��ClearBit�������������㣬����λ
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


