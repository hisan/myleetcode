//2020-04-06 16:16 浙江杭州
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdbool.h>

/*
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//未通过
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
	int total = 0 ;
	int **array = NULL;
	int maxnum = pow(numCourses,2);
	*prerequisitesColSize = 0;
	
	if (prerequisitesSize > 1 + (maxnum/2) )
	{//不可能大于一半的路径
		return false;
	}

	array = (int **)malloc(sizeof(int*)*numCourses);
	if (array == NULL)
	{
		return false;
	}

	memset(array,0,sizeof(int *)*numCourses);

	for (int i = 0 ;i < numCourses;i++)
	{
		array[i] = (int *)malloc(sizeof(int)*numCourses);
		memset(array[i],0,sizeof(int)*numCourses);
	}

	//初始化
	for (int i = 0 ;i < prerequisitesSize;i++)
	{
		if (array[(prerequisites[i][0]-1)][(prerequisites[i][1]-1)] == 1)
		{//课程重复？？？
			return false;
		}

		array[(prerequisites[i][0]-1)][(prerequisites[i][1]-1)] = 1;
		
		if (array[(prerequisites[i][0]-1)][(prerequisites[i][1]-1)] == 1 &&
						 array[(prerequisites[i][1]-1)][(prerequisites[i][0]-1)]== 1)
		{//排除互相依赖的课程(即不合法的课程)
			return false;
		}
	}

	for (int i = 0 ;i < numCourses;i++)
	{
		for (int j = 0;j < numCourses;j++)
		{
			if (array[i][j] == 1)
			{
				total+=2;
			}
		}
	}

	if (total != numCourses)
	{
		return false;
	}

	*prerequisitesColSize = 2;
	return true;
}


int main()
{
	int numCourses = 2;
	int prerequisitesSize = 1;
	int rerequisitesColSize = 2;
	int **prerequisites = NULL;

	prerequisites = (int **)malloc(sizeof(int *)*prerequisitesSize);
	for (int i = 0; i < prerequisitesSize; i++)
	{
		 prerequisites[i] =(int*)malloc(sizeof(int)*rerequisitesColSize);
		 memset(prerequisites[i],0,sizeof(int)*rerequisitesColSize);
	}

	prerequisites[0][0] = 2;
	prerequisites[0][1] = 1;	
	
	bool ret = canFinish(numCourses, prerequisites, prerequisitesSize, &rerequisitesColSize);
	printf("%s\n",(ret == false)?"no":"yes");
	
	return 0;
}