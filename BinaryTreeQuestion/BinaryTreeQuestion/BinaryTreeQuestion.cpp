//���������⼯��
//20140822

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
using namespace std;


typedef int ElementType;
typedef struct TreeNode
{
	ElementType data;
	struct TreeNode* pLeft;
	struct TreeNode* pRight;
}TreeNode;

typedef struct TreeNode* PtrNode;
typedef struct TreeNode* BinaryTree;


//������������
PtrNode CreateBinaryTreeNode(ElementType val)
{
	PtrNode ptrNode = new TreeNode;
	ptrNode->data = val;
	ptrNode->pLeft = NULL;
	ptrNode->pRight = NULL;
	return ptrNode;
}

void ConnectTreeNodes(PtrNode pNode1, PtrNode pNode2, PtrNode pNode3)
{
	if (pNode1 == NULL)
	{
		return ;
	}
	pNode1->pLeft = pNode2;
	pNode1->pRight = pNode3;
}

BinaryTree CreateBinaryTree()
{
	PtrNode pNode1 = CreateBinaryTreeNode(1);
	PtrNode pNode2 = CreateBinaryTreeNode(2);
	PtrNode pNode3 = CreateBinaryTreeNode(3);
	PtrNode pNode4 = CreateBinaryTreeNode(4);
	PtrNode pNode5 = CreateBinaryTreeNode(5);
	PtrNode pNode6 = CreateBinaryTreeNode(6);
	PtrNode pNode7 = CreateBinaryTreeNode(7);
	PtrNode pNode8 = CreateBinaryTreeNode(8);
	PtrNode pNode9 = CreateBinaryTreeNode(9);
	PtrNode pNode10 = CreateBinaryTreeNode(10);
	PtrNode pNode11 = CreateBinaryTreeNode(11);
	PtrNode pNode12 = CreateBinaryTreeNode(12);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	ConnectTreeNodes(pNode4, pNode8, pNode9);
	ConnectTreeNodes(pNode8, pNode10, pNode11);

	return pNode1;
}
BinaryTree CreateBinaryTree2()
{
	PtrNode pNode1 = CreateBinaryTreeNode(1);
	PtrNode pNode2 = CreateBinaryTreeNode(2);
	PtrNode pNode3 = CreateBinaryTreeNode(3);
	PtrNode pNode4 = CreateBinaryTreeNode(4);
	PtrNode pNode5 = CreateBinaryTreeNode(5);
	PtrNode pNode6 = CreateBinaryTreeNode(6);
	PtrNode pNode7 = CreateBinaryTreeNode(7);
	PtrNode pNode8 = CreateBinaryTreeNode(8);
	PtrNode pNode9 = CreateBinaryTreeNode(9);
	PtrNode pNode10 = CreateBinaryTreeNode(10);
	PtrNode pNode11 = CreateBinaryTreeNode(11);
	PtrNode pNode12 = CreateBinaryTreeNode(12);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	ConnectTreeNodes(pNode4, pNode8, pNode9);
	ConnectTreeNodes(pNode8, pNode10, NULL);

	return pNode1;
}

BinaryTree CreateBinaryTree3()
{
	PtrNode pNode1 = CreateBinaryTreeNode(10);
	PtrNode pNode2 = CreateBinaryTreeNode(5);
	PtrNode pNode3 = CreateBinaryTreeNode(12);
	PtrNode pNode4 = CreateBinaryTreeNode(4);
	PtrNode pNode5 = CreateBinaryTreeNode(7);
	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);

	return pNode1;
}

