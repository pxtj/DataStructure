#include <stdio.h>
#include <stdlib.h>
#include "PriorityHeap.h"

struct HeapStruct{
	int Capacity;
	int Size;
	ElementType *Element;
};


PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue PH ;
	if (MaxElements < 0)
	{
		printf("MaxElement < 0");
	}
	PH = (PriorityQueue)calloc(1, sizeof(struct HeapStruct));
	if (NULL == PH)
	{
		printf("PH == NULL");
		return NULL;
	}

	PH->Element = (ElementType*)calloc(MaxElements + 1, sizeof(ElementType));
	if(NULL == PH->Element)
	{
		printf("NULL = P->Element");
		return NULL;
	}
	PH->Capacity = MaxElements;
	PH->Size = 0;
	//PH->Element[0] = MinData;
	PH->Element[0] = -9999;

	return PH;
}



void Destory(PriorityQueue H)
{

}


void Insert(ElementType X, PriorityQueue H)
{
	int isFull = IsFull(H);
	if(isFull)
	{
		printf("H is Full. X can not be insert.\n");
		return ;
	}

// 	H->Size += 1;
// 	H->Element[H->Size] = X;
// 	int childNode = H->Size;
// 	int parentNode = H->Size/2;
// 	ElementType childNum = H->Element[childNode];
// 	ElementType parentNum = H->Element[parentNode];
// 	while((parentNode > 0) &&(childNum > parentNum))
// 	{
// 		ElementType temp = H->Element[parentNode];
// 		H->Element[parentNode] = H->Element[childNode];
// 		H->Element[childNode] = temp;
// 		childNode =parentNode;
// 		parentNode /= 2;
// 	}
	
	int i = 0;
	for(i = ++H->Size; H->Element[i/2]>X; i/=2)
	{
		H->Element[i] = H->Element[i/2];
	}
	H->Element[i] = X;

}


ElementType DeleteMin(PriorityQueue H)
{
	int i = 0;
	int child = 0;

	ElementType minElement, lastElement;

	if(IsEmp(H))
	{
		printf("H is empty\n");
		return 0;
	}

	minElement = H->Element[1];
	lastElement = H->Element[H->Size--];

	for (i = 1; i*2 <= H->Size; i = child)
	{
		child = i*2;
		if (child != H->Size && H->Element[child + 1] < H->Element[child])
		{
			child++;
		}

		if (lastElement > H->Element[child])
		{
			H->Element[i] = H->Element[child];
		} 
		else
		{
			break;
		}
	}

	H->Element[i] = lastElement;

	return minElement;

}


int IsEmp(PriorityQueue H)
{
	if (H->Size = 0)
	{
		return 1;
	}
	else
		return 0;
}






int IsFull(PriorityQueue H)
{
	if (H->Size < H->Capacity)
	{
		return 0;
	}
	else
		return 1;
}


void InsertTest(PriorityQueue Hd, int X)
{
	if(Hd == NULL)
	{
		printfU("Hd is NULL");
		return;
	}
	if (IsFull(Hd))
	{
		printf("Hd is full!\n");
		return ;
	}

	int i = 0;
	for (i = ++Hd->Size; Hd->Element[i/2] < X; i = i/2)
	{
		Hd->Element[i] = Hd->Element[i/2];
	}
	Hd->Element[i] = X;


}













