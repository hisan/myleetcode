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



bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){

	int i = 0,j = 0;
	int *degree = NULL;
	int **map = NULL;	
	int *res = NULL;
	int tmpval = 0;
	int cnt = 0;
	Queue g_queue;

	que_init(&g_queue);

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
		cnt++;
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
		return false;
	}

	return true;
}