BinaryTree CreateBinaryTree4()
{
	PtrNode pNode1 = CreateBinaryTreeNode(1);
	PtrNode pNode2 = CreateBinaryTreeNode(2);
	PtrNode pNode3 = CreateBinaryTreeNode(3);
	PtrNode pNode4 = CreateBinaryTreeNode(4);
	PtrNode pNode5 = CreateBinaryTreeNode(5);
	PtrNode pNode6 = CreateBinaryTreeNode(6);
	PtrNode pNode7 = CreateBinaryTreeNode(7);
	PtrNode pNode8 = CreateBinaryTreeNode(8);
	PtrNode pNode9 = CreateBinaryTreeNode(9);
	PtrNode pNode10 = CreateBinaryTreeNode(10);
	PtrNode pNode11 = CreateBinaryTreeNode(11);
	PtrNode pNode12 = CreateBinaryTreeNode(12);

	//ConnectTreeNodes(pNode1, pNode2, pNode3);
	//ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	ConnectTreeNodes(pNode4, pNode8, pNode9);
	//ConnectTreeNodes(pNode8, pNode10, pNode11);

	return pNode1;
}

//����������ݹ�
void PerOrderPrint(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return ;
	}

	cout << Tree->data << " ";
	PerOrderPrint(Tree->pLeft);
	PerOrderPrint(Tree->pRight);

}

//����������ݹ�
void InOrderPrint(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	InOrderPrint(Tree->pLeft);
	cout << Tree->data << " ";
	InOrderPrint(Tree->pRight);
}

//����������ݹ�
void PostOrderPrint(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	PostOrderPrint(Tree->pLeft);
	PostOrderPrint(Tree->pRight);
	cout << Tree->data << " ";
}

/************************************************************************/
/* �������ķǵݹ����:�������򡢺��򡢼��������
/************************************************************************/
/************************************************************************
* �ǵݹ����������
* ��������ջ�ṹ��
*	1.�����������ڵ��ջ�������������ڵ��ջ
*	2.���ջ�ǿգ�����г�ջ����
*	�����ڲ������
************************************************************************/
void PerOrderPrintNoRecursive(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	PtrNode ptrNode = Tree;
	stack<PtrNode> s;
	s.push(ptrNode);
	while (!s.empty())
	{
		ptrNode = s.top();
		cout << ptrNode->data << " ";
		s.pop();
		if (ptrNode->pRight != NULL) //ע�⣺������������������ڵ���ջ
		{
			s.push(ptrNode->pRight);
		}
		if (ptrNode->pLeft != NULL)
		{
			s.push(ptrNode->pLeft);
		}
	}
}


/************************************************************************
* �ǵݹ����������
* ��������ջ�ṹ��
*	1.
*	2.
************************************************************************/
void InOrderPrintNoRecursive(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	PtrNode ptrCurrent = Tree; //ָ����ǰҪ��������,��ʱ���ڵ㲻Ҫ����ջ
	stack<PtrNode> s;
	while (ptrCurrent != NULL || !s.empty())
	{
		while (ptrCurrent != NULL)
		{
			s.push(ptrCurrent);
			ptrCurrent = ptrCurrent->pLeft;
		}
		if (!s.empty())
		{
			ptrCurrent = s.top();
			cout << ptrCurrent->data << " ";
			s.pop();
			ptrCurrent = ptrCurrent->pRight;
		}
	}
}


/************************************************************************
* �ǵݹ���������
* ��������ջ�ṹ��
************************************************************************/
//void PostOrderNoRecursive(BinaryTree Tree)
//{
//	if (Tree == NULL)
//	{
//		return ;
//	}

//	PtrNode ptrCurr = Tree;
//	stack<PtrNode> s;
//	s.push(ptrCurr);
//	while (ptrCurr != NULL || !s.empty())
//	{
//		while (ptrCurr != NULL)
//		{
//			ptrCurr = s.top();
//			if (ptrCurr->pLeft != NULL)
//			{
//				s.push(ptrCurr->pLeft);
//			}
//			if (ptrCurr->pRight != NULL)
//			{
//				s.push(ptrCurr->pRight);
//			}
//		}

//	}

//}



