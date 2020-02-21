/*
*  2020-01-12 15:48
*  张云波
*  浙江-杭州
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//使用栈
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes)
{
	int cnt = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	int curstacktop = 0;
	int curstackbottlem = 0;

	curstacktop++;
	int statckValue, pointValue;
	int count = 0;

	for (count = 0; count < K; count++)
	{
		returnColumnSizes[count] = (int*)malloc(sizeof(int) * (*pointsColSize));
		memset(returnColumnSizes[count], 0, sizeof(int) * (*pointsColSize));
	}

	returnColumnSizes[0] = points[0];

	for (cnt = 1; cnt < pointsSize; cnt++)//处理数组
	{
		pointValue = pow(points[cnt][0], 2) + pow(points[cnt][1], 2);
		for (cnt1 = 0; cnt1 < curstacktop; cnt1++)
		{//遍历栈
			statckValue = pow(returnColumnSizes[cnt1][0], 2) + pow(returnColumnSizes[cnt1][1], 2);//栈中的变量
			if (pointValue > statckValue)//退栈
			{
				for (cnt2 = curstacktop; cnt2 > cnt1; cnt2--)
				{
					returnColumnSizes[cnt2] = returnColumnSizes[cnt2 - 1];
				}
				//挪开以后位置就是我们的了
				returnColumnSizes[cnt2] = points[cnt];//进栈
				curstacktop++;
				break;
			}
		}
		if (curstacktop < 10)
		{
			returnColumnSizes[curstacktop] = points[cnt];//进栈
			curstacktop++;
		}
	}

	*returnSize = K;
	return returnColumnSizes;
}

int main()
{
	int array1[10][2] = { {2,5},{1,4},{2,8},{3,9},{4,2},{7,9},{1,2},{2,4},{-6,7},{1,0} };
	int** array = (int**)malloc(sizeof(int*) * 10);
	int j = 0;
	int pointsColSize = 2;
	for (; j < 10; j++)
	{
		array[j] = (int*)malloc(sizeof(int)* 2);

		array[j][0] = array1[j][0];
		array[j][1] = array1[j][1];
	}

	int** returnColumnSizes = (int**)malloc(sizeof(int*) * 10);
	int retSize = 0;
	memset(returnColumnSizes,0,sizeof(int*)*10);

	kClosest(array, 10, &pointsColSize, 7, &retSize, returnColumnSizes);
	for (int i = 0; i < retSize; i++)
	{
		printf("returnColumnSizes[%d] : {%d,%d}\n", i, returnColumnSizes[i][0], returnColumnSizes[i][1]);
	}

	return 0;
}