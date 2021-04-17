#include <stdio.h>
#include "print_array.h"

void print_onedim_array(int *g,int size)
{
	printf("\n\n");
	int i = 0;
	for (i = 0; i < size -1;i++)
	{
		printf("%d,",g[i]);
	}
	
	printf("%d\t\n",g[size-1]);
}

void print_twodim_array(int**ppg,int size,int *col_size)
{
	printf("\n\n");
	int i = 0;
	for (i = 0; i < size;i++)
	{
		print_onedim_array(ppg[i],col_size[i]);
	}
}
