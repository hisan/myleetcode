#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int hashmap1[10000000] = {0};
    int hashmap2[10000000] = {0};
    int *ret = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    for (int i=0; i<numsSize;i++)
    {
        int tmp = target - nums[i];
        if (tmp >= 0)
        {
            if (hashmap1[tmp] != 0)
            {
                ret[0] = i;
                ret[1] = hashmap1[tmp] - 1;
                return ret;
            }
        }
        else
        {
            if (hashmap2[abs(tmp)] != 0)
            {
                ret[0] = i;
                ret[1] = hashmap2[abs(tmp)] - 1;
                return ret;
            }
        }

        if (nums[i] >= 0)
        {
            hashmap1[nums[i]] = i+1;
        }
        else 
        {
            hashmap2[abs(nums[i])] = i+1;
        }
    }

    *returnSize = 0;
    return NULL;
}


int main()
{
	int nums[] = {2,7,11,15};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 9;
	int returnSize = 0;
	
	int* ret = twoSum(nums,numsSize,target,&returnSize);
	
	printf("%d %d\n",ret[0],ret[1]);
	
	return 0;
}









