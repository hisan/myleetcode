#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  dfs(char *S,char **res,char *curstr,int traend,int start,int *traverpos,int *bitmap,int *returnSize)
{
    if (traend == *traverpos)
    {
        res[*returnSize] = malloc(sizeof(char)*traend);
        memcpy(res[*returnSize],curstr,sizeof(char)*traend);
        *returnSize += 1;
        return;
    }

    for (int i = start ; i <= traend;i++)
    {
	if (bitmap[i-1] == 1)
	{
		continue;
	}

        curstr[*traverpos] = S[i-1];
        *traverpos += 1;
	
	bitmap[i-1] = 1;        
	dfs(S,res,curstr,traend,i+1,traverpos,bitmap,returnSize);
        
	*traverpos -= 1;
	bitmap[i-1] = 0;
    }
}


char** permutation(char* S, int* returnSize){
    
    char **res = malloc(sizeof(char *)*(10000));
    
    int traverpos = 0;
    int traend = strlen(S);
    
    char *curstr = malloc(sizeof(char)*traend);
    memset(curstr,0,sizeof(char)*traend);
    
    int bitmap[10000] = {0};
    dfs(S,res,curstr,traend,1,&traverpos,bitmap,returnSize);
    
    return res;
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
