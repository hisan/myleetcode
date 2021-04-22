#include <stdio.h>

//O(n) = 1.最大时间复杂度为O(n^2)
void insertsort(int *a,int size)
{
	if (!a || size <= 0)
	{
		return;
	}
	
	for (i=1;i < size;i++)
	{
		int j = i-1;
		while (j >= 0 && a[j] > a[i])
		{
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = a[i];
	}
}


void print_array(int *g,int size)
{
	int i = 0;
	for (; i < size;i++)
	{
		printf("%d\n",g[i]);
	}
}

int main()
{
	int a[] = {25,28,520,105,110,1,2,25,100,101,21,23,3,92,94,98,3,61,4,19,24,102,104,53,70,71,82,83,86,12};
	int size = sizeof(a)/sizeof(int);
	insertsort(a,size);
	print_array(a,size);
	
	return 0;
}


#if 0

感觉很慢

#endif