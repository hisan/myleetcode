/*
2020-08-21 02:36 终于通过了！！！
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getleftstring(char *tmp,char *dsttring,int len,char curchar,int pos)
{
	for (int i = 0;i < len;i++)
	{
		if (dsttring[i] == curchar && i == pos)
		{
			continue;
		}
		
		sprintf(tmp+strlen(tmp),"%c",dsttring[i]);
	}
}

void DFS(char *varstring,int varlen,int k,char ***retarray,int *ppnum,char *curstring)
{
	int used[128] = {0};//只过滤本层的重复字符串
	char tmpchar[10];
	
	for (int i = 0;i < varlen;i++)
	{
		if (used[(int)varstring[i]] == 1)
		{
			continue;//剪枝
		}
		
		memset(tmpchar,0,10);
		getleftstring(tmpchar,varstring,varlen,varstring[i],i);
		used[(int)varstring[i]] = 1;
		sprintf(curstring+strlen(curstring),"%c",varstring[i]);//尤为重要，这代表经过剪枝的分之一定是可行的，所以可以直接构造序列。
		
		if (strlen(curstring) == k)
		{
			*retarray = (char **)realloc(*retarray,sizeof(char *)*(*ppnum + 1));
			(*retarray)[*ppnum] = (char *)malloc(sizeof(char)*10);
			sprintf((*retarray)[*ppnum],"%s",curstring);
			*ppnum += 1;
			
			if (strlen(curstring) > 0)
			{//此处是当前层返回，则当前层的字母干掉
				curstring[strlen(curstring) -1] = '\0';//回溯
			}
			
			return;
		}
		else
		{
			DFS(tmpchar,varlen-1,k,retarray,ppnum,curstring);
			if (strlen(curstring) > 0)
			{
				curstring[strlen(curstring) -1] = '\0';//回溯
				
				/*
				这么干是因为：我们是深度有关联，广度无关联。每一个广度下是一轮深度，且某一深度的所有广度互不相关,
				所以若某一个广度的深度结束了，那么我们就要清除当前广度的痕迹，以便进入下一广度并进行该广度的深度遍历。这就体现回溯。
				*/
			}
		}
	}
}

char** permutation(char* S, int* returnSize)
{
	char **retarray = NULL;
	*returnSize = 0;
	char tmp[10] = {0};
    DFS(S,strlen(S),strlen(S),&retarray,returnSize,tmp);
	return retarray;
}

int main()
{	
	char *S = "qqe";
	int result = 0;
	char **res = NULL;
	res = permutation(S,&result);
	printf("%d\r\n",result);
	return 0;
}

/*
这题使用组合显然是不行的,因为它求的所有种可能，是排列问题，DFS如何求排列呢？
（1）求组合，联想多叉树的深度遍历，我们的每一次递归起点等于当前递归的起点的下一个点，
这样就能保证我们求的是组合，不会得到”不稳定的重复序列“。
（2）而求排列，我们只需要从进入递归的起点来入手就行了。
*/
