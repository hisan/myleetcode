#include <stdio.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int getmin(int *prices,int size)
{
    int i = 0;
    int tmp = 0;
	tmp = prices[0];
	for (i=1;i<size;i++)
	{
        if (prices[i] < tmp)
        {
            tmp = prices[i];
        }
	}

    return tmp;
}

int maxProfit(int* prices, int pricesSize)
{
    int dp[200000] = {0};
    int i = 0;
    int tmp = 0;
    dp[0] = 0;
    dp[1] = 0;

    if (pricesSize == 1)
    {
        return 0;
    }

    tmp = prices[0];
    for (i = 2;i <= pricesSize;i++)
    {
        //tmp = getmin(prices,i-1);//这里每一次都求的话显然没有必要且重复计算，导致超时
        tmp = min(tmp,prices[i-1]);
		printf("%d\n",tmp);
        dp[i] = max(dp[i-1],prices[i-1] - tmp);
    }

    return dp[pricesSize];
}

int main()
{
	int prices[] = {7,1,5,3,6,4};
	int pricesSize = sizeof(prices)/sizeof(int);
	int ret = maxProfit(prices,pricesSize);
	
	printf("%d\n",ret);
	return 0;
}