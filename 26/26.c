#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int tmp = numsSize;
    int value = nums[0];
    for (int i = 1 ;i < tmp;i++)
    {
        if (nums[i] == value)
        {
            for (int j = i;j < tmp-1;j++)
            {
                nums[j] = nums[j+1];
            }

            tmp -= 1;
			i -= 1;
        }
        else 
        {
            value = nums[i];
        }
    }

    return tmp;
}

int main()
{
	int a[] = {0,0,1,1,1,2,2,2,3,3,4};
	int size = sizeof(a)/sizeof(a[0]);
	int ret = removeDuplicates(a,size);
	
	for (int i = 0 ; i< ret-1;i++)
	{
		printf("%d,",a[i]);
	}
	
	printf("%d\r\n",a[ret-1]);
	
	return 0;
}