//2020-0606 杭州
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "/home/zyb/CODE/API/include/aux_api.h"

//归并排序的思想:归并排序是建立在合并有序数组的基础上的，但是我们的目的就是对数组进行排序。所以，我们应该将原始数组划分成单个有序的序列，再两合并，最终整个数组有序。


void merge(int *a,int l,int m,int r)
{
	int *tmp = NULL;
	tmp = (int *)malloc(sizeof(int)*(r - l + 1));
	int index = 0;
	
	int Lidx = l;
	int Ridx = m+1;
	
	while (Lidx <= m && Ridx <= r)
	{
		if (a[Lidx] <= a[Ridx])
		{
			tmp[index++] = a[Lidx++];
		}
		else 
		{
			tmp[index++] = a[Ridx++];
		}
	}
	
	while (Lidx <= m)
	{
		tmp[index++] = a[Lidx++];
	}
	
	while (Ridx <= r)
	{
		tmp[index++] = a[Ridx++];
	}
	
	for (int i = l;i <=r;++i)
	{
		a[i] = tmp[i-l];
	}
	
	free(tmp);
}

void mergesort(int *a,int low,int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main()
{
	int a[] = {1,12,1,3,23,56,23,12};
	int num = sizeof(a)/sizeof(a[0]);

	mergesort(a,0,num - 1);
	outputarray(a,num);	
	return 0;
}



