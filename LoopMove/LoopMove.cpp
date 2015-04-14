#include <iostream>
#include <string>
using namespace std;

void Reverse(string& str, int start, int end)
{
	int i, j;
	i = start;
	j = end;
	while (i < j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int main()
{
	string str;
	int n;
	cout<<"�����ַ���:";
	cin>>str;
	cout<<"������λ������ ";
	cin >> n;

	int len = str.size(); 
	n = n%len;

	Reverse(str, 0, n - 1);
	Reverse(str, n, len - 1);
	Reverse(str, 0, len - 1);

	cout<<str<<endl;

	return 0;

}