//�������������
void LayerOrderPrint(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return ;
	}

	int nodeNumInTree = 0; //  ��¼�ڵ�ĸ���
	queue<PtrNode> Queue;
	PtrNode ptrNode = Tree;
	Queue.push(ptrNode);
	while (!Queue.empty())
	{
		ptrNode = Queue.front();
		cout << ptrNode->data << " " ;
		nodeNumInTree++;
		Queue.pop();
		if (ptrNode->pLeft != NULL)
		{
			Queue.push(ptrNode->pLeft);
		}
		if (ptrNode->pRight != NULL)
		{
			Queue.push(ptrNode->pRight);
		}
	}

	//cout << endl;
	//cout << "�ڵ�ĸ����� " << nodeNumInTree;

	return ;
}


//�����н��ĸ���
int GetNodeNumber(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return 0;
	}
	return GetNodeNumber(Tree->pLeft) + GetNodeNumber(Tree->pRight) + 1;
}

//��Ҷ�ӽڵ�ĸ�����
int GetLeavesNumber(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return 0;
	}
	static int leavesNum = 0;

	if (Tree->pLeft == NULL && Tree->pRight == NULL)
	{
		leavesNum++;
	}
	GetLeavesNumber(Tree->pLeft);
	GetLeavesNumber(Tree->pRight);

	return leavesNum;
}

//����������
int GetTreeDepth(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return 0;
	}
	int leftDepth = GetTreeDepth(Tree->pLeft);
	int rightDepth = GetTreeDepth(Tree->pRight);

	return leftDepth >= rightDepth?leftDepth+1:rightDepth+1;
}

//����������Ϊ�����˫������ ��ָoffer27��
void ConvertToDoubleList(BinaryTree Tree, PtrNode* listNode);
BinaryTree ConvertToList(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return NULL;
	}

	PtrNode listNode = NULL;
	ConvertToDoubleList(Tree, &listNode);

	//����ͷ��㣺
	PtrNode lastNode = listNode;
	while (lastNode != NULL && lastNode->pLeft != NULL)
	{
		lastNode = lastNode->pLeft;
	}



	return lastNode;
}
void ConvertToDoubleList(BinaryTree Tree, PtrNode* listNode)
{
	if (Tree == NULL)
	{
		return ;
	}

	PtrNode pCurrent = Tree;
	if (pCurrent->pLeft != NULL)
	{
		ConvertToDoubleList(pCurrent->pLeft, listNode);
	}

	pCurrent->pLeft = *listNode;
	if (*listNode != NULL)
	{
		(*listNode)->pRight = pCurrent;
	}
	*listNode = pCurrent;

	if (pCurrent->pRight != NULL)
	{
		ConvertToDoubleList(pCurrent->pRight, listNode);
	}
}

void PrintList(BinaryTree ListTree)
{
	if (ListTree == NULL)
	{
		return;
	}
	PtrNode p = ListTree;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pRight;
	}
	cout << endl;
}
//ת����˫��������


/*********************************************************
* ���������K��Ľڵ���
* 1.�����Ϊ�ջ���K<1������0
* 2.���K == 1�� ����1
* 3.���K>1, �ڵ���������������K-1��ڵ�����������K-1��֮��
**********************************************************/
//�ݹ�
int GetNodeNumInLayerK(BinaryTree Tree, int k)
{
	if (Tree == NULL || k < 1)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return GetNodeNumInLayerK(Tree->pLeft, k - 1) + GetNodeNumInLayerK(Tree->pRight, k - 1);
}
//�ǵݹ飬���ݲ�������������K��ڵ���
int GetNodeNumInLayerKByLayerPrint(BinaryTree Tree, int k)
{
	if (Tree == NULL || k < 1)
	{
		return 0;
	}
//	if (k == 1)
//	{
//		return 1;
//	}

	PtrNode ptrNode = Tree;
	queue<PtrNode> q;
	q.push(ptrNode);
	while (q.size())
	{
		--k;
		if (k <= 0) break;
		int nodeNumInQ = q.size();
		while (nodeNumInQ--)
		{
			ptrNode = q.front();
			q.pop();
			if (ptrNode->pLeft != NULL)
			{
				q.push(ptrNode->pLeft);
			}
			if (ptrNode->pRight != NULL)
			{
				q.push(ptrNode->pRight);
			}
		}
	}
	return q.size();
}


