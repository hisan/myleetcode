/*
*	³¬Ê±
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int subarraySum2(int* nums, int numsSize, int k){
    int ret = 0;
    int tmp = 0;
    int i,j;
    int retnum = 0;
    int sum[20001] = {0};
	
    for (i = 1;i <=numsSize;i++)
    {
		sum[i] = sum[i-1] + nums[i-1];
    }
	
	for (i = 0;i < numsSize;i++)
    {
        if (sum[i] == k)
            retnum++;
        for (j = i+1;j <numsSize;j++)
        {
			if (sum[j] - sum[i] == k)
			{
				retnum++;
			}
        }
    }
    return retnum;
}


void DFS(int *nums,int numsSize,int start,int *retSize,int k,int cur_num,int curdep,int first_flag)
{
    if (cur_num == k && 0 != first_flag)
    {
        (*retSize) += 1;
    }

	if (curdep == 0)
    {
        return;
    }
	
    cur_num += nums[start];
    DFS(nums,numsSize,start+1,retSize,k,cur_num,curdep-1,1);
}

int subarraySum(int* nums, int numsSize, int k){
    int ret = 0;
    int tmp = 0;
    int retSize = 0;
    int i = 0;
    int curdep = 0;
    int cur_num = 0;

    for (i = 0;i < numsSize;i++)
    {
        curdep = numsSize - i;
        cur_num = 0;
        DFS(nums,numsSize,i,&retSize,k,cur_num,curdep,0);
    }

    printf("%d\n",retSize);
    return retSize;
}

int main()
{
	//int nums[] = {-1,-1,1};
	//int k = 0;
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	#if 0
	printf("1.start %d\n",(int)time(NULL));
	int ret = subarraySum(nums,numsSize,k);
	printf("1.end %d\n\n",(int)time(NULL));
	printf("%d\n",ret);
	#endif
	
	printf("2.start %d\n",(int)time(NULL));
	int ret2 = subarraySum2(nums,numsSize,k);
	printf("2.end %d\n",(int)time(NULL));
	printf("%d\n",ret2);
	
	return 0;
}


