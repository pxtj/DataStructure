//BinarySearchTree.h

#ifdef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);


#endif

struct TreeNode
{
	ElementType element;
	Position left;
	Position rigth;
};

