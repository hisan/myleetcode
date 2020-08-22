/* 2020-06-09 23:31 杭州 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
void insertsort(int* a, int pricesSize)
{
    for ( int i =1;i < pricesSize;i++)
    {
        if (a[i] < a[0])
        {
            int tmp = a[i];
            for (int j = i;j>=1;j--)
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
            int tmp = a[i];
            for(int j = 1;j < i;j++)
            {
                if (a[i] >= a[j])
                {
                    continue;
                } 
                else 
                {
                    int tmp = a[i];
                    for (int k=i;k>=j;k--)
                    {
                        a[k] = a[k-1];
                    }
                    a[j] = tmp;
                }
            }
        }
    }
}

insertsort(a,sizeof(a)/sizeof(a[0]));
for (int j = 0; j < sizeof(a)/sizeof(a[0]);j++)//此for循环，不断计算dp[i]的值，直至最优
{
	printf("%d\r\n",a[j]);
}

#endif 


int max(int a,int b)
{
	return a<b?b:a;
}

/*
分析：要求解最大的收益，这个最大的收益，它指不定哪天买了就达成了，
所以我们只需要求出每一天卖出时的收益，然后在这个过程中，不断更新最大值的情况
我们假设dp[i]为第i天卖出股票时候的最大收益,则它可能由前一天卖出的最大收益sold[i-1]，
或者是前一天持有的收益加上今天卖出后的收益==prices[i]-fee构成。
即，sold[i] = max(sold[i-1],hold[i-1] + prices[i]-fee);
*/

int maxProfit(int* prices, int pricesSize, int fee)
{
	int *sold = (int *)malloc(sizeof(int)*(pricesSize));
	memset(sold,0,sizeof(int)*(pricesSize));
	
	int *hold = (int *)malloc(sizeof(int)*(pricesSize));
	memset(hold,0,sizeof(int)*(pricesSize));
	hold[0] = -prices[0];//第一天买了未卖，赔了prices[0]的钱
	
	//由于很严格，你要i天买，那么你必然要i-1卖出股票，所以只能逐天计算
	for (int i = 1;i < pricesSize;i++)
	{
		sold[i] = max(sold[i-1],hold[i-1]+prices[i]-fee);//明天卖掉的收益等于：今天卖掉的收益，或者今天继续持有明天卖掉的收益
        hold[i] = max(hold[i-1],sold[i-1] - prices[i]);//明天持有的收益等于：今天不买继续持有的收益，或者今天卖掉的收益减去明天买入的消耗
	}
	
	return sold[pricesSize-1];//这个值并不是说一定最后一天卖掉收益最高，记住，这个值是我们不断通过max得到的，不具有"平稳性"。
}


int main()
{
	int prices[] = {1, 3, 2, 8, 4, 9};
	int pricesSize = sizeof(prices)/sizeof(prices[0]);
	int fee  = 2;
	int ret = maxProfit(prices,pricesSize,fee);
	printf("%d\r\n",ret);
}


