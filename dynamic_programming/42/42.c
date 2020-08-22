/* 2020-06-09 23:31 º¼ÖÝ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN ~((1<<30)-1)

int max(int a,int b)
{
	return a<b?b:a;
}

int maxSubArray(int* nums, int numsSize)
{
	int res = INT_MIN, curSum = 0;
	for (int i = 0;i < numsSize;i++)
	{
		curSum = max(curSum + nums[i],nums[i]);
		res = max(res, curSum);
	}
	return res;
}

int main()
{
	int num[] = {-2,1,-3,4,-1,2,1,-5,4};
	int numsSize = sizeof(num)/sizeof(num[0]);
	int ret = maxSubArray(num,numsSize);
	printf("%d\r\n",ret);
}