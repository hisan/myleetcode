/*
2020-03-15 ���� ��ʱ
(1)�Ѿ��кü������ǳ�ʱ������ˣ���ʱ��ѧһЩ������򵥵��㷨�ˡ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool 	int
#define false 	-1
#define true	 0

//���ڲ��ԵĴ�ӡ��ά����Ľӿ�
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
	for (int i = numsSize - 1;i <= curStep+1;i--)//����������Ĳ���ʼ��
	{
		if (pparray[curStep][i] == 1)
		{
			(*StepSize)++;
			temp = *StepSize;//�����Ǳ���ÿһ�ֿ��ܣ�����ÿһ�ֿ��ܶ�Ӧ��ָ�������������ı���
			if (*StepSize == numsSize - 1)//���ܹ�Ҫǰ��size-1������Ҫ���
			{
				return true;
			}
			else 
			{
				if (true == jump(pparray,i,&temp,numsSize))//��һ���ж�Ϊ��ȷ��ʱ�����Ƿǳ��б�Ҫ�ģ����Ǳ���������ά������Ϊ���ҵ�һ����ͷ��أ��������ж����е������
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
	
	//��������������·��(������Ϊ��i�ܷ�j)
	for (int i = 0;i < numsSize;i++)
	{
		for (int j = 0 ; j < numsSize;j++)
		{
			if (i >= j)
			{
				pparray[i][j] = -1;//��·
				continue;
			}
			
			if (j <= (i + nums[i]))//�жϵ�ǰԪ��������λ��ǰ���Լ��Ĳ���a[i]�Ƿ��ܵ���λ��j(>=j)
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