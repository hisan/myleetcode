int DFS(int ***result,int *array_size,int *nums,const int numsSize,int *cur_ret,int *curnum,int *visited,int **returnColumnSizes)
{
	int i = 0;
	
	if (*curnum == numsSize)
	{
		*returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*array_size + 1));
		(*returnColumnSizes)[*array_size] = numsSize;
		
		*result = realloc(*result,sizeof(int *)*(*array_size + 1));
		(*result)[*array_size] = malloc(sizeof(int)*numsSize);
		memcpy((*result)[*array_size],cur_ret,sizeof(int)*numsSize);
		*array_size += 1;
		return;
	}
	
	for (i = 0; i < numsSize;i++)
	{
		if (visited[i] == 1)
		{
			continue;
		}
		
		visited[i] = 1;
		
		cur_ret[*curnum] = nums[i];
		*curnum += 1;
		DFS(result,array_size,nums,numsSize,cur_ret,curnum,visited,returnColumnSizes);
		*curnum -= 1;
		visited[i] = 0;//回溯关键
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int i = 0;
	int **result = NULL;
	int visited[1000] = {0};
	int array_size = 0;
	int cur_ret[10000] = {0};
	int cur_num = 0;
    int *col = NULL;
	
	DFS(&result,&array_size,nums,numsSize,cur_ret,&cur_num,visited,&col);
	*returnSize = array_size;
    *returnColumnSizes = col;
	
	return result;
}
