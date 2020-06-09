//2020-06-07 杭州
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int min(int a,int b)
{
	return a<b?a:b;
}

#if 0
/*

暴力解法，累加每一种可能即能得到结果
但是会超时

*/
void helper(int *coins,int coinsSize,int start,int amount,int *res)
{
    if (amount < 0)//不能构成n的表示的情形
    {
        return;
    }

	if (amount == 0)
	{
		*res += 1;
		return;//当前这种方法已经可以达成解了，反回上一步继续下种解法的尝试。
	}
	
    for (int i = start;i >= 0;i--)
    {
        if (amount >= coins[i])
        {
            helper(coins,coinsSize,i,amount - coins[i],res);
        }
    }
}

int waysToChange(int n)
{
    int coins[4] ={1,5,10,25};
    int coinsSize = 4;
    int res = 0;
    helper(coins,coinsSize,coinsSize-1,n,&res);
    return res;
}

#endif

#define MAX_MOD	1000000007

#ifdef jiefa2

int waysToChange(int n)
{
    int coins[4] ={1,5,10,25};
    int coinsSize = 4;
    int res = 0;
	int *dp = (int *)malloc(sizeof(int)*(n+1));
	memset(dp,0,sizeof(int)*(n+1));
	dp[0] = 1;
	
	for (int j = 0; j < coinsSize; j++)//去重需要
	{
		for (int i = 1; i <= n; i++)
		{
			if (coins[j] <= i) 
			{
				dp[i] = (dp[i] + dp[i - coins[j]])%MAX_MOD;
			}
		}
	}
	
	return dp[n];
}

/*
千说万说，首先一定要保证状态方程是对的，
dp[i] = dp[i] + dp[i - coins[j]],即i的组合方式.

在dp初始化后，我们只知道dp[0]=1,其余的我们不知道，所以一律赋值为0。

那么dp[n]的组合方式一定等于dp[n]目前的组合方式与dp[n-coins[x]]的组合方式的累加

*/

#endif 


/*

解法2可以得到解，但是还是没搞清楚动态转移方程为何这么来？
所以我们继续看大佬的题解。



1.首先,我们求的是组合方式,那么其实,我们的重点要放在硬币种类上，
因为硬币我们是可以无限取的,所以n无论多大都不是事儿，只要我们不断地取,n最终会被消减的很小。
所以，要搞清楚，状态转移方程，是和硬币种类强相关。

2.既然求组成n的硬币组合数，那么,我们可以任意组合硬币，那些组合后将n消减为0的组合即为满足条件的组合。

用dp[i][j]表示，前i种硬币能够组合成钱j的方式数。那么，我们一个一个硬币地加，就能达到自底向上地求出所有j的不同硬币组合的情况。

对于遍历到的当前钱数j，组成方法就是不仅加上当前硬币的拼法 dp[i-1][j]，还要加上，去掉当前硬币值的钱数的组成方法，
当然钱数j要大于当前硬币值(j>coins[i-1])

所以动态转移方程可以这样写：
	dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
一定一定地强调，这个状态转移方程虽然看着是解的前后重叠，但是一定只能从底向上推,
因为我们只能从初始条件中得到最底层的几个解，只能由这几个解不断地重叠上升地得到其他的解。


3再次理解：
(首先来考虑最简单的情况，如果只有一个硬币的话，那么给定钱数的组成方式就最多有1种，就看此钱数能否整除该硬币值。
当有两个硬币的话，组成某个钱数的方式就可能有多种，
比如可能由每种硬币单独来组成，或者是两种硬币同时来组成，怎么量化呢？比如我们有两个硬币[1,2]，
钱数为5，那么钱数的5的组成方法是可以看作两部分组成，

一种是由硬币1单独组成，那么仅有一种情况 (1+1+1+1+1)；
另一种是由1和2共同组成，说明组成方法中至少需要有一个2，所以此时先取出一个硬币2，

然后只要拼出钱数为3即可，这个3还是可以用硬币1和2来拼，所以就相当于求由硬币 [1,2] 组成的钱数为3的总方法。
)

这段话才是理解动态转移方程为何这么写的原因？

我们从一个硬币开始，用这一个硬币组合面值为1~n,组合方式,那么，在满足组合条件下(n能被coins[0]整除),
可知对任意的n,组合方式一定只有一种.

所以我们逐一地增加可以用于组合的硬币，那么，组合方式就是由硬币数决定，所以我们必须从少到多地过度。


#if 0
dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
//即，即可由前面的硬币单独组成，也可由当前硬币数组合而成。
#endif 

*/

int waysToChange(int n)
{
	int coins[4] = {1,5,10,25};
	int coinsSize = 4;
	int **dp  = (int **)malloc(sizeof(int *)*(coinsSize+1));
	for (int i = 0; i < coinsSize + 1;i++)
	{
		dp[i] = (int *)malloc(sizeof(int)*(n+1));
		memset(dp[i],0,sizeof(int)*(n+1));//dp[0][m]：不使用钱来组成m(m>0),组合方式当然为0。
	}
	
	dp[0][0] = 1;
	
	for (int i = 1;i < coinsSize+1;i++)
	{
		dp[i][0] = 1;
		for (int j = 1;j < n+1;j++)
		{
			dp[i][j] = dp[i-1][j] + (j >= coins[i-1]?dp[i][j-coins[i-1]]:0);
		}
	}
	
	return dp[coinsSize][n];
}

int main()
{
	printf("%d\r\n",waysToChange(25));
}
