/************************************************************************/
/* 10. 要求编程实现上述高精度的十进制加法。要求实现函数：
void add (const char *num1, const char *num2, char *result)
【输入】num1：字符串形式操作数1，如果操作数为负，则num1[0]为符号位'-'
num2：字符串形式操作数2，如果操作数为负，则num2[0]为符号位'-'
【输出】result：保存加法计算结果字符串，如果结果为负，则result[0]为符号位。
                                                                     */
/************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void move(char *str, int length)    //移除字母前的"-"符号
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
	for(int i = length-1; i > 0; i--)    //从最后开始移除0，直到遇到非0数字，只对最初位置上的0不予判断
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

void reverse(char *result, int length)        //将字符串倒转
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
	int n1, n2, another = 0;    //another表示进位
	int cur_rs = 0;        //表示result的当前位数
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
		while(i >= 0)        //遍历str1剩余各位
		{
			n1 = str1[i--] - '0';
			curSum = n1 + another;
			result[cur_rs++] = curSum % 10 + '0';
			another = curSum / 10;
		}
		if(another != 0)        //如果还有进位未加上
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


int real_minus(char *str1, char *str2, char *result)    //使用str1减去str2
{
	char big[100], small[100];
	int big_len, sml_len;

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	bool flag = false;        //用于标记str2是否比str1大

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

	if(flag)    //将str1和str2交换，确保str1指向的值是其中较大者，最后通过flag确定要不要给前面加-号
	{
		char *temp = str1;
		str1 = str2;
		str2 = temp;
		len1 = strlen(str1);
		len2 = strlen(str2);
	}

	int n1, n2, another = 0;    //another表示是否有借位
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
	printf("请输入两个整型数据：\n");
	scanf("%s%s",num1,num2);

	char result[100];
	memset(result, 0, 100);
	addi(num1,num2, result);
	printf("%s\n", result);

	return 0;
}
