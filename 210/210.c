#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
//大家的实现都是维护一个队列，将入度为0的结点都入队,最后从队头元素开始，将它出队,同时，将它指向的元素的入度都-1，且若此结点的入读为0再入队,直至队中元素全部出队。此时，再判断是否所有结点都被遍历过，若没有，则说明不符合拓扑排序。既任务不能顺序完成。

typedef struct st_Queue
{
	int array[2000];
	int head;
	int tail;
	int size;
}Queue;

#if 0
使用队列，动态地维护了结点的出入队动作代表的遍历与否。
#endif

void enqueue(Queue *queue,int val)
{
	queue->array[queue->tail] = val;
	queue->tail += 1;
	queue->size += 1;
}

int dequeue(Queue *queue)
{
	int tmp = queue->array[queue->head];
	queue->head += 1;
	queue->size -= 1;
	return tmp;
}

void que_init(Queue *queue)
{
	memset(queue,0,sizeof(Queue));
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
	int i = 0,j = 0;
	int *degree = NULL;
	int **map = NULL;	
	int *res = NULL;
	int tmpval = 0;
	int cnt = 0;
	Queue g_queue;

	que_init(&g_queue);
	
	res = (int *)malloc(sizeof(int)*numCourses);
	memset(res,0,sizeof(int)*numCourses);
	
	degree = (int *)malloc(sizeof(int)*numCourses);
	memset(degree,0,sizeof(int)*numCourses);
	
	map = (int **)malloc(sizeof(int *)*numCourses);
	memset(map,0,sizeof(int *)*numCourses);

	for (i = 0;i < numCourses;i++)
	{
		map[i] = (int *)malloc(sizeof(int)*numCourses);
		memset(map[i],0,sizeof(int)*numCourses);
	}
	
	for (j = 0; j < prerequisitesSize;j++)//使用degree记录每个课程的出入度
	{
		degree[prerequisites[j][0]] += 1;//入度
		map[prerequisites[j][1]][prerequisites[j][0]] = 1;
	}
	
    for (j=0;j<numCourses;j++)
    {
        if (degree[j] == 0)
        {
			enqueue(&g_queue,j);
        }
    }
	
	while (g_queue.size != 0)
	{
		tmpval = dequeue(&g_queue);
		res[cnt++] = tmpval;
		for (i = 0 ;i < numCourses;i++)
		{
			if (map[tmpval][i] == 1)//找到节点
			{
				degree[i] -= 1;//入度-1
				if (degree[i] == 0)//如果入度为0,则入队
				{
					enqueue(&g_queue,i);
				}
			}
		}
	}
	
	for (i = 0;i < numCourses;i++)
	{
		free(map[i]);
	}
	
	free(map);
	free(degree);
    
	if (cnt != numCourses)
	{
		free(res);
		*returnSize = 0;
		res = NULL;
		return res;
	}
	
	*returnSize = cnt;
	return res;
}


void print_arrary(int *g,int size)
{
	int i = 0;
	for ( i = 0;i < size;i++)
	{
		printf("%d\r\n",g[i]);
	}
}

int main()
{
	int i = 0;
	int numCourses = 4;
	int returnSize = 0;
	int prerequisitesSize = 5-1;
	
	int **prerequisites = (int **)malloc(sizeof(int *)*prerequisitesSize);
	memset(prerequisites,0,sizeof(int *)*prerequisitesSize);
	
	for (i = 0;i < prerequisitesSize;i++)
	{
		prerequisites[i] = (int *)malloc(sizeof(int)*2);
		memset(prerequisites[i],0,sizeof(int)*2);
	}
	
	prerequisites[0][0] = 1;
	prerequisites[0][1] = 0;
	
	prerequisites[1][0] = 2;
	prerequisites[1][1] = 0;
	
	prerequisites[2][0] = 3;
	prerequisites[2][1] = 1;
	
	prerequisites[3][0] = 3;
	prerequisites[3][1] = 2;
	
	// prerequisites[4][0] = 0;
	// prerequisites[4][1] = 3;
	
	int* res = findOrder(numCourses,prerequisites,prerequisitesSize,NULL,&returnSize);
	
	print_arrary(res,returnSize);
	
	return 0;
}

