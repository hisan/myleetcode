//2020-06-12 23:58 杭州

#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
	return a<b?b:a;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int judgesquare(int is,int js,int length,int **grid)
{
	for (int i = 0;i < length;i++)
	{
		if (grid[i+is][js] != 1)
		{
			return 0;
		}
		
		if (grid[is][i+js] != 1)
		{
			return 0;
		}
		
		if (grid[is+length-1][i+js] != 1)
		{
			return 0;
		}
		
		if (grid[i+is][js+length-1] != 1)
		{
			return 0;
		}
	}
	
	return 1;
}

int set(int a,int b)
{
	if (abs(a-b) <= 1)
	{
		return 1;
	}
	
	return max(a,b);
}

//先暴力解一下
int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
	int maxgrid = 0;
	int tmpgrid = 0;
	int start = 0;
	int res = 0;
	int colsize = *gridColSize;
	
	int little = min(gridSize,colsize);
	
	for (int i = 0;i < gridSize;i++)
	{
		for (int j = 0;j < colsize;j++)
		{
			tmpgrid = 0;
			
			if (grid[i][j] == 0)
			{
				continue;
			}
			
			tmpgrid++;
			maxgrid = max(maxgrid,tmpgrid*tmpgrid);
			for (int k = 1;k < little - set(i,j) + 1;k++)//从对角线入手
			{
				//判断对角是否可扩展可以的话再去判断对角线形成的四边形是否满足条件
				if (grid[i+k][j+k] == 0)
				{
					tmpgrid++;
					continue;
				}
				else
				{
					res  =judgesquare(i,j,k+1,grid);
					if (res == 0)
					{
						break;
					}
					else 
					{
						tmpgrid++;
						maxgrid = max(maxgrid,tmpgrid*tmpgrid);
					}
				}
			}
		}
	}
	
	return maxgrid;
}

int main()
{
	int **grid = NULL;					//[][] = {{1,1,1},{1,0,1},{1,1,1}};
	int gridSize = 3;
	
	grid = malloc(sizeof(int *)*gridSize);
	for (int i = 0 ; i < gridSize;i++)
	{
		grid[i] = malloc(sizeof(int)*gridSize);
	}
	
	grid[0][0] = 1;
	grid[0][1] = 1;
	grid[0][2] = 1;
	
	grid[1][0] = 1;
	grid[1][1] = 1;
	grid[1][2] = 1;
	
	grid[2][0] = 1;
	grid[2][1] = 0;
	grid[2][2] = 1;
	
	int ret = 0;
	ret = largest1BorderedSquare(grid,gridSize,&gridSize);
	
	printf("%d\r\n",ret);
	
}