/*********************************************************
* �ж��������ṹ�Ƿ�ṹ��ͬ 
* 1.�����������Ϊ�գ�����true;
* 2.���һ��Ϊ�գ�һ����Ϊ�գ� ����flase
* 3.�������Ϊ��, ���ж϶�Ӧ�����������Ƿ�ṹ��ͬ�� 
**********************************************************/
bool StructureCmp(BinaryTree Tree1, BinaryTree Tree2)
{
	if (Tree1 == NULL && Tree2 == NULL)
	{
		return true;
	}
	if (Tree1 == NULL && Tree2 != NULL || Tree1 != NULL && Tree2 == NULL)
	{
		return false;
	}

	bool left = StructureCmp(Tree1->pLeft, Tree2->pLeft);
	bool right = StructureCmp(Tree1->pRight, Tree2->pRight);
	return (left && right);
}


/*********************************************************
* �ж������ӽṹ 
* ����������A��B���ж���B�Ƿ�����A���ӽṹ
* 1.�����������Ϊ�գ�����false;
* 2.���һ��Ϊ�գ�һ����Ϊ�գ� ����flase
* 3.�������Ϊ��, ���ж϶�Ӧ���Ƿ����ӽṹ�� 
* 4.���裺
*	1����A���ҵ���B�ĸ��ڵ��ֵ��ͬ�Ľڵ�R
*	2���ж���A����RΪ���ڵ�������ǲ��ǰ�������Bһ���Ľṹ
* ��ָoffer����18��
**********************************************************/
bool DoesTreeAHaveTreeB(BinaryTree TreeA, BinaryTree TreeB);
bool HasSubtree(BinaryTree TreeA, BinaryTree TreeB)
{
	bool result = false;
	if (TreeA != NULL && TreeB != NULL)
	{
		if (TreeA->data == TreeB->data)
		{
			result = DoesTreeAHaveTreeB(TreeA,TreeB);
		}
		if (!result)
		{
			result = HasSubtree(TreeA->pLeft, TreeB);
		}
		if (!result)
		{
			result = HasSubtree(TreeA->pRight, TreeB);
		}
	}
	return result;
}

bool DoesTreeAHaveTreeB(BinaryTree TreeA, BinaryTree TreeB)
{
	if (TreeA == NULL)
	{
		return false;
	}
	if (TreeB == NULL)
	{
		return true;
	}

	return DoesTreeAHaveTreeB(TreeA->pLeft, TreeB->pLeft) && DoesTreeAHaveTreeB(TreeA->pRight, 
		TreeB->pRight);
}




/*********************************************************
* �ж����Ƿ���ƽ�������
* 1.�����Ϊ�գ�����true;
* 2.�����Ϊ��, ���ж����������Ƿ���AVL�������������߶�������1���򷵻�true����������false�� 
**********************************************************/
bool IsAVL(BinaryTree Tree, int& Height)
{
	if (Tree == NULL)
	{
		return true;
	}

	int leftHeight = 0;
	int rightHeight = 0;
	bool isLeftAVL = IsAVL(Tree->pLeft, leftHeight);
	bool isRightAVL = IsAVL(Tree->pRight, rightHeight);
	Height = leftHeight >= rightHeight?leftHeight+1:rightHeight+1;

	if (isLeftAVL && isRightAVL && abs(leftHeight - rightHeight) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}



/*********************************************************
* ��������ľ��� 
* 1.������������;
**********************************************************/
void TreeMirror(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return ;
	}
	PtrNode ptrNode = NULL;
	ptrNode = Tree->pLeft;
	Tree->pLeft = Tree->pRight;
	Tree->pRight = ptrNode;

	TreeMirror(Tree->pLeft);
	TreeMirror(Tree->pRight);
}

