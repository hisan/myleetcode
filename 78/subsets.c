#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common_use/PRINT_ARRAY/include/print_array.h"

void DFS(int *nums,int numsSize,int *visited,int *returnSize,int **returnColumnSizes,int ***ret_array,int *cur_ret_set,int *cur_size)
{
	int newvisited[10] = {0};//这个数组的必要性
    int i = 0;
	int j = 0;
 	if (*cur_size > 0)
    {
        (*ret_array) = realloc((*ret_array),sizeof(int *)*(*returnSize+1));
        (*ret_array)[*returnSize] = (int *)malloc(sizeof(int)*(*cur_size));
		
        for (i = 0 ;i < *cur_size;i++)
        {
            (*ret_array)[*returnSize][i] = cur_ret_set[i];
        }
        
        (*returnColumnSizes) = realloc((*returnColumnSizes),sizeof(int)*(*returnSize+1));
        (*returnColumnSizes)[*returnSize] = *cur_size;
                                                                                         
        (*returnSize) += 1;
    }
    
    for (i = 0;i < numsSize;i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }
		
        cur_ret_set[*cur_size] = nums[i];
        (*cur_size) += 1;
        visited[i] = 1;
        
        for (j=0;j<= i;j++)
		{
			newvisited[j] = 1;
		}

        DFS(nums,numsSize,newvisited,returnSize,returnColumnSizes,ret_array,cur_ret_set,cur_size);
        (*cur_size) -= 1;
		visited[i] = 0;
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){	
    int visited[10] = {0};
    int cur_num_set[10] = {0};
    int cur_set_size = 0;
    int *ret_col_size = NULL;
    int** ret_array = NULL;
    
    *returnSize = 0;
    ret_array = (int **)malloc(sizeof(int* )*(*returnSize+1));
    ret_array[*returnSize] = (int *)malloc(sizeof(int));
    
    ret_col_size = realloc(ret_col_size,sizeof(int)*(*returnSize+1));
    ret_col_size[*returnSize] = 0;//第一个子集中的元素个数为0
	
    (*returnSize)++;//子集元素+1
	
	DFS(nums,numsSize,&visited[0],returnSize,&ret_col_size,&ret_array,cur_num_set,&cur_set_size);
	*returnColumnSizes = ret_col_size;
	
    return ret_array;
}


int main()
{
	int nums[] = {1,2,3};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int**res = NULL;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	
	res = subsets(nums,numsSize, &returnSize,&returnColumnSizes);
	
	print_twodim_array(res,returnSize,returnColumnSizes);

	return 0;
}


