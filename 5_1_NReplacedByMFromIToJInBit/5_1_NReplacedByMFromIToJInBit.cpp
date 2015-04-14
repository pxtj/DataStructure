/************************************************************************/
/* 编程金典5.1：
/* 给定两个32位整数M和N，以及表示比特位置的i和j，用M代替N的第i到j位
/* 
/* 20140909
/************************************************************************/

#include <iostream>
#include <bitset>
using namespace std;

int GetBit(int num, int i)
{
	return num & (1 << i);
}
int GetBitNum(int num)
{
	int count = 0;
	while (num != 0)
	{
		++count;
		num = num/2;
	}
	return count;
}

void Swap(int& i, int& j)
{
	int temp = i;
	i = j;
	j = temp;
}

int UpdateBit(int num, int index, int value)
{
	return (num & (~(1<<index)))  | (value << index);
}

int NReplacedByMFromIToJInBit(int N, int M, int i, int j)
{
	if (i > j)
	{
		Swap(i, j);
	}
	int bitCountInM = GetBitNum(M);
	if (bitCountInM > (j - i + 1))
	{
		cout << "(bitCountInM > (j - i + 1))" << endl;
		return N;
	}

	int count = 0;
	for (int index = i; index <= j; ++index)
	{
		int bitInM = GetBit(M, index - i);
		if (bitInM != 0)
		{
			bitInM = 1;
		}
		count++;
		if (count > bitCountInM)
		{
			break;
		}
		N = UpdateBit(N, index, bitInM);
	}

	return N;

}

//书上给出的代码
//步骤：1.将N中从i到j之间的位清零
//	2.对M执行位移操作，与j和i之间的位对齐
//	3.合并M和N
int NUpdateWithM(int N, int M, int i, int j)
{
	int allOnes = ~0;
	int left = allOnes << (j + 1); //j前边均置1
	int right = ((1 << i) - 1); //i后边均置1
	int mask = left|right; //对i和j（包括i，j）中间的位均为0
	int n_cleared = N & mask;//对i和j（包括i，j）中间的位均置零
	int m_shifted = M << i;//M位对齐
	return n_cleared|m_shifted;
}

void Test()
{
	cout << GetBitNum(15) << endl;
	while(1)
	{
		int N = 0;
		int M = 0;
		cin >> N;
		cin >> M;
		cout << (bitset<32>)N <<endl;
		cout << (bitset<32>)M << endl;

		N = NReplacedByMFromIToJInBit(N, M, 0, 4);
		cout << (bitset<32>)N <<endl;

		N = NUpdateWithM(N, M, 6, 10);
		cout << (bitset<32>)N <<endl;

	}


}

int main()
{
	Test();

	return 0;
}