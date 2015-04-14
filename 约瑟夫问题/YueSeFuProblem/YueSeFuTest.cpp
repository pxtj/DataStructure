//约瑟夫问题：
//序号从1,开始，1,2,3,4...,n
//f(n, k) = ?
//f(1, 1) = 1;
//f(n, k) = (f(n - 1, k) + k - 1)%n + 1;

//如果序号从0开始，0,1,2,3,4...,n-1
//f(1,1) = 0;
//f(n,k) = (f(n-1, k) + k)%n;

#include <iostream>

using namespace std;

int YueSeFu(int n, int k)
{
	int result = 0;

	if((1 == n)&&(1 == k))
	{
		result = 1;
	}
	else if(0 != n)
	{
		result =  (YueSeFu(--n, k) + k - 1)%(n + 1) + 1;
	}

	return result;
}


int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;

	while(1)
	{

		//1.2.3...n
		cout << "input n = ";
		cin >> n;
		cout << "input k = ";
		cin >> k;
		cout << "n = " << n << endl;
		cout << "k = " << k << endl;

		int result = YueSeFu(n, k);

		cout << "when n = " << n << " k = " << k ;
		cout << "\tthe result is: " << result << endl;

	}
	return 0;


}