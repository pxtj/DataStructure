/************************************************************************/
/* 10. Ҫ����ʵ�������߾��ȵ�ʮ���Ƽӷ���Ҫ��ʵ�ֺ�����
void add (const char *num1, const char *num2, char *result)
�����롿num1���ַ�����ʽ������1�����������Ϊ������num1[0]Ϊ����λ'-'
num2���ַ�����ʽ������2�����������Ϊ������num2[0]Ϊ����λ'-'
�������result������ӷ��������ַ�����������Ϊ������result[0]Ϊ����λ��
                                                                     */
/************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move(char *str, int length)    //�Ƴ���ĸǰ��"-"����
{
	if(str[0] != '-')
		return;
	int i;
	for(i = 0; i < length-1; i++)
		str[i] = str[i+1];
	str[i] = '\0';
}

int remove_zero(char *result, int length)
{
	int count = 0;
	for(int i = length-1; i > 0; i--)    //�����ʼ�Ƴ�0��ֱ��������0���֣�ֻ�����λ���ϵ�0�����ж�
	{
		if(result[i] == '0')
		{
			result[i] = '\0';
			count++;
		}else
			return length-count;
	}
	return length - count;
}

void reverse(char *result, int length)        //���ַ�����ת
{
	char temp;
	for(int i = 0; i <= (length-1)/2; i++)
	{
		temp = result[i];
		result[i] = result[length-1-i];
		result[length-1-i] = temp;
	}
}

int real_add(char *str1, char *str2, char *result, const bool flag)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int n1, n2, another = 0;    //another��ʾ��λ
	int cur_rs = 0;        //��ʾresult�ĵ�ǰλ��
	int i, j;
	int curSum;
	for(i = len1-1, j = len2-1; i >= 0 && j >= 0; i--, j--)
	{
		n1 = str1[i] - '0';
		n2 = str2[j] - '0';
		curSum = n1 + n2 + another;
		result[cur_rs++] = curSum % 10 + '0';
		another = curSum / 10;
	}

	if(j < 0)
	{
		while(i >= 0)        //����str1ʣ���λ
		{
			n1 = str1[i--] - '0';
			curSum = n1 + another;
			result[cur_rs++] = curSum % 10 + '0';
			another = curSum / 10;
		}
		if(another != 0)        //������н�λδ����
			result[cur_rs++] = another + '0';
	}
	else
	{
		while(j >= 0)
		{
			n2 = str2[j--] - '0';
			curSum = n2 + another;
			result[cur_rs++] = curSum % 10 + '0';
			another = curSum / 10;
		}
		if(another != 0)
			result[cur_rs++] = another + '0';
	}

	result[cur_rs] = '\0';

	cur_rs = remove_zero(result, cur_rs);
	if(!flag)
	{
		result[cur_rs++] = '-';
		result[cur_rs] = '\0';
	}
	reverse(result, strlen(result));
	return cur_rs;
}


int real_minus(char *str1, char *str2, char *result)    //ʹ��str1��ȥstr2
{
	char big[100], small[100];
	int big_len, sml_len;

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	bool flag = false;        //���ڱ��str2�Ƿ��str1��

	if(len1 < len2)
		flag = true;
	else if(len1 == len2)
	{
		if(strcmp(str1, str2) == 0)
		{
			result[0] = '0';
			result[1] = '\0';
			return 1;
		}else if(strcmp(str1,str2) < 0)
			flag = true;
	}

	if(flag)    //��str1��str2������ȷ��str1ָ���ֵ�����нϴ��ߣ����ͨ��flagȷ��Ҫ��Ҫ��ǰ���-��
	{
		char *temp = str1;
		str1 = str2;
		str2 = temp;
		len1 = strlen(str1);
		len2 = strlen(str2);
	}

	int n1, n2, another = 0;    //another��ʾ�Ƿ��н�λ
	int i, j;
	int cur_rs = 0;
	int curMinus;

	for(i = len1-1, j = len2-1; i>=0 && j>=0; i--,j--)
	{
		n1 = str1[i] - '0';
		n2 = str2[j] - '0';
		if(n1 >= n2+another)
		{
			result[cur_rs++] = (n1-n2-another) +'0';
			another = 0;
		}
		else
		{
			result[cur_rs++] = (n1+10-n2-another) + '0';
			another = 1;
		}
	}

	while(i >= 0)
	{
		n1 = str1[i--] - '0';
		if(another != 0)
		{
			n1 -= another;
			another = 0;
		}
		result[cur_rs++] = n1 + '0';
	}

	result[cur_rs] = '\0';
	cur_rs = remove_zero(result, cur_rs);
	if(flag)
	{
		result[cur_rs++] = '-';
		result[cur_rs] = '\0';
	}
	reverse(result, cur_rs);

	return cur_rs;
}

void addi(const char *num1, const char *num2, char *result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int rs_len;
	if(!len1 || !len2)
		return;
	char str1[100], str2[100];
	strncpy(str1, num1, len1);
	str1[len1] = '\0';
	strncpy(str2, num2, len2);
	str2[len2] = '\0';

	if(str1[0] == '-' && str2[0] == '-')
	{
		move(str1, len1);
		move(str2, len2);
		rs_len = real_add(str1, str2, result, false);
	}else if(str1[0] == '-')
	{
		move(str1, len1);
		rs_len = real_minus(str2, str1, result);
	}
	else if(str2[0] == '-')
	{
		move(str2, len2);
		rs_len = real_minus(str1, str2, result);
	}else
		rs_len = real_add(str1, str2, result, true);
}

//int main(int argc, char *argv[])
int main()
{
	char num1[100],num2[100];
	printf("�����������������ݣ�\n");
	scanf("%s%s",num1,num2);

	char result[100];
	memset(result, 0, 100);
	addi(num1,num2, result);
	printf("%s\n", result);

	return 0;
}
