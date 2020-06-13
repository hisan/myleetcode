//2020-06-13 22:46 杭州 通过
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

//给定矩形grid，判断矩形grid中，以(istart,jstart)为左顶点，宽为length的未知是否边全为1的正方，判断该正方形的边是否全为1.
int judgesquare(int istart,int jstart,int length,int **grid)
{
	for (int i = 0;i < length;i++)//一趟扫描判断四个点，这是由正方形的坐标规律的来的
	{
		if (grid[i+istart][jstart] != 1)
		{
			return 0;
		}
		
		if (grid[istart][i+jstart] != 1)
		{
			return 0;
		}
		
		if (grid[istart+length-1][i+jstart] != 1)
		{
			return 0;
		}
		
		if (grid[i+istart][jstart+length-1] != 1)
		{
			return 0;
		}
	}
	
	return 1;
}

//先暴力解一下
int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
	int maxgrid = 0;
	int tmpgrid = 0;
	int start = 0;
	int res = 0;
	int colsize = *gridColSize;
	
	int maymaxlen = min(gridSize,colsize);//先找出可能构成的最大正方形的边长
	
	for (int i = 0;i < gridSize;i++)
	{
		for (int j = 0;j < colsize;j++)
		{
			tmpgrid = 0;//逐个处理每个点为正方形的左顶点时的边长大小的增长
			
			if (grid[i][j] == 0)//该左顶点点就不符合条件直接跳出本次判断
			{
				continue;
			}
			
			tmpgrid++;
			maxgrid = max(maxgrid,tmpgrid*tmpgrid);//此顶点符合，那么最少此顶点构成的正方形是合法的，所以先计算一次最大的正方形
			for (int k = 1;k < maymaxlen;k++)//
			{
				if ((i+k) >= gridSize || (j+k) >= colsize)//避免超过grid的边界
				{
					break;
				}
				
				res  =judgesquare(i,j,k+1,grid);
				if (res == 0)
				{
					tmpgrid++;
					continue;//为什么是continue?因为，当前非左顶点的点等于0，只能说明不可能以它为一个正方形的边，但是它可能是被一个"合格“的正方形的包围在内。
				}
				else
				{
					tmpgrid++;
					maxgrid = max(maxgrid,tmpgrid*tmpgrid);//更新最大的正方形包含的元素数
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
	int colsize = 5;
	grid = malloc(sizeof(int *)*gridSize);
	for (int i = 0 ; i < gridSize;i++)
	{
		grid[i] = malloc(sizeof(int)*colsize);
	}
	
	grid[0][0] = 1;
	grid[0][1] = 1;
	grid[0][2] = 1;
	grid[0][3] = 1;
	grid[0][4] = 1;
	
	grid[1][0] = 1;
	grid[1][1] = 1;
	grid[1][2] = 1;
	grid[1][3] = 1;
	grid[1][4] = 1;
	
	grid[2][0] = 1;
	grid[2][1] = 0;
	grid[2][2] = 1;
	grid[2][3] = 1;
	grid[2][4] = 1;
	
	int ret = 0;
	ret = largest1BorderedSquare(grid,gridSize,&colsize);
	
	printf("%d\r\n",ret);
}








