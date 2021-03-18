bool containsDuplicate(int* nums, int numsSize){
    if (numsSize <= 1)
    {
        return false;
    }
    
    int map[10000000] = {0};//一个存储正整数
    int map2[10000000] = {0};//一个存储负数

    for (int i = 0; i < numsSize;i++)
    {
        if (nums[i] < 0)
        {
            if (map2[abs(nums[i])] >= 1)
            {
                return true;
            }
            map2[abs(nums[i])] += 1;
        }
        else 
        {
            if (map[nums[i]] >= 1)
            {
                return true;
            }

            map[nums[i]] += 1;
        }

    }

    return false;
}
