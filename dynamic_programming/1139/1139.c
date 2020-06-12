//2020-06-11 22:54 杭州

int judgesquare(int is,int js,int length,int int **grid)
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
		
		if (grid[is+length][i+js] != 1)
		{
			return 0;
		}
		
		if (grid[i+is][js+length] != 1)
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
	
	for (int i = 0;i < gridSize;i++)
	{
		for (int j = 0;j < gridSize;j++)
		{
			for (int k = 1;k < gridSize-i;K++)//从对角线入手
			{
				if (grid[i][j] == 0)
				{
					break;
				}
				
				tmpgrid = 1;
				
				//判断对角是否可扩展可以的话再去判断对角线形成的四边形是否满足条件
				if (grid[i+k][j+K] == 0)
				{
					break;
				}
				else
				{
					res  =judgesquare(i,j,2,grid);
					if (res == 0)
					{
						break;
					}
					else 
					{
						tmpgrid++;
						maxgrid = max(maxgrid,tmpgrid*tmpgrid);
						if (tmpgrid == gridSize)
						{
							return maxgrid;
						}
					}
				}
			}
		}
	}
	
	return maxgrid;
}