/*********************************************************
* �ؽ�������
* ���ݶ���������������������ؽ�������
* ��ָoffer 6��;���֮��3.9
**********************************************************/
PtrNode ConstructBinaryTree(int* startPerOrder, int* endPerOrder, int* startInOrder, int* endInOrder);
BinaryTree RebuildTree(int* PerOrder, int* InOrder, int length)
{
	if (PerOrder == NULL || InOrder == NULL || length <= 0)
	{
		return NULL;
	}

	BinaryTree rebuildTree = NULL;
	rebuildTree = ConstructBinaryTree(PerOrder, PerOrder+length-1, InOrder, InOrder+length-1);

	return rebuildTree;
}
PtrNode ConstructBinaryTree(int* startPerOrder, int* endPerOrder, int* startInOrder, int* endInOrder)
{
	PtrNode rootNode = new TreeNode; 
	rootNode->pLeft = rootNode->pRight = NULL;
	rootNode->data = startPerOrder[0];

	int* ptrInOrder = startInOrder;
	while (*ptrInOrder != rootNode->data && ptrInOrder <= endInOrder)
		++ptrInOrder;
	int leftLen = ptrInOrder - startInOrder;

	if (leftLen > 0)
	{
		rootNode->pLeft = ConstructBinaryTree(startPerOrder+1, startPerOrder+leftLen,
			startInOrder, startInOrder+leftLen-1);
	}
	if (leftLen < endPerOrder - startPerOrder)
	{
		rootNode->pRight = ConstructBinaryTree(startPerOrder+leftLen+1, endPerOrder,
			startInOrder+leftLen+1, endInOrder);
	}

	return rootNode;
}



/*********************************************************
* ����͹������� 
* 1.��������ڵ�Ϊ���ڵ�������ӽڵ㣬�򷵻ظ��ڵ�
* 2.�����������������ݹ鴦���������������������������ݹ鴦��������
**********************************************************/
bool FindNode(BinaryTree Tree, PtrNode pNode)
{
	if (Tree == NULL)
	{
		return false;
	}
	if (Tree == pNode)
	{
		return true;
	}
	bool found = FindNode(Tree->pLeft, pNode);
	if (!found)
	{
		found = FindNode(Tree->pRight, pNode);
	}

	return found;
}
PtrNode GetLastCommonParent(BinaryTree Tree, PtrNode pNode1, PtrNode pNode2)
{
	if (Tree == NULL || pNode1 == NULL || pNode2 == NULL)
	{
		return NULL;
	}
	if (FindNode(Tree->pLeft, pNode1))
	{
		if (FindNode(Tree->pRight, pNode2))
		{
			return Tree;
		}
		else
			return GetLastCommonParent(Tree->pLeft, pNode1, pNode2);
	}
	else if (FindNode(Tree->pRight, pNode1))
	{
		if (FindNode(Tree->pLeft, pNode2))
		{
			return Tree;
		}
		else
			return GetLastCommonParent(Tree->pRight, pNode1, pNode2);
	}
}

//�ݹ�ⷨ����
PtrNode GetLCA(BinaryTree Tree, PtrNode pNode1, PtrNode pNode2)
{
	if (Tree == NULL)
	{
		return NULL;
	}
	if (Tree == pNode1 || Tree == pNode2)
	{
		return Tree;
	}
	
	PtrNode leftNode = GetLCA(Tree->pLeft, pNode1, pNode2);
	PtrNode rightNode = GetLCA(Tree->pRight, pNode1, pNode2);

	if (leftNode != NULL && rightNode != NULL)
	{
		return Tree;
	}
	else if (leftNode != NULL)
	{
		return leftNode;
	}
	else if (rightNode != NULL)
	{
		return rightNode;
	}
	else
		return NULL;
}

