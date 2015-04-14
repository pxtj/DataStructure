#pragma  once

class Binarynode
{
public:
	char element;
	Binarynode* leftson;
	Binarynode* rightson;

public: 
	Binarynode()
	{
	
	}
	Binarynode(char theElement, Binarynode* ls, Binarynode* rs)
		:element(theElement),leftson(ls),rightson(rs)
	{}
};

template <typename Comparable>
class BinarySearchTree:public Binarynode
{
public:
	BinarySearchTree();
	//BinarySearchTree(Comparable &rhs);
	~BinarySearchTree(){}

	const Comparable &findMin()const;
	const Comparable &findMax()const;
	bool contains(const Comparable & x)const;
	bool isEmpty()const;
	void printTree()const;

	void makeEmpty();
	void insert(const Comparable & x);
	void remove(const Comparable & x);

	const BinarySearchTree & operator=(const BinarySearchTree & rhs);


private:
	//typedef struct Binarynode
	//{
	//	char element;
	//	Binarynode* leftson;
	//	Binarynode* rightson;
	//	 
	//	Binarynode(char theElement,Binarynode* ls, Binarynode* rs)
	//		:element(theElement),leftson(ls),rightson(rs)
	//	{}
	//}Binarynode;

	BinarySearchTree* root;

	void insert(const Comparable& x,Binarynode* &t)const;
	void remove(const Comparable& x,Binarynode* &t )const;
	Binarynode* findMin(Binarynode*  t)const;
	Binarynode* findMax(Binarynode*  t)const;
	bool contains(const Comparable & x,Binarynode* t)const;
	void makeEmpty(Binarynode* & t);
	void printTree(Binarynode*  t)const;
	Binarynode * clone (Binarynode*  t)const;

};
 
template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{

}

template <typename Comparable >  bool BinarySearchTree< Comparable>::contains(const Comparable & x)const
{ 
	return contains(x,root);
}


template <typename Comparable >  const Comparable & BinarySearchTree< Comparable>::findMin ()const
{
	return findMin(root); 
}


template <typename Comparable > const Comparable & BinarySearchTree< Comparable>::findMax ()const
{
	return findMax(root); 
}

template <typename Comparable > void BinarySearchTree< Comparable>::insert (const Comparable & x)
{
	insert(x,root);
}

template <typename Comparable >  void BinarySearchTree< Comparable>::remove (const Comparable & x)
{
	remove (x,root);
}

template <typename Comparable > void BinarySearchTree< Comparable>::makeEmpty ()
{
    makeEmpty(root);
}

template <typename Comparable > void BinarySearchTree< Comparable>::printTree()const
{
	printTree(root);
}
template <typename Comparable > 
const BinarySearchTree < Comparable> & BinarySearchTree< Comparable>:: operator=(const BinarySearchTree< Comparable> & rhs)
{
	if (this !=rhs)
	{
		makeempty();
		root=clone(rhs.root);
	}
	return *this;
}
////////////////////////////////////////////////////////////////////上部为驱动 下面为实现




template <typename Comparable > void BinarySearchTree< Comparable>::insert(const Comparable & x,Binarynode * & t)const
{
	if (t==NULL)
	{
		t=new Binarynode(x ,NULL,NULL);
	}

	else if (x<t->element)
	{
		insert(x,t->leftson);
	} 
	else if(x>t->element)
	{
		insert(x,t->rightson);
		
	}
}
template <typename Comparable > void BinarySearchTree< Comparable>::remove(const Comparable & x,Binarynode * & t )const
{
	if (t=NULL)
	{
		return;
	}
	if (x<t->leftson)
	{
		remove(x,t->leftson);

	}
	else if (x>t->element)
	{
		remove(x,t->rightson);
	}
	else if (t->element!=NULL&&t->rightson!=NULL)//two sons
	{
		t->element=findMin(t->rightson);
		remove(t->element,t->rightson);
	}
	else// one and zero son
	{
		Binarynode * oldNode=t;

		t=(t->leftson!=NULL)?t->leftson:t->rightson;
		delete oldNode;
	}

}
template <typename Comparable >
Binarynode* BinarySearchTree< Comparable>::findMin(Binarynode *  t)const
{
	/*if (t==NULL)
	{
		return NULL;
	}

	if (t->leftson==NULL)
	 return t;

	return findMin(t->leftson);*/
	
	

}
template <typename Comparable> 
Binarynode* BinarySearchTree<Comparable>::findMax(Binarynode* t)const
{
	if (t==NULL)
	{
		return NULL;
	}
	if (t->leftson!=NULL)
	{
		return findMax(t->leftson);
	} 
	else 
		return t;

}
template <typename Comparable > bool BinarySearchTree< Comparable>::contains(const Comparable & x,Binarynode *  t)const
	{if (t==NULL)
	{
	
		return false;

	}

	else if (x<t->element)
	{
		contains(x,t->leftson);
	} 
	else if(x>t->element)
	{
		contains(x,t->rightson);

	}
	else return true;
	}
template <typename Comparable > void BinarySearchTree< Comparable>::makeEmpty(Binarynode * & t)
{
	if (t!=NULL)
	{
		makeEmpty(t->leftson);
		makeEmpty(t->rightson);
		delete t;
	}
	t=NULL;
}
template <typename Comparable > void BinarySearchTree< Comparable>::printTree(Binarynode *  t)const
{
	if (t!=NULL)
	{
	cout<<t->element<<endl;
	printTree(t->leftson);
	printTree(t->rightson);
	}
}
template <typename Comparable > 
Binarynode* BinarySearchTree< Comparable>::clone (Binarynode *  t)const
{
     if (t==null)
     {
		 return NULL;
     }
	 return new Binarynode(t->element,clone(t->leftson),clone(t->rightson));
}

