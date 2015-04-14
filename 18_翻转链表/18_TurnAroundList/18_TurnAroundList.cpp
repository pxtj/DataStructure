/***************************************************************************************
* 18. 链表翻转。给出一个链表和一个数k，比如链表1→2→3→4→5→6，k=2，则翻转后2→1→4→3→6→5，
* 若k=3,翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→5→6，用程序实现
* 思想：采用遍历链表，分成length/k组，对每组进行逆转，逆转的同时要将逆转后的尾和头连接起来

*20140809
***************************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Node* PtrNode;
typedef struct Node* List;

void Insert(List Head, int val)
{
	if(Head == NULL)
		return ;
	PtrNode p = Head;
	PtrNode tempNode = (PtrNode)malloc(sizeof(Node));
	if(tempNode == NULL) return ;
	tempNode->data = val;
	tempNode->next = NULL;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = tempNode;
	
	return ;

}

List CreatList()
{
	PtrNode Head = (PtrNode)malloc(sizeof(Node));
	if (Head == NULL)
	{
		return NULL;
	}
	Head->next = NULL;

	for (int i = 0; i < 15; i++)
	{
		Insert(Head, i+1);
	}
	
	return Head;
}

int PrintList(List Head)
{
	if (Head == NULL || Head->next == NULL)
	{
		return 0;
	}

	int len = 0;
	PtrNode p1 = Head;
	p1 = p1->next;
	while (p1 != NULL)
	{
		len++;
		cout << p1->data << "   ";
		p1 = p1->next;
	}
	cout << endl;
	return len;
}


//链表中部分结点逆转
PtrNode ReverseListByNode(PtrNode pPer, PtrNode pCur)
{
	if (pPer == NULL)
	{
		return NULL;
	}
	if (pPer == pCur)
	{
		return pPer;
	}

	PtrNode tempCur;
	if(pCur != NULL && pCur->next != NULL)
	{
		tempCur = pCur->next;
	}

	PtrNode p1, p2, p3;
	p1 = pPer;
	p2 = p1->next;
	while(p2 != NULL && p1 != pCur)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	if (pCur == NULL)
	{
		pPer->next = NULL;
	}
	else if(pCur != NULL)
	{
		if(p2 == NULL)
		{
			pPer->next = NULL;
		}
		else if(p2 != NULL)
		{
			pPer->next = tempCur;
		}
	}
	pPer = p1;
	return pPer;
}


//链表以K为步长翻转：
void ReverseListByK(List Head, int k, int length)
{
	if (k <= 1)
	{
		return ;
	}
	PtrNode pPer = Head->next;
	PtrNode pCur = Head->next;
	PtrNode p1 = Head, p2;
	int r = k;
	for (int i = 0; i < length; i+=r)
	{
		if(length - i < k)
		{
			r = length - i; 
		}
		int m = r;
		while (--m)
		{
			pCur = pCur->next;
		}
		while(p1->next != pPer)
		{
			p1 = p1->next;
		}
		p2 = pCur->next;
		p1->next = ReverseListByNode(pPer, pCur);
		pPer = p2;
		pCur = pPer;

	}

	return ;

}


void Test()
{
	List Head = CreatList();
	int length = PrintList(Head);

	int k = 0;
	while(1)
	{

		cout << "input K: ";
		cin >> k;
		cout << "链表翻转： " << endl;
		//if k >= length时，翻转整个链表:
		for (int i = 0; i < 15; i++)
		{
			cout << i+1 << "   ";
		}
		cout << endl;
		ReverseListByK(Head, k, length);
		PrintList(Head);
		cout << endl;
	}

	//当pPer=Head->next, pCur=NULL时，整个链表翻转
	Head->next = ReverseListByNode(Head->next, NULL);
	PrintList(Head);
	return ;
}


int main()
{
	Test();

	return 0;
}