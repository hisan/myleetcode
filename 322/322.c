/*	2020-06-06 杭州 先暴力解一遍，提交不能通过*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX ((1 << 31) - 1)

int min(int a,int b)
{
	return a<b?a:b;
}

//1.先暴力解一遍
void insertsort(int *a,int num)
{
	int tmp = 0;
	for (int i = 1; i < num;i++)
	{
		if (a[i] < a[0])
		{
			tmp = a[i];
			for (int j = i; j > 0;j--)
			{
				 a[j] = a[j-1];
			}
			a[0] = tmp;
		}
		else if (a[i] >= a[i-1])
		{
			continue;
		}
		else 
		{
			for (int j = 0; j <=i;j++)
			{
				if (a[i] > a[j])
				{
					continue;
				}
				
				tmp  =a[i];
				
				for (int k = i;k >= j;k--)
				{
					a[k] = a[k-1];
				}
				
				a[j] = tmp;
			}
		}
	}
}


int count;

void helper(int* coins,int start, int target, int cur, int* res) 
{
	count++;
	if (target < 0)
	{
		return;
	}
	
	if (target == 0) 
	{
		*res = min(*res, cur); 
		return;
	}
	
	/*这个for循环的作用类似于对target每次减去一个硬币数组中的一个成员的一次值后的情况的所有情况的遍历，
	这是一个全方位无死角的遍历，所以比我之前只考虑到连续性没考虑到不连续性的情况，是真正的暴力算法。
	*/
	for (int i = start; i >= 0; i--)
	{
		 helper(coins,i,target - coins[i], cur + 1, res);
	}
}

int coinChange(int* coins, int coinsSize, int amount) 
{
	int res = INT_MAX;
	insertsort(coins,coinsSize);
	
	helper(coins,coinsSize-1, amount, 0, &res);
	
	return (res == INT_MAX) ? -1 : res;
}



int main1()
{
	count = 0;//看看递归执行了多少次
	//int coins1[] = {1, 2, 5}, amount = 11;				//count= 63
	int coins[] = {186,419,83,408},amount = 6249;		//count = 35309
	
	int ret = coinChange(coins,sizeof(coins)/sizeof(coins[0]),amount);
	
	printf("%d		count:%d\r\n",ret,count);
	
	return 0;
}

//当使用coins1时，helper共调用了63次，而使用coins时，居然高达35309，这要是在项目中使用，很容易爆栈。
//这个值是受amount影响的，amount越大，执行次数越大，暴力法终究走到了末路！


/*
	总结一下这个暴力思想：
	这个题很好，提升了我面对此类问题不能去全面考虑的能力！
	
	应该很好的理解这是怎么样将所有的情况都考虑进去的。
	
	首先，根据题目求的最小硬币数，我们直接可以知道，使用面额amount,去与较大的硬币们取模，就能得到最少的硬币数。
	
	
	1.要是与当前某一个较大的硬币值刚好取模后amount=0，那么我们很直接的得到最少的硬币数，但是这只是个例的情况下得到的情况，
	必定有很多的情况，不能直接由一个较大的硬币面值得到，所以要通过不同的硬币值组合得到解(包括解以及最优解)
	，所以，在遍历的过程中，还要用当前解与最优解比较，更新最优解。
	
	2.如何得到不同硬币值构成的最少硬币数的组合呢？那就是，先与硬币值数组中的最大值(小雨等于amount的硬币值数组中最大的硬币值)，
	求得最少硬币数(此时也不代表这个硬币值就能形成解)，
	若是不能使得amount=0，那么我们就用剩余要组合的amount，在新的硬币值中寻求下一个解。
	下一个当然是硬币值数组中的次大值，就按这样的逻辑，我们可以知道从当前值到最后的结果形成的这条路线，是否走的通？(是否是解)
	
	3.若是走不通，我们就返回上一步(这就是回溯？),在上一步的基础上跨一步继续按照规则执行，寻找解。
	
	4.这样，我们只相对当前位置，沿着”最近“的路一步一步地走，走不通我们就回到上一步，走第二条近的路。
	
	5.这样，我们不会错过任何一条路，这就是暴力法，但是，不会错过任何一条路的代价是巨大的。
	
	6.这题可以增加我们对问题的解的全面考虑，在全面考虑的此基础上，将那些不需要的解提前剪枝，不用再走，从而就能在一个小范围内寻求最优解。
	
*/



//2.非暴力的理解
int coinChange2(int *coins,int coinsSize, int amount) 
{
	//初始化记忆数组
	int *dp = (int *)malloc(sizeof(int)*(amount+1));
	memset(dp,-1,sizeof(int)*(amount+1));
	dp[0] = 0;
	for (int i = 1;i < amount+1;i++)
	{
		
		dp[i] = amount+1;
	}
	
	for (int i = 0; i < coinsSize;i++)//做优化，提前将那些一定最优的dp[x]计算出来
	{
        if (coins[i] <= amount)
        {
		    dp[coins[i]] = 1;
        }
	}
	
	for (int i = 1; i <= amount; i++)//我们计算出每一个dp[i]，达到自底向上的目的,一定要从1开始，因为我们只能从底向上推，反之，我们要都知道顶了，那么我们干嘛还要继续计算
	{
		for (int j = 0; j < coinsSize; j++)//此for循环，不断计算dp[i]的值，直至最优
		{
			if (coins[j] <= i) 
			{
				dp[i] = min(dp[i], (dp[i - coins[j]] + 1));
			}
		}
	}
	
	return (dp[amount] > amount)?-1:dp[amount];
}

int main()
{
	//int coins[] = {5,2,1}, amount = 11;	
	int coins[] = {186,419,83,408},amount = 6249;
	int ret = coinChange2(coins,sizeof(coins)/sizeof(coins[0]),amount);
	printf("%d\r\n",ret);
	
	return 0;
}

/* 

1.状态方程的理解
dp[i] = min(dp[i], (dp[i - coins[j]] + 1));

dp[i]，即构成面值i的最少硬币数，那么，其实我们还可以计算一下，dp[i-coins[j]]+1的值，看它和dp[i]比起来，谁更小？

当然首先我们要保证i>coins[j]才能进行如此计算。

2.为什么内循环(for(int j = 0; j < coinsSize; j++))能计算出最优的dp[i]?

因为，对于coins数组来说，它肯定是固定的，那么dp[coins[x]] = min(dp[coins[x]],dp[coins[x] - coins[x]]+1).
是一定可以知道==1的，
也就是说，dp[coins[x]]的最优解是一定等于1的，这个从题目要求就可以知道，即使我们一开始将dp[coins[x]]赋值为！=1，
在内循环中，会逐步地将最优的值求出来。

由以上结果可以看出，不仅计算出了dp[amount],而且将dp[0]~dp[amount]的值全部计算出来了。那么，这也是一个再次可以做计算速度的优化点。

(优化步骤如152line~158)

3.第一个for循环从1开始的必要性:因为我们只能从底向上推，反之，我们要都知道顶了，那么我们干嘛还要继续计算?
我们是由已知推未知，而已知是由coins数组决定的,也就是说，coins[]有几个成员，就有几个dp[coins[x]]=1,再加上一个dp[0]=0。
且dp[i]中的i必须小于等于amount,也即是coins[x]<=amount的coins成员才成立。

*/
















