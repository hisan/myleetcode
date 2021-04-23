#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maxheapify(int *g,int i,int size)
{
    int l = i*2+1;
    int r = i*2+2;
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
        g[larget] ^= g[i];
        g[i] ^= g[larget];
        g[larget] ^= g[i];

        maxheapify(g,larget,size);
    }
}

void buildmaxheap(int *g,int size)
{
    for (int i = (size/2)-1;i>=0;--i)
    {
        maxheapify(g,i,size);
    }
}

void heapsort(int *g,int size,int k)
{
    buildmaxheap(g,size);
    for (int i = size-1;i > size-k;--i)
    {
        g[0] ^= g[i];
        g[i] ^= g[0];
        g[0] ^= g[i];

        maxheapify(g,0,size);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    if (!nums || numsSize <= 0)
    {
        return 0;
    }

    heapsort(nums,numsSize,k);
    return nums[0];
}

int main()
{
	int nums[] = {2,1};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int k = 2;
	int ret = findKthLargest(nums,numsSize,k);
	
	printf("%d\n",ret);
	
	return 0;
}


















