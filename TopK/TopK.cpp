/************************************************************************/
/* copyright@yansha &&July
/* July、updated，2011.05.08
/* 题目描述：
/* 搜索引擎会通过日志文件把用户每次检索使用的所有检索串都记录下来，每个查询串的
/* 长度为1-255 字节。假设目前有一千万个记录（这些查询串的重复度比较高，虽然总数是1 千万，但如果
/* 除去重复后，不超过3 百万个。一个查询串的重复度越高，说明查询它的用户越多，也就是越热门），
/* 请你统计最热门的10 个查询串，要求使用的内存不能超过1G。
/* 
/* 思路：通过hash函数来统计个数，然后建立k个元素的堆
/* 20140904
/************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace std;

#define HASHLEN 3000000
#define WORDLEN 30

//节点指针
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

//最简单的hash函数
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

//添加单词到hash表
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

	//新建一个节点
	ptrNoSpace q = new nodeNoSpace;
	q->count = 1;
	q->word = new char[strlen(str) + 1];
	strcpy(q->word, str);
	q->next = Hash[index];
	Hash[index] = q;
}

//将单词处理结果写入文件
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

//从上往下筛选，保持最小堆
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
		//交换节点元素
		 swap(Heap[minIndex].count, Heap[i].count);
		 char buffer[WORDLEN];
		 strcpy(buffer, Heap[i].word);
		 strcpy(Heap[i].word, Heap[minIndex].word);
		 strcpy(Heap[minIndex].word, buffer);

		 PerDown(Heap, minIndex, len);
	}

}

//建立最小堆
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

//去除字符串前后符号
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

	//将字符串用hash函数转换成一个整数，并统计出现的次数
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

	//将统计结构输入文件
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

	//建立最小堆
	BuildMinHeap(heap, n);

	//查找出现频率最大的10个单词；
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


	//输出最大的前10个单词；
	for (int i = 0; i < n; ++i)
	{
		cout << heap[i].count << "  " << heap[i].word << endl;
	}
	
	return 0;
}