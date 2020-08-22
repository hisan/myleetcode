#include <stdio.h>
#include <stddef.h>
#include "../list.h"

int main()
{
	int a[] = {1,234,345,1,56,12,4657,12,6524};
	node *list = NULL;
	list = CreateSingleyLinkList_FromArray(a,sizeof(a)/sizeof(int));
	
	printf("before sort!\r\n");
	
	if (list != NULL)
	{
		printlist(list);
	}
	
	insertionSortList(list);
	printf("after sort!\r\n");
	if (list != NULL)
	{
		printlist(list);
	}
	
	Freelist(list);
	
	return 0;
}
