
#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"

using namespace std;


SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}


Position Find(SearchTree T, Element x)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (T->element > x)
	{
		Find(T->left, x);
	}
	else if (T->element < x)
	{
		Find(T->right, x);
	}
	else
		return T;

}

Position FindMin(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}

	if (T->left != NULL)
	{
		return FindMin(T->left);
	}

	return T;
}

Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}


	if (T->right != NULL)
	{
		return FindMax(T->right);
	}

	return T;
}

SearchTree Insert(SearchTree T, Element x)
{
	if (T == NULL)
	{
		Position T = (Position)malloc(sizeof(TreeNode));
		if (T == NULL)
		{
			return NULL;
		}
		
		T->element = x;
		T->left = NULL;
		T->right = NULL;

		return T;
	}
	else
	{
		if (x > T->element)
		{
			T->right = Insert(T->right, x);
		}
		else if (x < T->element)
		{
			T->left = Insert(T->left, x);
		}
	}

	return T;
}


SearchTree Delete(SearchTree T, Element x)
{
	Position TempPosition;

	if (T == NULL)
	{
		return NULL;
	}
	else if (x > T->element)
	{
		T->right = Delete(T->right, x);
	}
	else if(x < T->element)
	{
		T->left = Delete(T->left, x);
	}
	else if (T->left && T->right)
	{
		TempPosition = FindMin(T->right);
		T->element = TempPosition->element;
		T->right = Delete(T->right, x);
	}
	else
	{
		TempPosition = T;
		if (T->left == NULL)
		{
			T = T->right;
		}
		else if (T->right == NULL)
		{
			T = T->left;
		}
		free(TempPosition);
	}
	

	return T;

}


//Ç°Ðò±éÀú£º
void FrontPrintTree(SearchTree T)
{
	if (T == NULL)
	{
		return ;
	}

	cout << T->element << " ";
	FrontPrintTree(T->left);
	FrontPrintTree(T->right);
}


void Test()
{
	int i = 0;
	SearchTree T = NULL; 
	for (i = 0; i < 20; i++)
	{
		int x = 0;
		cin >> x;
		T = Insert(T, x);
	}

	FrontPrintTree(T);
	cout << endl;
}


int main()
{
	Test();
	return 0;
}