#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
	*returnSize = 0;
    if (matrix == NULL || matrixSize <= 0 || matrixColSize == NULL)
    {
        return NULL;
    }
	
    int up = 0;
    int down = matrixSize-1;
    int left = 0;
    int right = *matrixColSize -1;
	
    int *res = NULL;
    int count = 0;
    const int num = matrixSize*(*matrixColSize);
    
    if (num <= 0)
    {
        return res;
    }

    res = (int *)malloc(sizeof(int)*num);
    memset(res,0,sizeof(int)*num);

    while (count < num)
    {
        for (int i = left;i <= right;i++)
        {
            res[count++] = matrix[up][i];
        }
        up++;
        if (up > down)
        {
            break;
        }

        for (int j = up;j <= down;j++)
        {
            res[count++] = matrix[j][right];
        }
        right--;
        if (right < left)
        {
            break;
        }

        for (int j = right;j >= left;j--)
        {
            res[count++] = matrix[down][j];
        }
        down--;
        if (down < up)
        {
            break;
        }

        for (int j = down;j >= up;j--)
        {
            res[count++] = matrix[j][left];
        }
        left++;
        if (left > right)
        {
            break;
        }
    }

    *returnSize = count;
    return res;
}


void print_arrary(int *g,int size)
{
	printf("\n\n");
	int i = 0;
	for ( i = 0 ; i < size-1;i++)
	{
		printf("%d ",g[i]);
	}
	
	printf("%d\n\n",g[i]);
}

void free_2_arrary(int **g,int size)
{
    int  i = 0;
    for (i = 0;i < size;i++)
    {
        if (g[i])
        {
            free(g[i]);
            g[i] = NULL;    
        }
    }

    if (g)
    {
        free(g);
        g = NULL;
    }
}

int main()
{
	int** matrix = NULL;
	int matrixSize = 0;
	int matrixColSize = 0;
	int returnSize = 0;
	char input_buffer[200] = {0};
	
	while ((EOF != scanf("%d",&matrixSize)) && (EOF != scanf("%d",&matrixColSize)))
	{
		if (matrix == NULL)
		{
			matrix = (int **)malloc(sizeof(int *)*matrixSize);
			for (int i = 0; i < matrixSize;i++)
			{
				matrix[i] = (int *)malloc(sizeof(int)*matrixColSize);
			}
		}
		
		printf("please input the matrix content:\n\n");
		for (int i = 0; i < matrixSize;i++)
		{
			memset(matrix[i],0,sizeof(int)*matrixColSize);
			
			for (int j = 0; j < matrixColSize;j++)
			{
				scanf("%d",&matrix[i][j]);
			}
		}
		
		int* res = spiralOrder(matrix,matrixSize, &matrixColSize, &returnSize);
		print_arrary(res,returnSize);
		free(res);
		
		free_2_arrary(matrix,matrixSize);
		matrix = NULL;
		
		printf("returnSize: %d",returnSize);
	}
	


	
}






















