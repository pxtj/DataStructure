//¶þ²æËÑË÷Ê÷

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef int Element;

typedef struct TreeNode
{
	Element element;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct TreeNode* PtrNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(SearchTree T, Element x);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(SearchTree T, Element x);
SearchTree Delete(SearchTree T, Element x);
SearchTree Retrieve(Position P);
 

#endif