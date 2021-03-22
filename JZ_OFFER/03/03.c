int findRepeatNumber(int* nums, int numsSize){
    int map[100000] = {0};
    int map2[100000] = {0};

    for (int i = 0 ; i < numsSize;i++)
    {
        if (nums[i] > 0)
        {
            if (map[nums[i]] > 0)
            {
                return nums[i];
            }

            map[nums[i]]++;
        }
        else
        {
            if (map2[abs(nums[i])] > 0)
            {
                return nums[i];
            }

            map2[abs(nums[i])]++;
        }
    }

    return -1;
}
