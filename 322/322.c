
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
    //1.��������
    bubblesort(coins,coinsSize);
    
    //2.��<=�ܽ�������ҿ�ʼ������ͨ��ʹ���ܽ��Ըý������ģ�������¼���
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
    
    //3.����ǰ�����ģ�����¼��㣬�ò����ܽ���ص��ʼ�����¸���ҿ�ʼ��������
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