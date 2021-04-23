
int parttion(int *g,int left,int right)
{
    int key = g[left];
    while (left < right)
    {
        while (left < right && g[right] >= key)
        {
            right--;
        }

        g[left] = g[right];

        while (left < right && g[left] <= key)
        {
            left++;
        }
        g[right] = g[left];
    }
    g[left] = key;
    return left;
}




#if 0
借助快速排序的划分思想，每一趟划分，确定一个元素在数组中的有序的固定的位置。此时，若此位置就是题目要求的序号的元素，那么直接返回即可。
如不是，如果此位置左边的元素的个数>=k,则此,那么要求的元素一定落在左边，否则就落在右边,按照这个规则最终可得到题目要求的元素，此时返回即可。
#endif 

int findKthLargest(int* nums, int numsSize, int k){

    int left = 0;
    int right = numsSize -1;
    int pivoit = parttion(nums,left,right);
    int seq = numsSize - k+1;
    while (seq-1 != pivoit)
    {
        printf("%d ",pivoit);
        if (pivoit < seq -1)
        {
            left = pivoit+1;
            pivoit = parttion(nums,left,right);
        }
        else 
        {
            right = pivoit-1;
            pivoit = parttion(nums,left,right);
        }
    }

    return nums[seq-1];
}


