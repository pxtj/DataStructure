/*********************************************************************
//约瑟夫环问题：
//已知n个人围城一个圈，编号为1，2,3,4,5......n，
//从编号为k的人开始报数，数到m的人出列，
//他的下一个人又从k开始报数，数到m的那个人出列，
//依次重复，直到所有人都出列
//步骤：
//1. 建立一个循环链表
//2. 确定第一个报数人的位置；
//3. 不断的从链表中删除节点，直到节点为空；
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//node struct:
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

typedef struct Node* ptrNode;
typedef struct Node* List;

//建立循环链表
List BuildCycleList(int n)
{
	int inputData = 0;
	ptrNode p1, p2;

	List head;
	head = (ptrNode)malloc(sizeof(Node));
	p1 = head;

	for(int i = 1; i < n; i++)
	{
		p1->data = i;
		p2 = (ptrNode)malloc(sizeof(Node));
		p1->next = p2;
		p1 = p2;
	}
	p1->data = n;

//	while (n--)
//	{
//		scanf("%d", &inputData);
//		p1->data = inputData;
//		if (n > 0)
//		{
//			p2 = (ptrNode)malloc(sizeof(Node));
//			p1->next = p2;
//			p1 = p2;
//		}
//	}

	p1->next = head;
	return head;
}

//循环报数，并删除节点；
void yuesefuhuan(int n, int m, int k)
{
	assert(n > 0 && m > 0 && k > 0);
	k = k%n;
	m = m%n;

	ptrNode p1, p2, p3;
	ptrNode head = BuildCycleList(n);
	p1 = head;

	//将p1指向第一个报数的人；
	while (--k)
	{
		p1 = p1->next;
	}
	p2 = p1;

	while (n--)
	{
		for (int i = m - 1; i > 0; i--)
		{
			p2 = p1;
			p1 = p1->next;
		}
		printf("%d ", p1->data);
		p3 = p1;
		p2->next = p1->next;
		p2 = p1->next;
		p1 = p2;
		free(p3);
	}
	printf("\n");

	//printf("\n\n%d\n", p3->data);
}


int main()
{
	int n, m, k;
	printf("please input n: ");
	scanf("%d", &n);
	printf("please input m: ");
	scanf("%d", &m);
	printf("please input k: ");
	scanf("%d", &k);

	yuesefuhuan(n, m, k);

	return 0;
}

