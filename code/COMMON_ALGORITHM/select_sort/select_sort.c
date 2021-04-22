#include <stdio.h>

void selectsort(int *g,int size)
{
	if (!g || size <= 0)
	{
		return;
	}
	
	#if 0
	从i之后的元素选取一个最小的元素,若该元素比g[i]还小,则与之交换
	#endif
	for (int i = 0;i < size;i++)
	{
		int min_idx = i;
		for (int j = i+1;j < size;++j)
		{
			if (g[j] < g[min_idx])
			{
				min_idx = j;
			}
		}
		
		if (min_idx != i)
		{
			g[i] ^= g[min_idx];
			g[min_idx] ^= g[i];
			g[i] ^= g[min_idx];
		}
	}
}


void print_array(int *g,int size)
{
	int i = 0;
	for (; i < size;i++)
	{
		printf("%d ",g[i]);
	}
	
	printf("\n");
}

int main()
{
	int b[] = {1,2,23,10,123,162,121};
	int size1 = sizeof(b)/sizeof(b[0]);
	
	selectsort(b,size1);
	print_array(b,size1);
}