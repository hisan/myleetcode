/* 2020-02-23 01:31��δͨ�� */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 	1
#define false 	0
#define bool 	int

/* ����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict��
�ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ� */
bool wordBreak(char * s, char ** wordDict, int wordDictSize)
{
	if(s == NULL || wordDictSize == 0)
    {
        return false;
    }
	
	if (wordDictSize == 1)
	{
		if (strstr(s,wordDict[0]) != NULL)
		{
			return true;
		}
		
		return false;
	}
	
	int allen = strlen(s);
	int *flagArray = (int *)malloc(sizeof(int)*allen);
	memset(flagArray,0,sizeof(int)*allen);
	
	int i = 0,j = 0;
	int sublen = 0,seglen = 0,templen = 0;
	char *p = NULL;
	p = s;
	while (strlen(p) > 0)
	{
		for (i = 0;i < wordDictSize;i++)//��������
		{
			if((p = strstr(p,wordDict[i])) != NULL)
			{
				sublen = strlen(p);
				templen = strlen(wordDict[i]);
				seglen = allen - sublen;
				
				for (j = 0; j < templen; j++)
				{
					if(flagArray[seglen + j] != 0)//�������������ص���
					{
						break;
					}
					else 
					{
						flagArray[seglen + j] = 1;
					}
				}
				
				p += strlen(wordDict[i]);
				
				if (strlen(p) < 1)
				{
					break;
				}
			}
		}
	}
	
	for (i = 0;i < allen;i++)//����
	{
		if (flagArray[i] == 0)
		{
			return false;
		}
	}
	
	return true;
}


int main()
{
	//char *s = "applepenapple";
	//char *wordDict[] = {"apple", "pen"};
	char *s = "leetcode";
	char *wordDict[] = {"leet","code"};
	int ret = wordBreak(s, wordDict, sizeof(wordDict)/sizeof(int*));
	
	printf("%s\r\n",(ret == 1)?"true":"false");
	return ret;
}
