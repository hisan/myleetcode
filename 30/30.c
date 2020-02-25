//2020-02-24 20:30 超时
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  NOT_MATCH  0
#define  YES_MATCH  1

#define USE_NOT    0
#define USE_YES    1

int matchWords(int *flagArray,char	*MasterString,char **words,int wordsSize,int *returnSize,int *times)
{
	int i = 0;
	char *pMaster = MasterString;
	char *pSub = NULL;
	
	for (i = 0 ; i < wordsSize;i++)
	{
		if (flagArray[i] == USE_YES)
		{
			continue;
		}
		
		if (NULL != (pSub = strstr(MasterString,words[i])))
		{
			if (pSub == pMaster)//比较地址
			{
				flagArray[i] = USE_YES;
				pMaster += strlen(words[i]);
				(*times) += 1;
				
				if ((*times) == wordsSize)//完全匹配
				{
					(*returnSize) += 1;
					return YES_MATCH;
				}
				else 
				{
					return matchWords(flagArray,pMaster,words,wordsSize,returnSize,times);
				}
			}
		}
		else 
		{
			return NOT_MATCH;
		}
	}
	
	return NOT_MATCH;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{    
	char *pstr = NULL;
    int  i = 0,j = 0,l = 0;
	int sublen = 0;
	int *usedflag = NULL;
	int *retArray = NULL;
	int retSize = 0;
	int match_size = 0;
	int match_times = 0;
	char *ptmp = NULL;
	
	int index = 0;
	int alreay = 0;
	int len = 0;

    int masterlen = strlen(s);
	
	*returnSize = 0;
	
	if (wordsSize == 1)
	{
		if (0 == strcmp(s,words[0]))
		{
			retArray = realloc(retArray,sizeof(int)*(match_size+1));
			retArray[match_size] = 0;
			(*returnSize) += 1;
		}
		else 
		{
			pstr = strstr(s,words[0]);
			while (pstr != NULL)
			{
				index = masterlen - strlen(pstr);
				retArray = realloc(retArray,sizeof(int)*(match_size+1));
				retArray[match_size] = index;
				match_size++;
				(*returnSize) += 1;
				pstr++;
				pstr = strstr(pstr,words[0]);
			}
		}
		return retArray;
	}
	
	usedflag = (int *)malloc(sizeof(int)*wordsSize);
	if (usedflag == NULL)
	{
		return NULL;
	}

	for (i = 0; i < wordsSize;i++)
	{//得到子串长度
		sublen += strlen(words[i]);
	}
	
	len = strlen(s) - sublen + 1;
	
	//匹配策略：分别以每个单词作为组合后的子串的开头去进行匹配。
	for (i = 0;i < wordsSize;i++)
	{
		masterlen = strlen(s);
		pstr = s;
		while ( (pstr = strstr(pstr,words[i])) != NULL && strlen(pstr) >= sublen )//在当前单词能够匹配到主串中的一部分时，则要保证主串s中以当前单词开头至尾部的长度要大于等于所有单词的长度之和(待匹配词组构成的子串的长度之和)。
		{
			memset(usedflag,USE_NOT,sizeof(int)*wordsSize);
			match_times = 0;
			usedflag[i] = USE_YES;
			match_times += 1;
			
			ptmp = pstr;
			ptmp += strlen(words[i]);
			if (NOT_MATCH == matchWords(usedflag,ptmp,words,wordsSize,&retSize,&match_times))
			{
				pstr += 1;
				continue;
			}
			else 
			{
				index = masterlen - strlen(pstr);
				alreay = 0;
				for (j = 0;j < match_size;j++)
				{
					if (retArray[j] == index)
					{
						alreay = 1;
						break;
					}
				}
				
				if (alreay != 1)
				{
					retArray = realloc(retArray,sizeof(int)*(match_size+1));
					retArray[match_size] = index;
					match_size++;
				}
				else
				{
					retSize -= 1;
				}
				pstr += 1;
			}
		}
	}
	
	*returnSize = retSize;
	return retArray;
}


int main()
{
	//char *s = "wordgoodgoodgoodbestword";	
	//char *words[] = {"word","good","best","word"};
	char *s = "barfoothefoobarman";
	char *words[] = {"foo","bar"};
	
	int wordsSize = sizeof(words)/sizeof(char *);
	int retSize = 0;
	int i = 0;
	int *ret = findSubstring(s, words, wordsSize, &retSize);
	if (retSize <= 0)
	{
		printf("no match!\r\n");
		return 0;
	}
	
	for (i = 0; i < retSize-1;i++)
	{
		printf("%d,",ret[i]);
	}
	
	printf("%d\r\n",ret[retSize - 1]);
	return 0;
}




