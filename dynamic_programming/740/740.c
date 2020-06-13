//2020-06-13 23:07 杭州  通过
#include <stdio.h>
int max(int a,int b)
{
	return a<b?b:a;
}

int deleteAndEarn(int* nums, int numsSize)
{
	int sums[10001] = {0};
	int take = 0,skip = 0;
	
	for (int i = 0; i < numsSize;i++)
	{
		sums[nums[i]] += nums[i];//先统计每种数字的最大值
	}
	
	for (int i = 0; i < 10001; i++)
	{
		int takei = sums[i] + skip;//(在从前往后拿数字的基础上)，我们拿了当前的数字能得到积分就是当前数字的积分sums[i]，再加上不拿前面的数字能得到的积分
		int skipi = max(skip,take);//不拿当前的数字，那么前面的数字我们可拿可不拿，所以不拿当前数字的最大积分==max(拿前面的数字的积分，不拿前面的数字的积分)
		take = takei;
		skip = skipi;
	}
	
	return max(skip,take);
}

int main()
{
	//int nums[] = {2, 2, 3, 3, 3, 4};
	int nums[] = {3, 4, 2};
	
	int ret = deleteAndEarn(nums,sizeof(nums)/sizeof(nums[0]));
	printf("%d\r\n",ret);
	
}