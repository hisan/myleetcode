int max(int a,int b)
{
    return a>b?a:b;
}

int maxSubArray(int* nums, int numsSize){
    int cur_sum = 0;
    int res = -200;

    for (int i = 0 ; i < numsSize;i++)
    {
        cur_sum = max(cur_sum + nums[i],nums[i]);
        res = max(res,cur_sum);
    }

    return res;
}
