/*******************************************************************************************
* 15. �ڸ����ַ������ҳ����ʣ� �����ʡ��ɴ�д��ĸ��Сд��ĸ�ַ����ɣ���������ĸ�ַ���Ϊ���ʵļ����
* ��ո��ʺš����ֵȵȣ����ⵥ����ĸ���㵥�ʣ����ҵ����ʺ󣬰��ճ��Ƚ��н������򣬣�����ʱ���
* ������ͬ���򰴳��ֵ�˳��������У���Ȼ�������һ���µ��ַ����У����ĳ�������ظ����ֶ�Σ���ֻ
* ���һ�Σ��������������ַ�����û���ҵ����ʣ�������մ�������ĵ���֮��ʹ��һ�����ո񡱸�������
* ��һ�����ʺ󲻼ӿո�    
* Ҫ��ʵ�ֺ�����
* void my_word(charinput[], char output[])
* �����롿 char input[], ������ַ���
* ������� char output[]��������ַ���
* �����ء� ��
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

	//��ӡ�����е�world��
	cout << "��ӡ�����е�world��"<<endl;
	for (j = 0; j < numOfWorld; j++)
	{
		cout << world[j] << " " ;
	}
	cout << endl;

	//���ճ��������ò�������
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


	//��ӡ�����е�world��
	cout << "��ӡ����������е�world��"<<endl;
	for (j = 0; j < numOfWorld; j++)
	{
		cout << world[j] << " " ;
	}
	cout << endl;


	//ȥ���ظ��ĵ��ʣ�
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


	//��������������һ��
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
	cout << "�����ɸѡ�ַ�����" <<endl;
	cin >> input ;
	my_world(input, output);

	cout << "���ɸѡ��ĵ��ʣ�" << endl;
	printf("%s", output);



	return 0;

}
