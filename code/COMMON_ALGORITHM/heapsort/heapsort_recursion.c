#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void outputarray(int *g,int size)
{
	for (int i = 0; i < size;i++)
	{
		printf("%d ",g[i]);
	}
	printf("\n");
}

void adjustdown(int *g,int i,int size)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int larget = i;
	
	if (l < size && g[l] > g[larget])
	{
		larget = l;
	}
	
	if (r < size && g[r] > g[larget])
	{
		larget = r;
	}
	
	if (larget != i)
	{
		g[i] ^= g[larget];
		g[larget] ^= g[i];
		g[i] ^= g[larget];
		adjustdown(g,larget,size);
	}
}

void buildmaxheap(int *g,int size)
{
	for (int i = (size/2)-1;i>=0;--i)
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

int main()
{
	int g[] = {100,4,6,1,1,12,1,14,43,1234,1231,12};
	int size = sizeof(g)/sizeof(g[0]);
	
	heapsort(g,size);
	outputarray(g,size);
	return 0;
}







