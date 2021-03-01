int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;   
    if (numsSize == 0 || (numsSize == 1 && nums[0] == val))
    {
        return 0;
    }
    
	for (i = 0;i < numsSize;i++)
	{
		if (nums[i] == val)
		{
			for (int j = i ; j < numsSize-1;j++)
			{
				nums[j] = nums[j+1];
			}
			
			i = 0;
			numsSize -= 1;
		}
    }

    if (nums[0] == val)
    {
      	for (i = 0;i < numsSize-1;i++)
	    {
             nums[i] = nums[i+1];   
        }

        numsSize -= 1;
    }

	return numsSize;
}
