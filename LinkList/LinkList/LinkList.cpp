#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int IsEmpty(List L)
{
	return L->next == NULL;
}

int IsLast(Position P, List L)
{
	return P->next == NULL;
}

Position Find(ElementType X, List L)
{
	if (IsEmpty(L))
	{
		return NULL;
	}
	Position p;
	p = L->next;
	while (p != NULL && p->element != X)
	{
		p = p->next;
	}
	
	return p;
}


void Delete(ElementType X, List L)
{
	Position p, temp;

	p = FindPrevious(X, L);
	if (!IsLast(p, L))
	{
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position p;
	p = L;
	while (p->next != NULL && p->next->element != X)
	{
		p = p->next;
	}

	return p;
}


void Insert(ElementType X, List L, Position p)
{
	Position temp;
	temp = (Position)mallc(sizeof(Node));

	temp->element = X;
	temp->next = p->next;
	p->next = temp;
}

void DeleteList(List L)
{
	Position p1, p2;
	p1 = L->next;
	L->next = NULL;
	while (p1 != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
}