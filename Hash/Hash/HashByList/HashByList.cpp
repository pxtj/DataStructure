//hash表的实现：
//链地址法实现：

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct Node
{
	char* name;
	char* desc;
	struct Node* next;
}Node;

#define HASHSIZE 101
static Node* hashTable[HASHSIZE];

void InitHashTable()
{
	for (int i = 0; i < HASHSIZE; ++i)
	{
		hashTable[i] = NULL;
	}
}

unsigned int Hash(char* s)
{
	unsigned int h = 0;
	while (*s !='\0')
	{
		h = h * 31 + *s;
		s++;
	}
	return h % HASHSIZE;
}

Node* Find(char* s)
{
	unsigned int h = Hash(s);
	Node* pNode = hashTable[h]; 
	while (pNode != NULL)
	{
		if (strcmp(pNode->name, s) == 0)
		{
			return pNode;
		}
		pNode = pNode->next;
	}

	return NULL;
}

char* 