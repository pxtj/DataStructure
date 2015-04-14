//二叉树问题集：
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


//建立二叉树：
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

//先序遍历：递归
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

//中序遍历：递归
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

//后序遍历：递归
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
/* 二叉树的非递归遍历:先序，中序、后序、及层序遍历
/************************************************************************/
/************************************************************************
* 非递归先序遍历：
* 方法：用栈结构，
*	1.先让右子树节点进栈，再让左子树节点进栈
*	2.如果栈非空，则进行出栈操作
*	类似于层序遍历
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
		if (ptrNode->pRight != NULL) //注意：先序遍历先让右子树节点入栈
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
* 非递归中序遍历：
* 方法：用栈结构，
*	1.
*	2.
************************************************************************/
void InOrderPrintNoRecursive(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return;
	}

	PtrNode ptrCurrent = Tree; //指明当前要检测的数据,此时根节点不要先入栈
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
* 非递归后序遍历：
* 方法：用栈结构，
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



//层序遍历二叉树
void LayerOrderPrint(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return ;
	}

	int nodeNumInTree = 0; //  记录节点的个数
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
	//cout << "节点的个数： " << nodeNumInTree;

	return ;
}


//求书中结点的个数
int GetNodeNumber(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return 0;
	}
	return GetNodeNumber(Tree->pLeft) + GetNodeNumber(Tree->pRight) + 1;
}

//求叶子节点的个数：
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

//求二叉树深度
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

//将二叉树变为有序的双向链表 剑指offer27题
void ConvertToDoubleList(BinaryTree Tree, PtrNode* listNode);
BinaryTree ConvertToList(BinaryTree Tree)
{
	if (Tree == NULL)
	{
		return NULL;
	}

	PtrNode listNode = NULL;
	ConvertToDoubleList(Tree, &listNode);

	//返回头结点：
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
//转换成双向链表完


/*********************************************************
* 求二叉树第K层的节点数
* 1.如果树为空或者K<1，返回0
* 2.如果K == 1， 返回1
* 3.如果K>1, 节点数等于左子树第K-1层节点与右子树第K-1层之和
**********************************************************/
//递归
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
//非递归，根据层序遍历，求出第K层节点数
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
* 判断两个树结构是否结构相同 
* 1.如果两个树都为空，返回true;
* 2.如果一个为空，一个不为空， 返回flase
* 3.如果都不为空, 则判断对应的左右子树是否结构相同， 
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
* 判断树的子结构 
* 输入两个树A和B，判断树B是否是树A的子结构
* 1.如果两个树都为空，返回false;
* 2.如果一个为空，一个不为空， 返回flase
* 3.如果都不为空, 则判断对应的是否是子结构， 
* 4.步骤：
*	1）在A中找到和B的根节点的值相同的节点R
*	2）判断树A中以R为根节点的子树是不是包含和树B一样的结构
* 剑指offer，第18题
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
* 判断树是否是平衡二叉树
* 1.如果树为空，返回true;
* 2.如果不为空, 则判断左右子树是否都是AVL，且左右子树高度相差不大于1，则返回true，其他返回false， 
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
* 求二叉树的镜像 
* 1.左右子树交换;
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
* 重建二叉树
* 根据二叉树的先序及中序遍历，重建二叉树
* 剑指offer 6题;编程之美3.9
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
* 找最低公共祖先 
* 1.如果两个节点为根节点的左右子节点，则返回根节点
* 2.如果都在左子树，则递归处理左子树，如果都在右子树，则递归处理右子树
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

//递归解法二：
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

//非递归解法：先求出两个节点从根节点开始的路径，然后比较路径节点，最后一个相同的就是公共祖先节点
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
* 求二叉树中节点的最大距离
* 1.如果为空，则最大距离就为0,同时左右子树的最大深度为0
* 2.如果不为空，则最大距离要么是左子树最大深度，要么是右子树
*	最大深度，要么是左右子树最大深度之和，同时记录左右
*	子树的最大深度
* 剑指offer；编程之美3.8
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
* 求二叉树中和为某一值得路径
* 路径：从根节点到叶子节点的路径
* 1.如果树为空，则路径为空
* 2.如果树不为空，则从根节点开始遍历（即前序遍历）,遍历的过程中记录路径
*	并记录遍历过的路径的和，如果遍历到叶子节点，判断和是否为所给值，
*	如果是，则输出此路径，然后再回到上一个节点。
*	记录节点的路径就是一个栈结构，
* 注意：在回到上一个几点时，要将叶子节点出栈
* 另:本题用vector实现，是因为需要打印路径时，stack无法遍历打印
* 剑指offer25题
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
		cout << "和为" << expectedSum << "的路径为： ";
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
		//在返回父节点之前，应该从currentSum中减去当前节点的值，因为函数传递的参数currentSum是以引用传递的
		//若currentSum是非引用传递而是一般传值(即int currentSum)，则不用这步操作
		currentSum -= path.back(); 
	}
	path.pop_back(); //在返回到父节点之前，删除路径上当前的节点
}