//�ǵݹ�ⷨ������������ڵ�Ӹ��ڵ㿪ʼ��·����Ȼ��Ƚ�·���ڵ㣬���һ����ͬ�ľ��ǹ������Ƚڵ�
bool GetNodePath(BinaryTree Tree, PtrNode pNode, list<PtrNode>& path)
{
	if (Tree == NULL)
	{
		return false;
	}
	path.push_back(Tree);
	if (Tree == pNode)
	{
		return true;
	}

	bool found = GetNodePath(Tree->pLeft, pNode, path);
	if (!found)
	{
		found = GetNodePath(Tree->pRight, pNode, path);
	}

	if (!found)
	{
		path.pop_back();
	}

	return found;
}
PtrNode GetLastCommonParentNoRecur(BinaryTree Tree, PtrNode pNode1, PtrNode pNode2)
{
	if (Tree == NULL)
	{
		return NULL;
	}
	list<PtrNode> path1;
	bool foundNode1 = GetNodePath(Tree, pNode1, path1);
	list<PtrNode> path2;
	bool foundNode2 = GetNodePath(Tree, pNode2, path2);
	if (!foundNode1 || !foundNode2)
	{
		return NULL;
	}

	PtrNode lastCommonNode = NULL;
	list<PtrNode>::iterator iter1 = path1.begin();
	list<PtrNode>::iterator iter2 = path2.begin();
	while (iter1 != path1.end() && iter2 != path2.end())
	{
		if (*iter1 == *iter2)
		{
			lastCommonNode = *iter1;
		}
		else
			break;
		iter1++;
		iter2++;
	}
	return lastCommonNode;
}



/*********************************************************
* ��������нڵ��������
* 1.���Ϊ�գ����������Ϊ0,ͬʱ����������������Ϊ0
* 2.�����Ϊ�գ���������Ҫô�������������ȣ�Ҫô��������
*	�����ȣ�Ҫô����������������֮�ͣ�ͬʱ��¼����
*	������������
* ��ָoffer�����֮��3.8
**********************************************************/
int GetLargestDestInNode(BinaryTree Tree, int& nMaxLeft, int& nMaxRight)
{
	if (Tree == NULL)
	{
		nMaxLeft = 0;
		nMaxRight = 0;
		return 0;
	}
	int maxLL = 0, maxLR = 0;
	int maxRL = 0, maxRR = 0;
	int maxDistLeft = 0;
	int maxDistRight = 0;
	if (Tree->pLeft == NULL)
	{
		maxDistLeft = 0;
		nMaxLeft = 0;
	}
	if (Tree->pRight == NULL)
	{
		maxDistRight = 0;
		nMaxRight = 0;
	}

	if(Tree->pLeft != NULL)
	{
		maxDistLeft = GetLargestDestInNode(Tree->pLeft, maxLL, maxLR);
		nMaxLeft = maxLL>maxLR?maxLL+1:maxLR+1;
	}
	if(Tree->pRight != NULL)
	{
		maxDistRight = GetLargestDestInNode(Tree->pRight, maxRL, maxRR);
		nMaxRight = maxRL>maxRR?maxRL+1:maxRR+1;
	}

	int maxDist = maxDistLeft>maxDistRight?maxDistLeft:maxDistRight;
	int nMax = nMaxLeft + nMaxRight;
	return maxDist>nMax?maxDist:nMax;
}

