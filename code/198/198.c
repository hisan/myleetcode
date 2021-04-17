
int maxnum(int a,int b)
{
    return a>b?a:b;
}

int rob (int* nums, int numsSize){
    if (numsSize <= 0)
    {
        return 0;
    }
    
    if (numsSize == 1)
    {
        return nums[0];
    }
    
    int dp[500] = {0};
    dp[0] = nums[0];
    dp[1] = maxnum(nums[0],nums[1]);
    int i = 2;
    for (;i < numsSize;i++)
    {
        dp[i] = maxnum(dp[i-1],nums[i] + dp[i-2]);
    }
    return dp[numsSize-1];
}



/*
动态规划角度分析：
原问题：求解偷到的最大钱
子问题：
	当前正在偷第i个房间，
		(1)若可以偷第i个房间此时i房间的的最大财富数nums[i] + 前i-2个房间偷盗的最优数量dp[i-2]
		(2)若不可以，则最大财富为前i-1个房间的最优解dp[i-1]
	因此，第i个房间的最优解为max(dp[i-1],nums[i]+dp[i-2])
*/




