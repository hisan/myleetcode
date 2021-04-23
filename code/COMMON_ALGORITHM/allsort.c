#include <stdio.h>
#include <stdlib.h>
#include "/home/zyb/CODE/API/include/aux_api.h"

//select_sort.c
void select_sort(int *g,int size)
{
	for (int i = 0; i < size;i++)
	{
		int min_idx = i;
		for (int j = i+1;j < size;j++)
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

//insert_sort.c
void insert_sort(int *g,int size)
{
	for (int i = 1;i < size;i++)
	{
		int j = i-1;
		while (j >=0 && g[j] > g[i])
		{
			g[j+1] = g[j];
			--j;
		}
		g[j+1] = g[i];
	}
}

//bubble_sort.c
void bubble_sort(int *g,int size)
{
	for (int i = 0; i < size-1;++i)
	{
		int bswitch = 0;
		for (int j = size-1;j > i;--j)
		{
			if (g[j-1] > g[j])
			{
				g[j-1] ^= g[j];
				g[j] ^= g[j-1];
				g[j-1] ^= g[j];
				bswitch = 1;
			}
		}
		if (bswitch == 0)
		{
			break;
		}
	}
}

//quick_sort.c
int parttion(int *g,int left,int right)
{
	int key = g[left];
	while (left < right)
	{
		while (left < right && g[right] >= key)
		{
			right--;
		}
		g[left] = g[right];
		while (left < right && g[left] <= key)
		{
			left++;
		}
		g[right] = g[left];
	}
	
	g[left] = key;
	return left;
}

void quick_sort(int *g,int left,int right)
{
	if (left < right)
	{
		int piviot = parttion(g,left,right);
		quick_sort(g,left,piviot-1);
		quick_sort(g,piviot+1,right);
	}
}

void quicksort(int *g,int size)
{
	int left = 0;
	int right = size-1;
	quick_sort(g,left,right);
}


//heap_sorrt.c
void adjustdown(int *g,int i,int size)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	
	if (l < size && g[largest] < g[l])
	{
		largest = l;
	}
	
	if (r < size && g[largest] < g[r])
	{
		largest = r;
	}
	
	if (largest != i)
	{
		g[i] ^= g[largest];
		g[largest] ^= g[i];
		g[i] ^= g[largest];
		adjustdown(g,largest,size);
	}
}

void buildmaxheap(int *g,int size)
{
	for (int i = (size/2)-1;i >=0;--i)
	{
		adjustdown(g,i,size);
	}
}

void heapsort(int *g,int size)
{
	buildmaxheap(g,size);
	for (int i = size-1;i >= 1;--i)
	{
		g[i] ^= g[0];
		g[0] ^= g[i];
		g[i] ^= g[0];
		adjustdown(g,0,i);
	}
}

//merge_sort.c
void merge(int *g,int left,int mid,int right)
{
	int *tmp = (int *)malloc(sizeof(int)*(right-left+1));
	int index = 0;
	int L_idx = left;
	int R_idx = mid+1;
	
	while (L_idx <=mid && R_idx <=right)
	{
		if (g[L_idx] <= g[R_idx])
		{
			tmp[index++] = g[L_idx++];
		}
		else 
		{
			tmp[index++] = g[R_idx++];
		}
	}
	
	while (L_idx <= mid)
	{
		tmp[index++] = g[L_idx++];
	}
	
	while (R_idx <= right)
	{
		tmp[index++] = g[R_idx++];
	}
	
	for (int i = left;i <= right;++i)
	{
		g[i] = tmp[i-left];
	}
	
	free(tmp);
}

void merge_sort(int *g,int left,int right)
{
	if (left >= right)
	{
		return;
	}
	
	int mid = (left + right)/2;
	merge_sort(g,left,mid);
	merge_sort(g,mid+1,right);
	merge(g,left,mid,right);
}

void mergesort(int *g,int size)
{
	if (!g || size <= 0)
	{
		return;
	}
	
	int left = 0;
	int right = size-1;
	merge_sort(g,left,right);
}


int main()
{
	int g[] = {25,28,520,105,110,1,2,25,100,101,21,23,3,92,94,98,3,61,4,19,24,102,104,53,70,71,82,83,86,12};
	int size = sizeof(g)/sizeof(g[0]);
	
	select_sort(g,size);
	outputarray(g,size);
	
	insert_sort(g,size);
	outputarray(g,size);
	
	bubble_sort(g,size);
	outputarray(g,size);
	
	quicksort(g,size);
	outputarray(g,size);
	
	heapsort(g,size);
	outputarray(g,size);
	
	mergesort(g,size);
	outputarray(g,size);
	
	return 0;
}
