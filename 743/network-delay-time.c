#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_Queue
{
	int array[2000];
	int head;
	int tail;
	int size;
}Queue;

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

int size_queue(Queue *queue)
{
    return queue->size;
}

Queue g_queue;

int max(int a,int b)
{
    return a>b?a:b;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k)
{
	int visited[101] = {0};
    int edges[101][101] = {0};
    int dist[101];
    int i = 0;
    int j = 0;
    int res = 0;

    for (i = 0 ; i < 101;i++)
    {
        dist[i] = INT_MAX;
        for (j=0;j<101;j++)
        {
            edges[i][j] = -1;
        }
    }
    
    dist[k] = 0;

    for (i = 0;i < timesSize;i++)
    {
        edges[times[i][0]][times[i][1]] = times[i][2]; 
    }

    
    que_init(&g_queue);
    enqueue(&g_queue,k);

    while (size_queue(&g_queue) > 0)
    {
		memset(visited,0,sizeof(int)*101);
		for (i = size_queue(&g_queue);i > 0;i--)//�ӵ�һ�㿪ʼ����һ��ֻ�ж���������
		{
			int vi = dequeue(&g_queue);
			 for (j = 1; j <= n;j++)//��������vi���б�
			{
				if (edges[vi][j] != -1 && dist[vi] + edges[vi][j] < dist[j])//�������������̰���㷨�����Ǵӽڵ�vi��j�ı߾�,���ϴ�Դ�ڵ㵽vi�ľ���dist[vi],��С��dist[j],����Ը���dist[j]����С���롣
				{
					if (visited[j] == 0) {
						visited[j] = 1;
						enqueue(&g_queue,j);
					}

					dist[j] = dist[vi] + edges[vi][j];
				}
			}
			
		}
    }

    for (int i = 1; i <= n; ++i) 
    {
        res = max(res, dist[i]);//����Դ�ڵ㵽���нڵ�ľ��룬��ô����һ���������ǽ����ĵ��ʱ�䡢Ҳ������������ʱ�ӣ���ɽ��ˮ��ͬʱ���У�
    }

    return res == INT_MAX ? -1 : res;
}

int main()
{
	int n = 3;
	int k = 1;
	int timesSize = 3;
	
	int second = 0;
	int timesColSize = 3;
	
	int** times = (int **)malloc(sizeof(int *)*timesSize);
	for (int i = 0 ;i < timesSize;i++)
	{
		times[i] = (int *)malloc(sizeof(int)*timesColSize);
		memset(times[i],0,sizeof(int)*timesColSize);
	}
	
	times[0][0] = 1;
	times[0][1] = 2;
	times[0][2] = 1;
	

	times[1][0] = 2;
	times[1][1] = 3;
	times[1][2] = 2;

#if 0
	times[2][0] = 1;
	times[2][1] = 3;
	times[2][2] = 2;

#endif
	
	
	#if 0
	[[1,2,1],[2,3,2],[1,3,2]]
3
1
	#endif 
	
	second = networkDelayTime(times,timesSize,&timesColSize,n,k);
	
	printf("%d\n",second);
	
	return 0;
}