/*********************************************************
* 判断二叉树是否是完全二叉树
* 1.如果树为空，则返回true
* 2.如果树不为空，则从根据层序遍历，遍历到第一个左子树为空的节点
*	第一个左子树为空的节点的右子树也为空，并且其以后的所有节点
*	的左右字数均为空的话，则为完全二叉树，返回true
*	否则，不是完全二叉树，返回false
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
	cout << "建立二叉树..." << endl;
	BinaryTree Tree = CreateBinaryTree();
	BinaryTree Tree2 = CreateBinaryTree2();
	BinaryTree Tree4 = CreateBinaryTree4();


	int treeDepth = GetTreeDepth(Tree);
	cout << "二叉树深度： " << treeDepth << endl;

	int nodeNum = GetNodeNumber(Tree);
	cout << "二叉树结点个数： " << nodeNum << endl;

	cout << "先序遍历..." << endl;
	PerOrderPrint(Tree);
	cout << endl;

	cout << "非递归先序遍历..." << endl;
	PerOrderPrintNoRecursive(Tree);
	cout << endl;

	cout << "中序遍历..." << endl;
	InOrderPrint(Tree);
	cout << endl;

	cout << "非递归中序遍历..." << endl;
	InOrderPrintNoRecursive(Tree);
	cout << endl;

	cout << "非递归后序遍历..." << endl;
	//PostOrderNoRecursive(Tree);
	cout << endl;

	cout << "层序遍历..." << endl;
	LayerOrderPrint(Tree);
	cout << endl;

	//int nodeNum = GetNodeNumber(Tree);
	//cout << "二叉树结点个数： " << nodeNum << endl;


	int leavesNum = GetLeavesNumber(Tree);
	cout << "叶节点的个数： " << leavesNum << endl;

//	//转换成双向链表
//	PtrNode treeToList = ConvertToList(Tree);
//	cout << "双向链表由左至右打印：" <<endl;
//	PrintList(treeToList);

	//第K层的节点数
	int k = 3;
	//int nodeNumInK = GetNodeNumInLayerK(Tree, k) - GetNodeNumInLayerK(Tree, k - 1);
	int nodeNumInK = GetNodeNumInLayerK(Tree, k);
	cout << "第" << k << "层节点数： " << nodeNumInK<< endl; 
	int nodeNumInK2 = GetNodeNumInLayerKByLayerPrint(Tree, k);
	cout << "根据层序遍历，求得第" << k << "层节点数： " << nodeNumInK2<< endl; 


	//判断两个树结构是否相同：
	cout << "判断两个树结构是否形同： " << StructureCmp(Tree, Tree2) << endl;

	//判断B是否是A的子结构：
	bool hasSubtree = HasSubtree(Tree, Tree4);
	cout << "是否是子结构"  << hasSubtree << endl;

	//判断树是否是AVL树：
	int height = 0;
	bool isAvl = IsAVL(Tree, height);
	cout << "是否是AVL树： " << isAvl << endl;

	//二叉树的镜像：
	TreeMirror(Tree);
	cout << "镜像层序输出：";
	LayerOrderPrint(Tree);
	//恢复原状：
	TreeMirror(Tree);
	cout << endl;

	//由先序及中序遍历重建二叉树
	int length = nodeNum;
	int perOrder[] = {1,2,4,8,10,11,9,5,3,6,7};
	int inOrder[] = {10,8,11,4,9,2,5,1,6,3,7};
	BinaryTree rebuildTree = RebuildTree(perOrder, inOrder, length);
	cout << "重建后层序输出： ";
	LayerOrderPrint(rebuildTree);
	cout << endl;

	//寻找最低公共祖先节点
	PtrNode commonParentNode = GetLastCommonParent(Tree, Tree->pLeft->pLeft->pLeft, Tree->pRight->pRight);
	cout << commonParentNode->data << endl;
	commonParentNode = GetLastCommonParent(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA： " << commonParentNode->data << endl;
	//非递归方法求公共祖先节点：
	commonParentNode = GetLastCommonParentNoRecur(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA： " << commonParentNode->data << endl;
	//非递归方法求公共祖先节点：
	//递归方法二：
	commonParentNode = GetLCA(Tree, Tree->pLeft->pLeft->pLeft, Tree->pLeft->pRight);
	cout << "LCA： " << commonParentNode->data << endl;
	

	//二叉树节点之间的最大距离
	int nMaxLeft = 0;
	int nMaxRight = 0;
	int nMaxLen = GetLargestDestInNode(Tree, nMaxLeft, nMaxRight);
	cout << nMaxLen << endl;


	//和为某一个值得路径
	int expectedSum = 22;
	BinaryTree Tree3 = CreateBinaryTree3();
	GetRoad(Tree3, expectedSum);

	//判断二叉树是否是完全二叉树
	bool isCompleteTree = IsCompleteBinaryTree(Tree);
	cout << "是否是完全二叉树： " << isCompleteTree << endl;


	return 0;
}