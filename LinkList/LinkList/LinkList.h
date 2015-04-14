#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef int ElementType;
typedef struct Node{
	ElementType element;
	struct Node* next;
}Node;

typedef struct Node* PtrNode;
typedef struct Node* List;
typedef struct Node* Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position FInd(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position p);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position p);
ElementType Retrieve(Position p);


#endif