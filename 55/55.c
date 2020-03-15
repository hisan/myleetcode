/*
2020-03-15 杭州 超时
(1)已经有好几个题是超时的情况了，是时候学一些解题更简单的算法了。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool 	int
#define false 	-1
#define true	 0

//用于测试的打印二维数组的接口
void printf_int(int **a,int size)
{
	int i,j;
	for (i = 0 ;i < size;i++)
	{
		for (j = 0 ;j < size;j++)
		{
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
}

bool jump(int **pparray,int curStep,int *StepSize,const int numsSize)
{
	int temp = 0;
	//for (int i = curStep+1;i < numsSize;i++)
	for (int i = numsSize - 1;i <= curStep+1;i--)//从最大能跳的步开始算
	{
		if (pparray[curStep][i] == 1)
		{
			(*StepSize)++;
			temp = *StepSize;//我们是遍历每一种可能，所以每一种可能都应有指明它能跳几步的变量
			if (*StepSize == numsSize - 1)//是总共要前进size-1步，不要搞错
			{
				return true;
			}
			else 
			{
				if (true == jump(pparray,i,&temp,numsSize))//这一步判断为正确及时返回是非常有必要的，我们遍历整个二维数组是为了找到一个解就返回，而不是判断所有的情况。
				{
					return true;
				}
			}
		}
	}
	
	return false;
}

bool canJump(int* nums, int numsSize)
{	
	int StepSize = 0;
	int **pparray = (int **)malloc(sizeof(int *)*numsSize);

	if (pparray == NULL)
	{
		return false;
	}
	
	for (int i = 0; i < numsSize;i++)
	{
		pparray[i] = (int *)malloc(sizeof(int)*numsSize);
		if (pparray[i] == NULL)
		{
			return false;
		}
		memset(pparray[i],0,sizeof(int)*numsSize);
	}
	
	//构建符合条件的路线(条件即为：i能否到j)
	for (int i = 0;i < numsSize;i++)
	{
		for (int j = 0 ; j < numsSize;j++)
		{
			if (i >= j)
			{
				pparray[i][j] = -1;//封路
				continue;
			}
			
			if (j <= (i + nums[i]))//判断当前元素所处的位置前进自己的步数a[i]是否能到达位置j(>=j)
			{
				pparray[i][j] = 1;
			}
		}
	}
	
	printf_int(pparray,numsSize);
	return jump(pparray,0,&StepSize,numsSize);
}

int main()
{
	//int a[] = {3,2,1,0,4};
	//int a[] = {2,3,1,1,4};
	//int a[] = {2,0,0};
	int a[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,\
					1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,\
						4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,\
							4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,\
								2,8,2,6,8,2,2,7,5,1,7,9,6};
								
	int size = sizeof(a)/sizeof(int);
	bool ret = canJump(a,size);
	if (ret == false)
	{
		printf("%s\n","false");
	}
	else 
	{
		printf("%s\n","true");
	}
	
	return 0;
}