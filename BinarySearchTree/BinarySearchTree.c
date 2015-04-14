//BinarySearchTree.c

#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

//make empty:
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->rigth);

		free(T);
	}

	return NULL;
	
}

//find
Position Find(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	
	if (T->element > X)
	{
		Find(ElementType X, T->left);
	}
	else if(T->element < X)
	{
		Find(ElementType X, T->rigth);
	}
	else
	{
		return T;
	}

}

//recursive method:
//find the position of min element;
Position FindMin(SearchTree T)
{
	if (T == NULL)
	{	
		return NULL;
	}

	if (T->left == NULL)
	{
		return T;
	}

	FindMin(T->left);
}


//not recursive method:
//find the position of max element:
Position FindMax(SearchTree T)
{
	if (T == NULL)
	{
		return NULL;
	}
	
	while(T->rigth != NULL)
	{
		T = T->rigth;
	}

	return T;

}


//insert:
SearchTree Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
		T = (SearchTree)calloc(1, sizeof(struct TreeNode));
		if (NULL == T)
		{
			printf("Create T failed.\n");
			return NULL;
		}
		T->element = X;
		T->left = NULL;
		T->rigth = NULL;

	}
	else if (T->element > X)
	{
		T->left = Insert(X, T->left);
	}
	else if (T->element < X)
	{
		T->rigth = Insert(X, T->rigth);
	}

	return T;

}


//delete:
SearchTree Delete(ElementType X, SearchTree T)
{
	Position Temp;

	if (NULL == T)
	{
		printf("T is Null.\n");
	}
	else if ((NULL == T->left)&&(NULL == T->rigth))
	{
		T = NULL;
	}
	else if (T->element > X)
	{
		T->left = Delete(X, T->left);
	}
	else if (T->element < X)
	{
		T->rigth = Delete(X, T->rigth);
	}
	else if (T->left && T->rigth)
	{
		Temp = FindMin(T->rigth);
		T->element = Temp->element;
		T->rigth = Delete(T->element, T->rigth);
	}
	else
	{
		Temp = T;
		if (T->left == NULL)
		{
			T = T->rigth;
		}
		else if (T->rigth == NULL)
		{
			T = T->left;
		}

		free(Temp);
	}


	return T;


}










































