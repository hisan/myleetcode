
int bubblesort(int *coins,int coinsSize)
{
    for (int i =  0;i < coinsSize;i++)
    {
        for (int j = i+1;j < coinsSize;j++)
        {
            if (coins[i] > coins[j])
            {
                coins[i] ^= coins[j];
                coins[j] ^= coins[i];
                coins[i] ^= coins[j];
            }
        }
    }
}

int calcnum(int amount,int *coins,int coinsSize,int *nums)
{
	for (int i = 0 ; i < coinsSize;i++)
	{
		if (amount == coins[i])
		{
			dp[amount] = 1;
			return 1;
		}
		
		return 1 + calcnum(amount - coins[i],coins,coinsSize);
	}
	
	return 0;
}

int coinChange(int* coins, int coinsSize, int amount){
    int i = 0,j = 0;
    int tmpcount = 0;
    int num = 0;
    //1.先排序金币
    bubblesort(coins,coinsSize);
    
    //2.从<=总金额的最大金币开始凑数，通过使用总金额对该金币来求模，再往下计算
    for (;i < coinsSize;i++)
    {
        if (coins[i] >= amount)
        {
            if (coins[i] == amount)
            {
                return 1;
            }

            break;
        }
    }
    
    //3.若当前金币求模后往下计算，得不到总金额，则回到最开始，从下个金币开始继续计算
    for (j = i;j >= 0;j--)
    {
        tmpcount = amount;
        num = tmpcount / coins[j];
        tmpcount = tmpcount % coins[j];

        if (tmpcount == 0)
        {
            return num;
        }
        else 
        {

        }
    }
}