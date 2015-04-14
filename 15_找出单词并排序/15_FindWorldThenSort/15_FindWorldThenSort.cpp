/*******************************************************************************************
* 15. 在给定字符串中找出单词（ “单词”由大写字母和小写字母字符构成，其他非字母字符视为单词的间隔，
* 如空格、问号、数字等等；另外单个字母不算单词）；找到单词后，按照长度进行降序排序，（排序时如果
* 长度相同，则按出现的顺序进行排列），然后输出到一个新的字符串中；如果某个单词重复出现多次，则只
* 输出一次；如果整个输入的字符串中没有找到单词，请输出空串。输出的单词之间使用一个“空格”隔开，最
* 后一个单词后不加空格。    
* 要求实现函数：
* void my_word(charinput[], char output[])
* 【输入】 char input[], 输入的字符串
* 【输出】 char output[]，输出的字符串
* 【返回】 无
* 
* 
* 20140808
********************************************************************************************/


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void my_world(char input[], char output[])
{
	int i , j;
	char* p;
	char* temp;
	char* world[10];
	int len = strlen(input);
	
	char except[] = ",";
	char* blank = " ";

	for (i = 0; i < len; i++)
	{
		if (input[i] < 'A' || (input[i] > 'Z'&&input[i] < 'a') || input[i] > 'z')
		{
			input[i] = ',';
		}
	}

	int numOfWorld = 0;
	p = strtok(input, except);
	while (NULL != p)
	{
		if (strlen(p) > 1)
		{
			world[numOfWorld++] = p;
		}
		p = strtok(NULL, except);
	}

	//打印出所有的world：
	cout << "打印出所有的world："<<endl;
	for (j = 0; j < numOfWorld; j++)
	{
		cout << world[j] << " " ;
	}
	cout << endl;

	//按照长度排序，用插入排序：
	for (i = 1; i < numOfWorld; i++)
	{
		temp = world[i];
		for (j = i; j > 0; j--)
		{
			int l1 = strlen(world[j - 1]);
			int l2 = strlen(temp);
			if (l1 > l2)
			{
				world[j] =  world[j - 1];
			}
			else
				break;
		}

		world[j] = temp;
	}


	//打印出所有的world：
	cout << "打印出排序后所有的world："<<endl;
	for (j = 0; j < numOfWorld; j++)
	{
		cout << world[j] << " " ;
	}
	cout << endl;


	//去掉重复的单词：
	for (i = 0; i < numOfWorld; i++)
	{
		for(j = i + 1; j < numOfWorld; j++)
		{
			if (strcmp(world[i], world[j]) == 0)
			{
				world[j] = blank;
			}
		}
	}


	//将各个单词连在一起：
	for (i = 0; i < numOfWorld; i++)
	{
		if (strcmp(world[i], blank) == 0)
		{
			continue;
		}
		if (0 == i)
		{
			strncpy(output, world[i], strlen(world[i]) + 1);
		}
		else
		{
			strcat(output, blank);
			strcat(output, world[i]);
		}
	}

	return ;

}


int main()
{
	char input[100], output[100];
	cout << "输入待筛选字符串：" <<endl;
	cin >> input ;
	my_world(input, output);

	cout << "输出筛选后的单词：" << endl;
	printf("%s", output);



	return 0;

}
