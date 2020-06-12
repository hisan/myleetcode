//2020-06-11 22:54 ����

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

//�ȱ�����һ��
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
			for (int k = 1;k < gridSize-i;K++)//�ӶԽ�������
			{
				if (grid[i][j] == 0)
				{
					break;
				}
				
				tmpgrid = 1;
				
				//�ж϶Խ��Ƿ����չ���ԵĻ���ȥ�ж϶Խ����γɵ��ı����Ƿ���������
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




