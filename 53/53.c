
int max(int a,int b) 
{
    return a>b?a:b;
}

int maxSubArray(int* nums, int numsSize){
    int* dp = (int*)malloc(sizeof(int)*numsSize);
    memset(dp,0,sizeof(int)*numsSize);
    dp[0] = nums[0];
    int ret = nums[0];
    for (int i = 1; i< numsSize;i++)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        if (ret <= dp[i])
        {
            ret = dp[i];
        }
    }
    free(dp);
    return ret;
}



