//2020-08-23 14:16 超时
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define  NOT_MATCH  0
#define  YES_MATCH  1

int matchleftwords(char *curstart,char ** words, int wordsSize,int *used,int *count,char *S,int *savepos)
{
    char *nextstart = NULL;
    
    if (*count == wordsSize)
    {//已构成
        return YES_MATCH;
    }

    for (int i = 0 ; i < wordsSize;i++)
    {
        if (used[i] == 1)
        {
            continue;
        }

        if (NULL == (nextstart = strstr(curstart,words[i])))
        {
            continue;
        }

        if (nextstart != curstart)//当前字符不紧挨着，则跳到下一个字符串继续比对
        {
            continue;
        }

        used[i] = 1;
		*count += 1;
		
        curstart += strlen(words[i]);
        //只要匹配了就返回，不需要得到所有符合条件的情况。
        if ( YES_MATCH == matchleftwords(curstart,words,wordsSize,used,count,S,savepos))
        {
            return YES_MATCH;
        }
    }
	
    return NOT_MATCH;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){

    int *used = (int*)malloc(sizeof(int)*wordsSize);
    int *savepos = NULL;
	int count = 0;
    char *curstart = NULL;
    char *nextstart = NULL;
	*returnSize = 0;
	
	int len = strlen(s);
	int sublen = 0;
	
	for (int i = 0 ; i < wordsSize;i++)
	{
		sublen += strlen(words[i]);
	}
	
	len -= sublen;
	
	for (int j = 0; j <=len;j++)
	{
		for (int i = 0 ; i < wordsSize;i++)
		{
			nextstart = NULL;
			curstart = s + j;
			count = 0;
			
			memset(used,0,sizeof(int)*wordsSize);//只保存本次深度优先遍历的状态，开始下一次深度之前要清除上一次的状态
			
			if ((nextstart = strstr(curstart,words[i])) == NULL)//当前子单词不可能组成字符串
			{
				continue;
			}
			
			curstart = nextstart + strlen(words[i]);
			used[i] = 1;
			count += 1;
			
			if ( YES_MATCH == matchleftwords(curstart,words,wordsSize,used,&count,s,savepos))
			{
				int tmplen = strlen(s) - strlen(nextstart);
				int already = 0;
				
				for (int k = 0 ; k < *returnSize;k++)
				{
					if (savepos[k] == tmplen)
					{
						already = 1;
						break;
					}
				}
				
				if (already == 1)
				{
					continue;
				}
			
				savepos = realloc(savepos,sizeof(int)*(*returnSize + 1));
				savepos[*returnSize] = strlen(s) - strlen(nextstart);
				*returnSize += 1;
			}
		}
	}
	
    return savepos;
}

int main()
{
	#if 0
	char *s = "wordgoodgoodgoodbestword";	
	char *words[] = {"word","good","best","word"};
	#endif 
	
	#if 0
	char *s = "barfoobarthefoobarman";
	char *words[] = {"foo","bar"};
	#endif 
	
	#if 0
	char *s = "aabbaabbaabb";
	char *words = {"bb","aa","bb","aa","bb"};
	#endif 
	
	char *s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
	char *words[] = {"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"};
	
	
	int wordsSize = sizeof(words)/sizeof(char *);
	int retSize = 0;
	int i = 0;
	
	printf("before:%d\r\n",time(NULL));
	int *ret = findSubstring(s, words, wordsSize, &retSize);
	printf("after:%d\r\n",time(NULL));
	
	if (ret == NULL || retSize <= 0 )
	{
		printf("no match!\r\n");
		return NOT_MATCH;
	}
	
	for (i = 0; i < retSize-1;i++)
	{
		printf("%d,",ret[i]);
	}
	
	printf("%d\r\n",ret[retSize - 1]);
	
	return YES_MATCH;
}

