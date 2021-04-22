#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* mergersort(int *array1,int size1,int *array2,int size2)
{
	int i,j;
	int  k = 0;
	int *res = NULL;
	for (i=0,j=0;i < size1 && j < size2;)
	{
		res = realloc(res,sizeof(int)*(k+1));
		if (array1[i] < array2[j])
		{
			res[k++] = array1[i];
			i++;
		}
		else 
		{
			res[k++] = array2[j];
			j++;
		}
	}
	
	while(i<size1)
	{
		res = realloc(res,sizeof(int)*(k+1));
		res[k++] = array1[i];
		i++;
	}
	
	while(j < size2)
	{
		res = realloc(res,sizeof(int)*(k+1));
		res[k++] = array2[j];
		j++;
	}
	
	return res;
}

void print_arrary(int *g,int size)
{
	for (int i = 0; i< size-1;i++)
	{
		printf("%d ",g[i]);
	}
	
	printf("%d\n",g[size-1]);
}

int main()
{
	int array1[] = {1,3,5,7,9};
	int size1 = sizeof(array1)/sizeof(array1[0]);
	
	int array2[] = {2,4,6,8,10,11,12,12,12,12};
	int size2 = sizeof(array2)/sizeof(array2[0]);
	
	int* res = mergersort(array1,size1,array2,size2);
	
	print_arrary(res,size1+size2);
	
	free(res);
	return 0;
}