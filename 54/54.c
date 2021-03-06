int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    
	int size = matrixSize*(*matrixColSize);

	int *ret = (int *)malloc(sizeof(int)*size);
	memset(ret,0,sizeof(int)*size);
	
    int i = 0;
	int up = 0;
	int down = matrixSize - 1;
	int left = 0;
	int right = *matrixColSize - 1;

	*returnSize = 0;
	
	while (1)
	{
		//	---->
		for (i = left;i <= right;i++)
		{
			ret[*returnSize] = matrix[up][i];
			*returnSize += 1;
		}
		
		up += 1;
		if (up > down) 
		{
			break;
		}
		
		//	\|/
		for (i = up;i<= down;i++)
		{
			ret[*returnSize] = matrix[i][right];
			*returnSize += 1;
		}
		
		right -= 1;
		if (left > right)
		{
			break;
		}
		
		//	<----
		for (i=right;i>=left;i--)
		{
			ret[*returnSize] = matrix[down][i];
			*returnSize += 1;
		}
		down -=1;
		if (up > down)
		{
			break;
		}
		
		//	/|\
		
		for (i=down;i>=up;i--)
		{
			ret[*returnSize] = matrix[i][left];
			*returnSize += 1;
		}
		
		left += 1;
		if (left > right)
		{
			break;
		}
	}
	
	return ret;
}
