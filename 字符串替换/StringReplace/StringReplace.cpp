//C++: µœ÷£∫£∫
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str, str1, str2, str3;
	string jiantou = "->";
	int n = 0;
	while (cin>>str)
	{
		cin>>n;
		while (n--)
		{
			cin>>str1;
			int jtwz = str1.find(jiantou);
			str2 = str1.substr(0, jtwz);
			str3 = str1.substr(jtwz+jiantou.size(), str1.size() - (jtwz+jiantou.size()));
			int counter  = 0;
			int zfwz = 0;
			while (1)
			{
				string strTemp = str.substr(counter, str.size() - counter);
				int posTemp = strTemp.find(str2);
				if (posTemp == -1) break;
				zfwz = counter + posTemp;
				str = str.substr(0, zfwz) + str3 + str.substr(zfwz+str2.size(), str.size()-(zfwz + str2.size()));
				counter = zfwz + str3.size();
			}
		}
		cout<<str<<endl;
		cout<<endl<<"input new string: "<<endl;
	}
	return 0;
}