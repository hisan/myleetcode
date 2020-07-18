#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a,int b)
{
	return a>b?b:a;
}

int minimum_price(int *days,int daySize,int *costs,int costSize)
{
	int maxday = days[daySize-1];
	int cs1,cs2,cs3;
	int *dp = malloc(sizeof(int)*(1+maxday));
	memset(dp,0,sizeof(int)*(1+maxday));
	
	for (int i = 0; i < daySize;i++)
	{
		dp[days[i]] = -1;
	}
	
	for (int i = 1; i <= maxday;i++)
	{
		if (dp[i] == 0)
		{
			dp[i] = dp[i-1];
		}
		else 
		{
			cs1 = dp[i-1] + costs[0];
			
			if (i >= 7)
			{
				cs2 = dp[i-7] + costs[1];
			}
			else
			{
				cs2 = costs[1];
			}
			
			if (i >= 30)
			{
				cs3 = dp[i-30] + costs[2];
			}
			else 
			{
				cs3 = costs[2];
			}
			
			dp[i] = min(cs3,min(cs2,cs1));
		}
	}
	
	return dp[days[daySize-1]];
}

int main()
{
	int days[] = {1,2,3,4,5,6,7,8,9,10,30,31};
	int costs[] = {2,7,15};
	int ret = minimum_price(days,sizeof(days)/sizeof(int),costs,sizeof(costs)/sizeof(int));
	
	printf("%d\r\n",ret);
	
}
	return ret;