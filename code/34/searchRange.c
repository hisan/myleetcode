#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){

    int *res = (int *)malloc(sizeof(int)*2);
    res[0] = -1;
    res[1] = -1;

    *returnSize = 0;
    int left = 0;
    int right = numsSize -1;
    int mid = 0;

    while (left < right)
    {
        mid = (left+right)/2;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }

    if (nums[left] == target)
    {

        (*returnSize) += 1;
        res[0] = left;
    }
    
    right = numsSize-1;
    while (left < right)
    {
        mid = (left+right)/2;
		
		printf("left: %d right:%d mid: %d\n",left,right,mid);
        
		if (nums[mid] <= target)
        {
            left = mid;
        }
        else
        {
            right = mid-1;
        }
    }

    if (nums[right] == target)
    {
        (*returnSize) += 1;
        res[1] = right;
    }

    return res;
}

int main()
{
	int nums[] = {5,7,7,8,8,10};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 0;
	scanf("%d",&target);
	int retsize = 0;
	int *res = searchRange(nums,numsSize,target,&retsize);
	
	printf("%d %d\n",res[0],res[1]);
	return 0;
}