/*********************************************************
* ��������к�Ϊĳһֵ��·��
* ·�����Ӹ��ڵ㵽Ҷ�ӽڵ��·��
* 1.�����Ϊ�գ���·��Ϊ��
* 2.�������Ϊ�գ���Ӹ��ڵ㿪ʼ��������ǰ�������,�����Ĺ����м�¼·��
*	����¼��������·���ĺͣ����������Ҷ�ӽڵ㣬�жϺ��Ƿ�Ϊ����ֵ��
*	����ǣ��������·����Ȼ���ٻص���һ���ڵ㡣
*	��¼�ڵ��·������һ��ջ�ṹ��
* ע�⣺�ڻص���һ������ʱ��Ҫ��Ҷ�ӽڵ��ջ
* ��:������vectorʵ�֣�����Ϊ��Ҫ��ӡ·��ʱ��stack�޷�������ӡ
* ��ָoffer25��
**********************************************************/
void GetRoad(BinaryTree Tree, vector<int>& path, const int& expectedSum, int& currentSum);
void GetRoad(BinaryTree Tree, int expectedSum)
{
	if (Tree == NULL)
	{
		return;
	}
	vector<int> path;
	int currentSum = 0;
	GetRoad(Tree, path, expectedSum, currentSum);
	return ;
}
void GetRoad(BinaryTree Tree, vector<int>& path, const int& expectedSum, int& currentSum)
{
	if (Tree == NULL)
	{
		return ;
	}

	path.push_back(Tree->data);
	currentSum += Tree->data;
	bool isLeaf = Tree->pLeft == NULL && Tree->pRight == NULL;
	if (isLeaf && expectedSum == currentSum)
	{
		cout << "��Ϊ" << expectedSum << "��·��Ϊ�� ";
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}

	GetRoad(Tree->pLeft, path, expectedSum, currentSum);
	GetRoad(Tree->pRight, path, expectedSum, currentSum);

	if (!path.empty())
	{
		//�ڷ��ظ��ڵ�֮ǰ��Ӧ�ô�currentSum�м�ȥ��ǰ�ڵ��ֵ����Ϊ�������ݵĲ���currentSum�������ô��ݵ�
		//��currentSum�Ƿ����ô��ݶ���һ�㴫ֵ(��int currentSum)�������ⲽ����
		currentSum -= path.back(); 
	}
	path.pop_back(); //�ڷ��ص����ڵ�֮ǰ��ɾ��·���ϵ�ǰ�Ľڵ�
}


/*********************************************************
* �ж϶������Ƿ�����ȫ������
* 1.�����Ϊ�գ��򷵻�true
* 2.�������Ϊ�գ���Ӹ��ݲ����������������һ��������Ϊ�յĽڵ�
*	��һ��������Ϊ�յĽڵ��������ҲΪ�գ��������Ժ�����нڵ�
*	������������Ϊ�յĻ�����Ϊ��ȫ������������true
*	���򣬲�����ȫ������������false
**********************************************************/
bool IsCompleteBinaryTree(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return true;
	}

	queue<PtrNode> q;
	PtrNode ptrNode = Tree;
	q.push(ptrNode);
	
	PtrNode ptrFirNode = NULL;
	while (!q.empty())
	{
		ptrNode = q.front();
		if (ptrFirNode != NULL && (ptrNode->pLeft != NULL || ptrNode->pRight != NULL))
		{
			return false;
		}
		if (ptrFirNode == NULL && (ptrNode->pLeft == NULL || ptrNode->pRight == NULL))
		{
			ptrFirNode = ptrNode;
		}
		q.pop();

		if (ptrNode->pLeft != NULL)
		{
			q.push(ptrNode->pLeft);
		}
		if (ptrNode->pRight != NULL)
		{
			q.push(ptrNode->pRight);
		}
	}

	return true;
}




