/************************************************************************/
/* copyright@yansha &&July
/* July��updated��2011.05.08
/* ��Ŀ������
/* ���������ͨ����־�ļ����û�ÿ�μ���ʹ�õ����м���������¼������ÿ����ѯ����
/* ����Ϊ1-255 �ֽڡ�����Ŀǰ��һǧ�����¼����Щ��ѯ�����ظ��ȱȽϸߣ���Ȼ������1 ǧ�򣬵����
/* ��ȥ�ظ��󣬲�����3 �������һ����ѯ�����ظ���Խ�ߣ�˵����ѯ�����û�Խ�࣬Ҳ����Խ���ţ���
/* ����ͳ�������ŵ�10 ����ѯ����Ҫ��ʹ�õ��ڴ治�ܳ���1G��
/* 
/* ˼·��ͨ��hash������ͳ�Ƹ�����Ȼ����k��Ԫ�صĶ�
/* 20140904
/************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

#define HASHLEN 3000000
#define WORDLEN 30

//�ڵ�ָ��
typedef struct nodeNoSpace* ptrNoSpace;
typedef struct nodeHasSpace* ptrHasSpace;
ptrNoSpace Hash[HASHLEN];

struct nodeNoSpace
{
	char* word;
	int count;
	ptrNoSpace next;
};
struct nodeHasSpace
{
	char word[WORDLEN];
	int count;
	ptrHasSpace next;
};

//��򵥵�hash����
int HashFunction(char const* p)
{
	int value  = 0;
	while(*p != '\0')
	{
		value = value * 31 + *p;
		if (value > HASHLEN)
		{
			value = value%HASHLEN;
		}
	}
	return value;
}

//��ӵ��ʵ�hash��
void AppendWordToHash(char const* str)
{
	if (str == NULL)
	{
		return ;
	}
	int index = HashFunction(str);
	ptrNoSpace p = Hash[index];
	while (p != NULL)
	{
		if (strcmp(str, p->word) == 0)
		{
			p->count++;
			return ;
		}
		p = p->next;
	}

	//�½�һ���ڵ�
	ptrNoSpace q = new nodeNoSpace;
	q->count = 1;
	q->word = new char[strlen(str) + 1];
	strcpy(q->word, str);
	q->next = Hash[index];
	Hash[index] = q;
}

//�����ʴ�����д���ļ�
void WriteToFile()
{
	FILE *fp = fopen("./result.txt", "w");
	assert(fp);

	int i = 0;
	while (i < HASHLEN)
	{
		for (ptrNoSpace p = Hash[i]; p != NULL; p = p->next)
		{
			fprintf(fp, "%s	%d\n", p->word, p->count);
		}
		++i;
	}
	fclose(fp);
}

//��������ɸѡ��������С��
void PerDown(nodeHasSpace Heap[], int i, int len)
{
	int minIndex = -1;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < len && Heap[leftChild].count < Heap[i].count)
	{
		minIndex = leftChild;
	}
	else
		minIndex = i;

	if (rightChild < len && Heap[rightChild].count < Heap[minIndex].count)
	{
		minIndex = rightChild;
	}

	if (minIndex != i)
	{
		//�����ڵ�Ԫ��
		 swap(Heap[minIndex].count, Heap[i].count);
		 char buffer[WORDLEN];
		 strcpy(buffer, Heap[i].word);
		 strcpy(Heap[i].word, Heap[minIndex].word);
		 strcpy(Heap[minIndex].word, buffer);

		 PerDown(Heap, minIndex, len);
	}

}

//������С��
void BuildMinHeap(nodeHasSpace Heap[], int len)
{
	if (Heap == NULL)
	{
		return ;
	}

	int index = len/2;
	for (int i = index; i >= 1; i--)
	{
		PerDown(Heap, i, len);
	}
}

//ȥ���ַ���ǰ�����
void HandleSymbol(char* str, int n)
{
	while (str[n] < '0' || (str[n] < '9' && str[n] < 'A') 
		 ||(str[n] > 'Z' && str[n] < 'a') || str[n] > 'z')
	{
		str[n] = '\0';
		n--;
	}
	while (str[0] < '0' || (str[0] < '9' && str[0] < 'A') 
		|| (str[0] > 'Z' && str[0] < 'a') || str[0] > 'z')
	{
		int i = 0;
		while (i < n)
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = '\0';
		n--;
	}
}

int main()
{
	char str[WORDLEN];
	for (int i = 0; i < HASHLEN; ++i)
	{
		Hash[i] = NULL;
	}

	//���ַ�����hash����ת����һ����������ͳ�Ƴ��ֵĴ���
	FILE* fp_passage = fopen("./string.txt", "r");
	assert(fp_passage);
	while (fscanf(fp_passage, "%s", str) != EOF)
	{
		int n = strlen(str) - 1;
		if (n > 0)
		{
			HandleSymbol(str, n);
		}
		AppendWordToHash(str);
	}
	fclose(fp_passage);

	//��ͳ�ƽṹ�����ļ�
	WriteToFile();

	int n = 10;
	ptrHasSpace heap = new nodeHasSpace[n+1];

	int c;

	FILE* fp_word = fopen("result.txt", "r");
	assert(fp_word);

	for (int i = 0; i < n; ++i)
	{
		fscanf(fp_word, "%s %d", &str, &c);
		heap[i].count = c;
		strcpy(heap[i].word, str);
	}

	//������С��
	BuildMinHeap(heap, n);

	//���ҳ���Ƶ������10�����ʣ�
	while (fscanf(fp_word, "%s %c", &str, &c) != EOF)
	{
		if (c > heap[1].count)
		{
			heap[1].count = c;
			strcpy(heap[1].word, str);
			PerDown(heap, 1, n);
		}
	}
	fclose(fp_word);


	//�������ǰ10�����ʣ�
	for (int i = 0; i < n; ++i)
	{
		cout << heap[i].count << "  " << heap[i].word << endl;
	}
	
	return 0;
}