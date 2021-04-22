#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outputarray(int *g,int size)
{
	for (int i = 0;i < size;i++)
	{
		printf("%d ",g[i]);
	}
	printf("\n");
}

//O(n) = 1.最大时间复杂度为O(n^2)
void insertsort(int *arr,int size)
{
	for (int i = 1;i < size;i++)
	{
		int key = arr[i];
		int j = i-1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}


int main()
{
	int arr[1000] = {0};
	int i = 0;
	int n = 0;
	printf("num size: ");
	scanf("%d\n",&n);
	
	for (int i = 0 ; i < n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	insertsort(arr,n);
	outputarray(arr,n);
}