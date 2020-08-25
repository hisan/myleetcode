/*
*2020-08-25 浙江杭州
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//这道题通过排序，使得题目简单了，需要思考的去重，没有真正被考虑，我个人觉得是一种规避而不是解决方式。
void bublesort(int *a,int size)
{
	for (int i = 0 ; i < size;i++)
	{
		for (int j = i+1;j < size;j++)
		{
			if (a[i] > a[j])
			{
				a[i] ^= a[j];
				a[j] ^= a[i];
				a[i] ^= a[j];
			}
		}
	}
}

void DFS(int* candidates, int candidatesSize, int target, int* returnSize, int* returnColumnSizes,
															int **retarray,int tmpvar,int *curnum,int curpos,int *used1,int start)
{
    for (int i = start; i < candidatesSize;i++)
    {
		if (used1[i] == 1)
		{
			continue;
		}

        if (i > start && candidates[i] == candidates[i-1])//像[2,2,...]这种，对第一个2进行DFS和对第二个2进行DFS，结果一定是一样的，那么第二个2跳过即可。
        {
            continue;
        }

        used1[i] = 1;

        tmpvar += candidates[i];
		curnum[curpos] = candidates[i];
		
        if (tmpvar == target)//满足条件(剪枝)
        {
            retarray[*returnSize] = (int *)malloc(sizeof(int)*(curpos + 1));
            for (int j = 0 ; j <= curpos;j++)
            {
                retarray[*returnSize][j] = curnum[j]; 
            }
			
			returnColumnSizes[*returnSize] = curpos + 1;
			*returnSize += 1;
			tmpvar -= candidates[i];//回溯
			used1[i] = 0;//回溯
            continue;
        }
        else if (tmpvar > target)//已经没有必要再进行下去(剪枝)
        {
			tmpvar -= candidates[i];//回溯
            used1[i] = 0;//回溯
			continue;
        }
		
        DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes,retarray,tmpvar,curnum,curpos + 1,used1,i+1);
		used1[i] = 0;//回溯
		tmpvar -= candidates[i];//回溯
    }
	
    return;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
	int tmp = 0;
	int curnum[1024] = {0};
    int curpos = 0;
    int used[1024] = {0};
	
	int **retarray = (int **)calloc(1024,sizeof(int *));
	*returnColumnSizes = (int *)calloc(1024,sizeof(int *));
	*returnSize = 0;
	
	bublesort(candidates,candidatesSize);
	
	DFS(candidates, candidatesSize, target, returnSize, *returnColumnSizes,retarray,tmp,curnum,curpos,used,0);
    return retarray;
}

int main()
{
	int candidates[] = {3,1,3,5,1,1};
	int candidatesSize = sizeof(candidates)/sizeof(candidates[0]);
	int target = 8;
	int returnSize = 0; 
	
	int* returnColumnSizes = NULL;
	int **ret = NULL;
	ret = combinationSum2(candidates,candidatesSize,target,&returnSize,&returnColumnSizes);
	
	printf("result:\r\n");
	for (int i = 0; i < returnSize;i++)
	{
		for (int j = 0 ; j < returnColumnSizes[i];j++)
		{
			printf("%d ",ret[i][j]);
		}
		printf("\r\n");
		
	} 
	
	return 0;
}


