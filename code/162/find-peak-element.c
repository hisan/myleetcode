//O(n)解法
int findPeakElement(int* nums, int numsSize){

    if (numsSize == 1)
    {
        return 0;
    }

    int i = 0;
    for ( i = 0;i < numsSize -1;i++)
    {
        if (nums[i] > nums[i+1])
        {
            return i;
        }
    }

    return i;
}


#if 0

这道题求峰值的任何一个即可，且题目告知num[-1] = nums[n] = 负无穷

那么我们只需要从第一个元素遍历，找到第一个满足：后一个元素大于前一个元素的情况，此时就能得到峰值
那么对于{1,2,3}这种递增的，由于不满足nums[i+1] < nums[i],所以i一直递增到i=numsSize-1,此时返回i也是正确的。而对于{3,2,1}这种数组，连for循环的进不去，此时i=0，那么返回i也是正确的。

#endif 


//O(logN) //二分法
理论依据:
(1).若nums[i] > nums[i+1],则i及之前一定有峰值
(2).若nums[i] < nums[i+1],则i+1及其之后一定有峰值

int findPeakElement(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    for (;left < right;)
    {
        int mid = left+(right-left)/2;
        if (nums[mid] > nums[mid+1])
        {
            right = mid;
        }
        else 
        {
            left = mid + 1;
        }
    }
    
    return left;
}
}