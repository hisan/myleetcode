#if 0
o(n)空间
#endif 

int findDuplicate(int* nums, int numsSize){
    int map[30002] = {0};
    for (int i = 0 ; i < numsSize;i++)
    {
        if (map[nums[i]] >= 1)
        {
            return nums[i];
        }
        map[nums[i]]++;
    }

    return -1;
}


#if 0

鸠巢原理，没理解

#endif 

int getlessthan_k(int *g,int size,int k)
{
    int count = 0;
    for (int i = 0 ; i < size;i++)
    {
        if (g[i] <=k)
        {
            count++;
        }
    }

    return count;
}

int findDuplicate(int* nums, int numsSize){
    int left = 1, right = numsSize;
    int mid  = 0;

    while (left < right)
    {
        mid = (right + left)/2;
        int tmp = getlessthan_k(nums,numsSize,mid);
        
        printf("mid:%d tmp:%d\n",mid,tmp);

        if (tmp <= mid)
        {
            left = mid+1;
        }
        else 
        {
            right = mid;
        }
    }

    return left;
}

#if 0
快慢指针
#endif

int findDuplicate(int* nums, int numsSize){
    int fast = 0;
    int slow = 0;
    while (1)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if (slow == fast)
        {
            fast = 0;
            while (nums[slow] != nums[fast])
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return nums[slow];
        }
    }

    return -1;
}

