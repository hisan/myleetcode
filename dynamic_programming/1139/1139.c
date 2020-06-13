//2020-06-13 22:46 ���� ͨ��
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

//��������grid���жϾ���grid�У���(istart,jstart)Ϊ�󶥵㣬��Ϊlength��δ֪�Ƿ��ȫΪ1���������жϸ������εı��Ƿ�ȫΪ1.
int judgesquare(int istart,int jstart,int length,int **grid)
{
	for (int i = 0;i < length;i++)//һ��ɨ���ж��ĸ��㣬�����������ε�������ɵ�����
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

//�ȱ�����һ��
int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
	int maxgrid = 0;
	int tmpgrid = 0;
	int start = 0;
	int res = 0;
	int colsize = *gridColSize;
	
	int maymaxlen = min(gridSize,colsize);//���ҳ����ܹ��ɵ���������εı߳�
	
	for (int i = 0;i < gridSize;i++)
	{
		for (int j = 0;j < colsize;j++)
		{
			tmpgrid = 0;//�������ÿ����Ϊ�����ε��󶥵�ʱ�ı߳���С������
			
			if (grid[i][j] == 0)//���󶥵��Ͳ���������ֱ�����������ж�
			{
				continue;
			}
			
			tmpgrid++;
			maxgrid = max(maxgrid,tmpgrid*tmpgrid);//�˶�����ϣ���ô���ٴ˶��㹹�ɵ��������ǺϷ��ģ������ȼ���һ������������
			for (int k = 1;k < maymaxlen;k++)//
			{
				if ((i+k) >= gridSize || (j+k) >= colsize)//���ⳬ��grid�ı߽�
				{
					break;
				}
				
				res  =judgesquare(i,j,k+1,grid);
				if (res == 0)
				{
					tmpgrid++;
					continue;//Ϊʲô��continue?��Ϊ����ǰ���󶥵�ĵ����0��ֻ��˵������������Ϊһ�������εıߣ������������Ǳ�һ��"�ϸ񡰵������εİ�Χ���ڡ�
				}
				else
				{
					tmpgrid++;
					maxgrid = max(maxgrid,tmpgrid*tmpgrid);//�������������ΰ�����Ԫ����
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








