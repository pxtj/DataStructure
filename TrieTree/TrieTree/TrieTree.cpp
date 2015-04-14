//TrieTree:字典树

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <memory>

using namespace std;

#define MAX 26	//英文字母的个数

typedef struct TrieTree
{
	bool isStr;	//标记该节点处是否有单词
	int strNum;	//标记该节点处单词出现的次数
	char cString[100]; //标记该节点出出现的单词
	struct TrieTree* next[MAX]; //子节点分支
}TrieTree;

typedef struct TrieTree* PtrTrieTree;

//Trie树插入：
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

//查找：
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

//查找：
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


//释放空间
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

//先序遍历
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

	//先序遍历打印
	PerOrderPrint(ptrTrieTree);
	cout << endl;

	//查找：
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

	//释放空间
	DelCache(ptrTrieTree);

	return;
}

int main()
{
	Test();
	return 0;
}