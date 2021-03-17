#include <stdio.h>

int findPeakElement(int* nums, int numsSize)
{
    if (numsSize == 1)
    {
        return 0;
    }

    if (numsSize == 2)
    {
        return nums[1] > nums[0]?1:0;
    }
	
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 1;i < numsSize-1;i++)
    {
        tmp1 = nums[i] > nums[i-1]?1:0;
        tmp2 = nums[i+1] > nums[i]?1:0;
		
		printf("f1:%d f2:%d\n",tmp1,tmp2);
		printf("nums[%d]:%d nums[%d]:%d nums[%d]:%d\n\n",i-1,nums[i-1],i,nums[i],i+1,nums[i+1]);
		
        if (tmp1 != tmp2 && nums[i] > nums[i+1] && nums[i] > nums[i-1])
        {
            return i;
        }

    }

    return -1;
}

int main()
{
	int nums[] = {6,5,4,3,2,3,2};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int index = findPeakElement(nums,numsSize);
	printf("idx:%d\n",index);
	
	return 0;
}