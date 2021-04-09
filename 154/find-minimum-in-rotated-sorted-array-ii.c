int min(int a,int b)
{
    return  a <=b?a:b;
}

int getmin(int *nums,int left,int right)
{
    int ret = nums[left];
    for (int i = left+1;i <= right;i++)
    {
        ret = min(ret,nums[i]);
    }

    return ret;
}


int findMin(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    if (numsSize == 1)
    {
        return nums[left];
    }

    while (nums[left] >= nums[right])//>=条件的必要：{5,5,1,2,3,4,5}
    {
        int mid = (left+right)/2;
        if (nums[left] <nums[mid])
        {
            left = mid;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid;
        }
        else 
        {
            return getmin(nums,left,right);
        }
    }

    return nums[left];
}
