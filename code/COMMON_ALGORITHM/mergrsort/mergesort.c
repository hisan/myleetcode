//2020-0606 ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "/home/zyb/CODE/API/include/aux_api.h"

//�鲢�����˼��:�鲢�����ǽ����ںϲ���������Ļ����ϵģ��������ǵ�Ŀ�ľ��Ƕ���������������ԣ�����Ӧ�ý�ԭʼ���黮�ֳɵ�����������У������ϲ�������������������


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



