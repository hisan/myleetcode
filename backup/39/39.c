#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0 
//提交有问题
void DFS(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes,
															int ***retarray,int tmpvar,int *curnum,int curpos,int start)
{
    for (int i = start ; i < candidatesSize;i++)
    {
        tmpvar += candidates[i];
		curnum[curpos] = candidates[i];
		
        if (tmpvar == target)//满足条件(剪枝)
        {
            (*retarray) = realloc(*retarray,sizeof(int *)*(*returnSize + 1));
            (*retarray)[*returnSize] = realloc((*retarray)[*returnSize],sizeof(int)*(curpos + 1));

            for (int j = 0 ; j <= curpos;j++)
            {
                (*retarray)[*returnSize][j] = curnum[j]; 
            }

            //返回列个数数组
            *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize + 1));
			(*returnColumnSizes)[*returnSize] = curpos + 1;
			
			*returnSize += 1;
			tmpvar -= candidates[i];//回溯
			continue;
        }
        else if (tmpvar > target)//已经没有必要再进行下去(剪枝)
        {
			#if 0
			printf("-----------num:%d------------------\r\n",num++);
			for (int j = 0 ; j <= curpos;j++)
            {
                printf("%d ",curnum[j]);
            }
			printf("\r\n");
			#endif 
			
			tmpvar -= candidates[i];//回溯
			continue;
        }
		
        DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes,retarray,tmpvar,curnum,curpos + 1,i);
		tmpvar -= candidates[i];//回溯
    }
	
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int tmp = 0;
    
	int curnum[30] = {0};
    int curpos = 0;
	
    int **retarray = NULL;
    *returnSize = 0;
	int *retcolsize = NULL;
	int start = 0;
    DFS(candidates, candidatesSize, target, returnSize, &retcolsize,&retarray,tmp,curnum,curpos,start);

	*returnColumnSizes = retcolsize;
	
    return retarray;
}


int main()
{
	int candidates[] = {2,3,1,5,12,43,12,23,12,234};
	int candidatesSize = sizeof(candidates)/sizeof(candidates[0]);
	
	int target = 68;
	int returnSize = 0; 
	
	int* returnColumnSizes = NULL;
	int **ret = NULL;
	ret = combinationSum(candidates,candidatesSize,target,&returnSize,&returnColumnSizes);
	
	printf("result:\r\n\r\n");
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

#else

void DFS(int* candidates, int candidatesSize, int target, int* returnSize, int* returnColumnSizes,
															int **retarray,int tmpvar,int *curnum,int curpos,int start)
{
    for (int i = start ; i < candidatesSize;i++)
    {
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
			continue;
        }
        else if (tmpvar > target)//已经没有必要再进行下去(剪枝)
        {
			#if 0
			printf("-----------num:%d------------------\r\n",num++);
			for (int j = 0 ; j <= curpos;j++)
            {
                printf("%d ",curnum[j]);
            }
			printf("\r\n");
			#endif 
			
			tmpvar -= candidates[i];//回溯
			continue;
        }
		
        DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes,retarray,tmpvar,curnum,curpos + 1,i);
		tmpvar -= candidates[i];//回溯
    }
	
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
	int tmp = 0;
	int curnum[1024] = {0};
    int curpos = 0;
    
	int **retarray = (int **)calloc(1024,sizeof(int *));
	*returnColumnSizes = (int *)calloc(1024,sizeof(int *));
    
	*returnSize = 0;
	int start = 0;
	
	DFS(candidates, candidatesSize, target, returnSize, *returnColumnSizes,retarray,tmp,curnum,curpos,start);
    return retarray;
}

int main()
{
	int candidates[] = {5,12,43,23,32,14};
	int candidatesSize = sizeof(candidates)/sizeof(candidates[0]);
	
	int target = 68;
	int returnSize = 0; 
	
	int* returnColumnSizes = NULL;
	int **ret = NULL;
	ret = combinationSum(candidates,candidatesSize,target,&returnSize,&returnColumnSizes);
	
	printf("result:\r\n\r\n");
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
	
#endif 
