//main.cpp
#include "vector.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::find;
using std::copy;
using std::uninitialized_fill_n;
using std::uninitialized_copy;
using std::max;
using std::fill;
using std::copy_backward;

int main(void) {
	size_t i;
	vector<int> ivec(1, 9);
	cout << "size=" << ivec.size() << endl;					// size=1
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=1

	ivec.push_back(1);
	cout << "size=" << ivec.size() << endl;					// size=2
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=2

	ivec.push_back(2);
	cout << "size=" << ivec.size() << endl;					// size=3
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=4

	ivec.push_back(3);
	cout << "size=" << ivec.size() << endl;					// size=4
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=4

	ivec.push_back(4);	
	cout << "size=" << ivec.size() << endl;					// size=5
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8
	for(i=0; i<ivec.size(); i++) {
		cout << ivec[i] << " ";							// 9 1 2 3 4
	}
	cout << endl;

	ivec.push_back(5);
	cout << "size=" << ivec.size() << endl;					// size=6
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8
	for(i=0; i<ivec.size(); i++) {
		cout << ivec[i] << " ";							// 9 1 2 3 4 5
	}
	cout << endl;

	ivec.pop_back();
	ivec.pop_back();
	cout << "size=" << ivec.size() << endl;					// size=4
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8

	ivec.pop_back();
	cout << "size=" << ivec.size() << endl;					// size=3
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8

	vector<int>::iterator iter2 =find(ivec.begin(), ivec.end(), 1);
	if(iter2 != ivec.end()) {
		ivec.erase(iter2);
	}
	cout << "size=" << ivec.size() << endl;					// size=2
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8
	for(i=0; i<ivec.size(); i++) {
		cout << ivec[i] << " ";							// 9 2
	}
	cout << endl;

	vector<int>::iterator iter1 =find(ivec.begin(), ivec.end(), 2);
	if(iter1 != ivec.end()) {
		ivec.insert(iter1, 3, 7);
	}
	cout << "size=" << ivec.size() << endl;					// size=5
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8
	for(i=0; i<ivec.size(); i++) {
		cout << ivec[i] << " ";							// 9 7 7 7 2
	}
	cout << endl;

	ivec.clear();
	cout << "size=" << ivec.size() << endl;					// size=0
	cout << "capacity=" << ivec.capacity() << endl;			// capacity=8

	system("pause");
	return 0;
}