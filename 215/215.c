
//冒泡排序

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int findKthLargest(int* nums, int numsSize, int k) {
    //冒泡排序
    int i,j;
    for(i = 0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i] < nums[j])
            {
                swap(&nums[i],&nums[j]);
            }
        }
    }
    
    return nums[k-1];
}

