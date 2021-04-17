int findMin(int* nums, int numsSize){
    if (numsSize == 1)
    {
        return nums[0];
    }

    int left = 0;
    int right = numsSize-1;
    
    if (nums[left] < nums[right])
    {
        return nums[left];
    }

    while (nums[left] > nums[right])
    {
        int mid = (left+right)/2;
        if (nums[left] < nums[mid])
        {
            left = mid;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid;
        }
        else 
        {
            return nums[mid+1];
        }
    }

    return -1;
}
