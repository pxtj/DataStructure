/***********************************************************************************
* 20. 输入一串字符串，其中有普通的字符与括号组成（包括‘（’、‘）’、‘[’,']'）,
* 要求验证括号是否匹配，如果匹配则输出0、否则输出1.

* 思路1：用数组；
* 思路2：用栈结构

*20140809
***********************************************************************************/

#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//用数组：//有点问题
int BracketMatch(char* str)
{
	if (str == NULL)
	{
		return 1;
	}

	int len = strlen(str);

	char a[1000] = {0};
	int i = 0, j = 0;
	int flag = 0;
	
	for (i = 0; i < len && str[i] != '\0' && flag == 0; i++)
	{
		switch(str[i])
		{
		case('('):
		case('['):
		case ('{'):
			a[j++] = str[i];
			break;
		case (')'):
			if (j - 1 >= 0 && a[j - 1] == '(')
			{
				a[j - 1] = '\0';
				j--;
			}
			else
				flag = 1;
			break;
		case (']'):
			if (j - 1 >= 0 && a[j - 1] == '[')
			{
				a[j - 1] = '\0';
				j--;
			}
			else
				flag = 1;
			break;
		case ('}'):
			if(j - 1 >= 0 &&a[j - 1] == '{')
			{
				a[j - 1] = '\0';
				j--;
			}
			else
				flag = 1;
			break;
		}
	}

	return flag;
}


//用栈：调用STL栈结构
int BracketMatchByStack(char* str)
{
	if (str == NULL)
	{
		return 1;
	}

	stack<char> braSta;
	int len = strlen(str);
	int i = 0;
	int flag = 0;
	int leftBra  = 0;
	int rightBra = 0;
	for (i = 0; i < len && str[i] != '\0' && flag == 0; i++)
	{
		switch(str[i])
		{
		case ('('):
			leftBra++;
		case ('['):
		case ('{'):
			braSta.push(str[i]);
			break;
		case (')'):
			rightBra++;
			if (!braSta.empty() && braSta.top() == '(')
			{
				braSta.pop();
			}
			else
				flag = 1;
			break;
		case (']'):
			if (!braSta.empty() && braSta.top() == '[')
			{
				braSta.pop();
			}
			else
				flag = 1;
			break;
		case ('}'):
			if (!braSta.empty() && braSta.top() == '}' )
			{
				braSta.pop();
			}
			else
				flag = 1;
			break;
		}
	}

	if (rightBra < 1 || leftBra < 1)
	{
		flag = 1;
	}
	cout << flag << " " << leftBra << " " << rightBra << endl;


	return flag;

}







void Test()
{
	char str[100];
	cout << "请输入字符串： ";
	gets(str);
	//scanf("%s", str);

	int matchOrNot = BracketMatch(str);
	cout << "是否匹配：" << matchOrNot << "(匹配：0；不匹配：1)" << endl;
	
	int mon = BracketMatchByStack(str);
	cout << "是否匹配：" << mon << "(匹配：0；不匹配：1)" << endl;

	fflush(stdin);
	

}



int main()
{
	Test();

	return 0;
}