#include <iostream>
#include "PriorityHeap.h"
using namespace std;

int main()
{
	int i = 0;
	int maxElement;
	cout<<"please input maxElement: ";
	cin>>maxElement;
	cout<<"maxElement: "<< maxElement<<endl;
	
	PriorityQueue ph;
	if(!(ph = Initialize(maxElement)))
	{
		cout<<"initialize failed\n"<<endl;
	}

	int x;
	cin>>x;
	while (x != 0)
	{
		Insert(x, ph);
		cin>>x;
	}
	for (i = 0; i < 5; i++)
	{
		cout<< DeleteMin(ph) <<endl;
	}

	return 0;

}