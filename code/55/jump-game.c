bool canJump(int* nums, int numsSize){
    int n = 1;
    int i = 0;
    for (i = numsSize - 2;i >= 0;i--)
    {
        if (nums[i] >= n)
        {
            n = 1;
        }
        else 
        {
            n++;
        }
    }

    printf("%d  %d\n",i,n);

    if (i == -1 && n == 1)
    {
        return true;
    }

    return false;
}

