/***********************************************************************************
* 20. ����һ���ַ�������������ͨ���ַ���������ɣ�����������������������[��,']'��,
* Ҫ����֤�����Ƿ�ƥ�䣬���ƥ�������0���������1.

* ˼·1�������飻
* ˼·2����ջ�ṹ

*20140809
***********************************************************************************/

#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//�����飺//�е�����
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


//��ջ������STLջ�ṹ
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
	cout << "�������ַ����� ";
	gets(str);
	//scanf("%s", str);

	int matchOrNot = BracketMatch(str);
	cout << "�Ƿ�ƥ�䣺" << matchOrNot << "(ƥ�䣺0����ƥ�䣺1)" << endl;
	
	int mon = BracketMatchByStack(str);
	cout << "�Ƿ�ƥ�䣺" << mon << "(ƥ�䣺0����ƥ�䣺1)" << endl;

	fflush(stdin);
	

}



int main()
{
	Test();

	return 0;
}