int main()
{
	cout << "����������..." << endl;
	BinaryTree Tree = CreateBinaryTree();
	BinaryTree Tree2 = CreateBinaryTree2();
	BinaryTree Tree4 = CreateBinaryTree4();


	int treeDepth = GetTreeDepth(Tree);
	cout << "��������ȣ� " << treeDepth << endl;

	int nodeNum = GetNodeNumber(Tree);
	cout << "�������������� " << nodeNum << endl;

	cout << "�������..." << endl;
	PerOrderPrint(Tree);
	cout << endl;

	cout << "�ǵݹ��������..." << endl;
	PerOrderPrintNoRecursive(Tree);
	cout << endl;

	cout << "�������..." << endl;
	InOrderPrint(Tree);
	cout << endl;

	cout << "�ǵݹ��������..." << endl;
	InOrderPrintNoRecursive(Tree);
	cout << endl;

	cout << "�ǵݹ�������..." << endl;
	//PostOrderNoRecursive(Tree);
	cout << endl;

	cout << "�������..." << endl;
	LayerOrderPrint(Tree);
	cout << endl;

	//int nodeNum = GetNodeNumber(Tree);
	//cout << "�������������� " << nodeNum << endl;


	int leavesNum = GetLeavesNumber(Tree);
	cout << "Ҷ�ڵ�ĸ����� " << leavesNum << endl;

//	//ת����˫������
//	PtrNode treeToList = ConvertToList(Tree);
//	cout << "˫�������������Ҵ�ӡ��" <<endl;
//	PrintList(treeToList);

	//��K��Ľڵ���
	int k = 3;
	//int nodeNumInK = GetNodeNumInLayerK(Tree, k) - GetNodeNumInLayerK(Tree, k - 1);
	int nodeNumInK = GetNodeNumInLayerK(Tree, k);
	cout << "��" << k << "��ڵ����� " << nodeNumInK<< endl; 
	int nodeNumInK2 = GetNodeNumInLayerKByLayerPrint(Tree, k);
	cout << "���ݲ����������õ�" << k << "��ڵ����� " << nodeNumInK2<< endl; 


	//�ж��������ṹ�Ƿ���ͬ��
	cout << "�ж��������ṹ�Ƿ���ͬ�� " << StructureCmp(Tree, Tree2) << endl;

	//�ж�B�Ƿ���A���ӽṹ��
	bool hasSubtree = HasSubtree(Tree, Tree4);
	cout << "�Ƿ����ӽṹ"  << hasSubtree << endl;

	//�ж����Ƿ���AVL����
	int height = 0;
	bool isAvl = IsAVL(Tree, height);
	cout << "�Ƿ���AVL���� " << isAvl << endl;

	//�������ľ���
	TreeMirror(Tree);
	cout << "������������";
	LayerOrderPrint(Tree);
	//�ָ�ԭ״��
	TreeMirror(Tree);
	cout << endl;

	//��������������ؽ�������
	int length = nodeNum;
	int perOrder[] = {1,2,4,8,10,11,9,5,3,6,7};
	int inOrder[] = {10,8,11,4,9,2,5,1,6,3,7};
	BinaryTree rebuildTree = RebuildTree(perOrder, inOrder, length);
	cout << "�ؽ����������� ";
	LayerOrderPrint(rebuildTree);
	cout << endl;

	//Ѱ����͹������Ƚڵ�
	PtrNode commonParentNode = GetLastCommonParent(Tree, Tree->pLeft->pLeft->pLeft, Tree->pRight->pRight);
	cout << commonParentNode->data << endl;
	commonParentNode = GetLastCommonParent(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA�� " << commonParentNode->data << endl;
	//�ǵݹ鷽���󹫹����Ƚڵ㣺
	commonParentNode = GetLastCommonParentNoRecur(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA�� " << commonParentNode->data << endl;
	//�ǵݹ鷽���󹫹����Ƚڵ㣺
	//�ݹ鷽������
	commonParentNode = GetLCA(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA�� " << commonParentNode->data << endl;
	

	//�������ڵ�֮���������
	int nMaxLeft = 0;
	int nMaxRight = 0;
	int nMaxLen = GetLargestDestInNode(Tree, nMaxLeft, nMaxRight);
	cout << nMaxLen << endl;


	//��Ϊĳһ��ֵ��·��
	int expectedSum = 22;
	BinaryTree Tree3 = CreateBinaryTree3();
	GetRoad(Tree3, expectedSum);

	//�ж϶������Ƿ�����ȫ������
	bool isCompleteTree = IsCompleteBinaryTree(Tree);
	cout << "�Ƿ�����ȫ�������� " << isCompleteTree << endl;


	return 0;
}