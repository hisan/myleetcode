int searchInsert(int* nums, int numsSize, int target){
    if (nums == NULL || numsSize <= 0)
    {
        return -1;
    }

    int left = 0;
    int right = numsSize -1;
    int mid = 0;
    int pos = 0;

    while (left < right)
    {
        mid = (left+right)/2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid+1;
        }
        else 
        {
            right = mid-1;
        }
    }
    
    if (target > nums[left])
    {
        pos = left+1;
    }
    else 
    {
        pos = left;
    }

    return pos;
}
