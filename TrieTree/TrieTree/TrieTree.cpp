//TrieTree:�ֵ���

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

using namespace std;

#define MAX 26	//Ӣ����ĸ�ĸ���

typedef struct TrieTree
{
	bool isStr;	//��Ǹýڵ㴦�Ƿ��е���
	int strNum;	//��Ǹýڵ㴦���ʳ��ֵĴ���
	char cString[100]; //��Ǹýڵ�����ֵĵ���
	struct TrieTree* next[MAX]; //�ӽڵ��֧
}TrieTree;

typedef struct TrieTree* PtrTrieTree;

//Trie�����룺
void TrieInsert(TrieTree* TreeRoot, char* str)
{
	if (TreeRoot == NULL || str == NULL || *str == '\0')
	{
		return ;
	}
	TrieTree* ptrTree = TreeRoot;
	int i = 0;

	char* ptrStr = str;

	while (*str != '\0') 
	{
		if(ptrTree->next[*str - 'a'] == NULL)
		{
			TrieTree* ptrNode = new TrieTree;
			for (int i = 0; i < MAX; i++)
			{
				ptrNode->next[i] = NULL;
			}
			ptrNode->isStr = false;
			ptrNode->strNum = 0;
			memset(ptrNode->cString, 0, 100*sizeof(char));

			ptrTree->next[*str - 'a'] = ptrNode;
		}

		ptrTree = ptrTree->next[*str - 'a'];
		str++;
	}

	ptrTree->isStr = true;
	strcpy(ptrTree->cString, ptrStr);
	ptrTree->strNum++;

	//return TreeRoot;
}

//���ң�
TrieTree* TrieSearch(TrieTree* ptrTree, const char* str)
{
	if (ptrTree == NULL || str == NULL || *str == '\0')
	{
		return NULL;
	}

	while (*str != '\0')
	{
		if (ptrTree->next[*str - 'a'] == NULL)
		{
			return NULL;
		}

		ptrTree = ptrTree->next[*str - 'a'];
		str++;
	}

	if (!ptrTree->isStr)
	{
		return NULL;
	}
	
	return ptrTree;
}

//���ң�
TrieTree* TrieSearch2(TrieTree* Tree, char* str)
{
	if (Tree == NULL || str == NULL || *str == '\0')
	{
		return NULL;
	}

	while (Tree != NULL && str != '\0')
	{
		Tree = Tree->next[*str - 'a'];
		str++;
	}
	if (Tree && Tree->isStr)
		return Tree;

	return NULL;
	

}


//�ͷſռ�
void DelCache(TrieTree* Tree)
{
	if (Tree == NULL)
	{
		return ;
	}
	for (int i = 0; i < MAX; i++)
	{
		if (Tree->next[i] != NULL)
		{
			DelCache(Tree->next[i]);
		}
	}

	free(Tree);
}

//�������
void PerOrderPrint(TrieTree* Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	if (Tree->isStr)
	{
		cout << Tree->cString << " " << Tree->strNum << " ";
	}
	for (int i = 0; i < MAX; i++)
	{
		PerOrderPrint(Tree->next[i]);
	}
}

void Test()
{
	char str[][10] = {"abc", "bcd", "abcd", "abce", "edf", "abc", "bcd", "abc"};
	TrieTree* ptrTrieTree = new TrieTree;
	ptrTrieTree->isStr = false;
	ptrTrieTree->strNum = 0;
	memset(ptrTrieTree->cString, 0, 100*sizeof(char));
	memset(ptrTrieTree->next, NULL, MAX*sizeof(TrieTree*));
	for (int i = 0; i < 8; i++)
	{
		TrieInsert(ptrTrieTree, str[i]);
	}

	//���������ӡ
	PerOrderPrint(ptrTrieTree);
	cout << endl;

	//���ң�
	TrieTree* doesExist = TrieSearch(ptrTrieTree, "abce");
	if (doesExist == NULL)
	{
		cout << "did not found!" << endl;
	}
	else
	{
		cout << "found!" << endl;
		cout << "times: " << doesExist->strNum << endl;
	}

	//�ͷſռ�
	DelCache(ptrTrieTree);

	return;
}

int main()
{
	Test();
	return 0;
}