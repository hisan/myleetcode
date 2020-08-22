1.暴利解决，
    时间复杂度O（n2 )
    空降复杂度O（n）
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int *num = NULL;
int* twoSum(int* nums, int numsSize, int target)
{
    num = malloc(sizeof(int)*2);
    for(int i = 0 ;i<numsSize-1;i++)出错（3）：没有考虑清楚边界条件，i只需从第一个元素遍历到倒数第二个元素即可
    {
        for(int j= i+1 ;j<numsSize;j++)
        {
            if(*(nums+i)==target-*(nums+j))//出错（2）：将=写成==
            {
                *num=i;
                *(num+1)=j;
                return num;
            }
        }
    }
    return 0;//出错（1）：一开始并没有写这个返回语句，结果编译不通过，起因是因为，我以为有返回语句   return num了，可是，这是找到的情况下的返回，那么，找不到就不返回了吗？
}