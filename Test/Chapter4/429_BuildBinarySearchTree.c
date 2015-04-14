/* ************************************************************
 * 题目来源：数据结构及算法分析——C语言描述 第四章习题：4.29
 * 题目：写出生成一棵N节点随机二叉查找树的函数，该树具有从1到N的不同的关键字
 * 时间：2014年06月14日
 * Author：pxtj
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









































