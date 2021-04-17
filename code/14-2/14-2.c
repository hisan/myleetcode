#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int cuttingRope(int n)
{

    int dp[59] = {1};
    for (int i = 0;i < 59;i++)
    {
        dp[i] = 1;//这是因为正整数>=1
    }

    if (n < 3)
    {
        return dp[n];
    }

    for (int i = 3;i <= n;i++)
    {
        for (int j = 1;j < i;j++)
        {
            dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));//寻求每一个值i的最优切法。
	    /*
		对于任意小于i的数字j，首先计算拆分为两个数字的乘积，即j乘以 i-j，
		然后是拆分为多个数字的情况，这里就要用到 dp[i-j] 了，
		这个值表示数字 i-j 任意拆分可得到的最大乘积，再乘以j就是数字i可拆分得到的乘积
	    */
        }
    }

    return dp[n];
}

int main()
{
	int n = 58;
	printf("%d\r\n", cuttingRope(n));
	return 0;
}
