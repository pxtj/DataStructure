/* ************************************************************
 * ��Ŀ��Դ�����ݽṹ���㷨��������C�������� ������ϰ�⣺4.29
 * ��Ŀ��д������һ��N�ڵ��������������ĺ������������д�1��N�Ĳ�ͬ�Ĺؼ���
 * ʱ�䣺2014��06��14��
 * Author��pxtj
 * ***********************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct TreeNode{
	ElementType element;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

int RandomInt(int Lower, int Upper)
{
	if(Upper <= Lower)
		return Lower;
	return (rand()%(Upper - Lower)) + Lower;
}

SearchTree MakeRandomTree1(int Lower, int Upper)
{
	SearchTree T;
	int randomValue;
	T = NULL;

	if(Lower <= Upper)
	{
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if(T != NULL)
		{
			randomValue = RandomInt(Lower, Upper);
			T->element = randomValue;
			T->left = MakeRandomTree1(Lower, randomValue - 1);
			T->right = MakeRandomTree1(randomValue + 1, Upper);
		}
		else
			printf("T malloc failed\n");
	}

	return T;

}


SearchTree MakeRandomTree(int N)
{
	return MakeRandomTree1(1, N);
}


int main(int argc, char* argv[])
{

	int a = 0;

	SearchTree T = MakeRandomTree(10);		

	printf("finished\n");

	return 0;
}









































