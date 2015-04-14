/************************************************************************/
/* 14. �ִ�ת��
����������
��������ַ������ַ���������Сд��ĸ��a������z�������������¹���ѭ��ת���������
a->b,b->c,��,y->z,z->a����������ַ�����������������ĸ��ͬʱ����һ����ĸ��Ҫ
����ת��2�Ρ����磺aa ת��Ϊ bc��zz ת��Ϊ ab����������ͬ��ĸ��������ʱ������
�����ֵ���ĸ����һ�γ����㡣
Ҫ��ʵ�ֺ�����
void convert(char *input,char* output)
�����롿 char *input , ������ַ���
������� char *output ��������ַ���
�����ء� ��
                                                                     */

//20140808
/************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void Convert(char* input, char* output)
{
	if (input == NULL || output == NULL)
	{
		return ;
	}
	
	int len1 = strlen(input);

	if (len1 == 0)
	{
		return ;
	}

	int flag = 1;
	char temp = '\0';
	int i = 0;
	for (i = 0; i < len1; i++)
	{
		if (input[i] != temp)
		{
			output[i] = (input[i] - 'a' + 1)%26 + 'a';
			temp = input[i];
			flag = 1;
		}
		else
		{
			if (flag == 1)
			{
				output[i] = (input[i] - 'a' + 2)%26 + 'a';
				temp = input[i];
				flag = 0;
			}
			else if (flag == 0)
			{
				output[i] = (input[i] - 'a' + 1)%26 + 'a';
				temp = input[i];
				flag = 1;
			}
		}
	}

	output[i] = '\0';

}


int main()
{
	char input[100];
	char output[100] = {0};

	printf("�������ַ�����\n");
	scanf("%s", input);

	Convert(input, output);

	printf("%s\n", output);

	return 0;
}

