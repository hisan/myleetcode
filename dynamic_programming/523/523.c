/*
	2020-08-01 23:28 浙江杭州
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 1
#define true 0

#define bool int 
bool dfs(int start,int end,int total,int k,int *nums,int *dep)
{
    if ((total + nums[start]) % k ==0)
    {
        if (start > 0 && *dep > 0)
        {
            return true;
        }
    }
    else 
    {
        if (start +1 >= end)
        {
            return false;
        }

        total += nums[start];
        *dep += 1;
        return dfs(start+1,end,total,k,nums,dep);
    }
	
    return false;
}

bool checkSubarraySum(int* nums, int numsSize, int k){
    k = abs(k);
    if (numsSize <= 1)
    {
        return false;
    }

    if (k == 1)
    {
        return true;
    }

    for (int i = 0;i < numsSize;i++)
    {
        if (i < numsSize -1)
        {
            if (nums[i] == 0 && nums[i+1] == 0)
            {
                return true; 
            }
        }
    }

    if (k == 0)
    {
        for (int i = 0;i < numsSize;i++)
        {
            if (i < numsSize -1)
            {
                if (nums[i] == 0 && nums[i+1] == 0)
                {
                    return true; 
                }
            }
        }

        return false;
    }

    int tmp = 0;
    for (int i = 0; i < numsSize;i++)
    {
        tmp += nums[i];
    }

    if (tmp < k)
    {
        return false;
    }

    int dep = 0;

    for (int i = 0 ; i < numsSize;i++)
    {    
        dep = 0;
        if (true == dfs(i,numsSize,0,k,nums,&dep))
        {
            return true;
        }
    }

    return false;
}

/*
这题，因为限制条件是字数组长度>=2,所以使用DFS就不需要回溯了。
*/


int main(){
	int a[3] = {1,2,3};
	//int a[9] = {0,1,0,3,0,4,0,4,0};
	int k = 5;
	int value = checkSubarraySum(a,sizeof(a)/sizeof(int),k);
	printf("%d\r\n",value);
	return 0;
}
