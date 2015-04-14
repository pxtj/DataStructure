/*********************************************************************
//Լɪ�����⣺
//��֪n����Χ��һ��Ȧ�����Ϊ1��2,3,4,5......n��
//�ӱ��Ϊk���˿�ʼ����������m���˳��У�
//������һ�����ִ�k��ʼ����������m���Ǹ��˳��У�
//�����ظ���ֱ�������˶�����
//���裺
//1. ����һ��ѭ������
//2. ȷ����һ�������˵�λ�ã�
//3. ���ϵĴ�������ɾ���ڵ㣬ֱ���ڵ�Ϊ�գ�
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

//����ѭ������
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

//ѭ����������ɾ���ڵ㣻
void yuesefuhuan(int n, int m, int k)
{
	assert(n > 0 && m > 0 && k > 0);
	k = k%n;
	m = m%n;

	ptrNode p1, p2, p3;
	ptrNode head = BuildCycleList(n);
	p1 = head;

	//��p1ָ���һ���������ˣ�
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

