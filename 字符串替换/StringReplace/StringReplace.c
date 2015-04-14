////CÓïÑÔÊµÏÖ£º
//
//void ReplaceString(char* str, char* pSrcToReplaceStr)
//{
//	assert(str != NULL);
//	char* p, *q, *s;
//	char replacedStr[100] = {0};
//	char srcStr[100] = {0};
//	char replaceStr[100] = {0};
//
//	p = strstr(pSrcToReplaceStr, "->");
//	if (p == NULL)
//	{
//		exit(-1);
//	}
//
//	memccpy(srcStr, pSrcToReplaceStr, p - pSrcToReplaceStr);
//	strcpy(replaceStr, pSrcToReplaceStr + (p - pSrcToReplaceStr));
//
//	p = str;
//	q = replacedStr;
//	
//	while(p != NULL)
//	{
//		s = p;
//		p = strstr(p, srcStr);
//		if (p == NULL)
//		{
//			break;
//		}
//		memccpy(q, srcStr, s - p);
//		p += strlen(srcStr);
//		q += strlen(srcStr);
//		strcpy(q, replaceStr);
//		q += strlen(replaceStr);
//	}
//	strcpy(q, s);
//	memset(str, 0, 100);
//	strcpy(str, replacedStr);
//}
//
//int main()
//{
//	int count = 0;
//	char str[100] = {0}:
//	char replaceStr[100] = {0};
//	scanf("%s", str);
//	fflush(stdin);
//	scanf("%d", &count);
//
//	while (count--)
//	{
//		fflush(stdin);
//		scanf("%s", replaceStr);
//		ReplaceString(str, replaceStr);
//	}
//	printf("%s", str);
//
//	return 0;
//}