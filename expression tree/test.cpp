#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	class BinarySearchTree<int> tree;
	for (int i =0;i<1;i++)
	{
		tree.insert(i);
	}
	tree.printTree();
	return 0;
}