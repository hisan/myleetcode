/*	2020-06-06 ���� �ȱ�����һ�飬�ύ����ͨ��*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX ((1 << 31) - 1)

int min(int a,int b)
{
	return a<b?a:b;
}

//1.�ȱ�����һ��
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
	
	/*���forѭ�������������ڶ�targetÿ�μ�ȥһ��Ӳ�������е�һ����Ա��һ��ֵ����������������ı�����
	����һ��ȫ��λ�����ǵı��������Ա���֮ǰֻ���ǵ�������û���ǵ��������Ե�������������ı����㷨��
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
	count = 0;//�����ݹ�ִ���˶��ٴ�
	//int coins1[] = {1, 2, 5}, amount = 11;				//count= 63
	int coins[] = {186,419,83,408},amount = 6249;		//count = 35309
	
	int ret = coinChange(coins,sizeof(coins)/sizeof(coins[0]),amount);
	
	printf("%d		count:%d\r\n",ret,count);
	
	return 0;
}

//��ʹ��coins1ʱ��helper��������63�Σ���ʹ��coinsʱ����Ȼ�ߴ�35309����Ҫ������Ŀ��ʹ�ã������ױ�ջ��
//���ֵ����amountӰ��ģ�amountԽ��ִ�д���Խ�󣬱������վ��ߵ���ĩ·��


/*
	�ܽ�һ���������˼�룺
	�����ܺã�����������Դ������ⲻ��ȥȫ�濼�ǵ�������
	
	Ӧ�úܺõ����������ô�������е���������ǽ�ȥ�ġ�
	
	���ȣ�������Ŀ�����СӲ����������ֱ�ӿ���֪����ʹ�����amount,ȥ��ϴ��Ӳ����ȡģ�����ܵõ����ٵ�Ӳ������
	
	
	1.Ҫ���뵱ǰĳһ���ϴ��Ӳ��ֵ�պ�ȡģ��amount=0����ô���Ǻ�ֱ�ӵĵõ����ٵ�Ӳ������������ֻ�Ǹ���������µõ��������
	�ض��кܶ�����������ֱ����һ���ϴ��Ӳ����ֵ�õ�������Ҫͨ����ͬ��Ӳ��ֵ��ϵõ���(�������Լ����Ž�)
	�����ԣ��ڱ����Ĺ����У���Ҫ�õ�ǰ�������Ž�Ƚϣ��������Ž⡣
	
	2.��εõ���ͬӲ��ֵ���ɵ�����Ӳ����������أ��Ǿ��ǣ�����Ӳ��ֵ�����е����ֵ(С�����amount��Ӳ��ֵ����������Ӳ��ֵ)��
	�������Ӳ����(��ʱҲ���������Ӳ��ֵ�����γɽ�)��
	���ǲ���ʹ��amount=0����ô���Ǿ���ʣ��Ҫ��ϵ�amount�����µ�Ӳ��ֵ��Ѱ����һ���⡣
	��һ����Ȼ��Ӳ��ֵ�����еĴδ�ֵ���Ͱ��������߼������ǿ���֪���ӵ�ǰֵ�����Ľ���γɵ�����·�ߣ��Ƿ��ߵ�ͨ��(�Ƿ��ǽ�)
	
	3.�����߲�ͨ�����Ǿͷ�����һ��(����ǻ��ݣ�),����һ���Ļ����Ͽ�һ���������չ���ִ�У�Ѱ�ҽ⡣
	
	4.����������ֻ��Ե�ǰλ�ã����š��������·һ��һ�����ߣ��߲�ͨ���Ǿͻص���һ�����ߵڶ�������·��
	
	5.���������ǲ������κ�һ��·������Ǳ����������ǣ��������κ�һ��·�Ĵ����Ǿ޴�ġ�
	
	6.��������������Ƕ�����Ľ��ȫ�濼�ǣ���ȫ�濼�ǵĴ˻����ϣ�����Щ����Ҫ�Ľ���ǰ��֦���������ߣ��Ӷ�������һ��С��Χ��Ѱ�����Ž⡣
	
*/



//2.�Ǳ��������
int coinChange2(int *coins,int coinsSize, int amount) 
{
	//��ʼ����������
	int *dp = (int *)malloc(sizeof(int)*(amount+1));
	memset(dp,-1,sizeof(int)*(amount+1));
	dp[0] = 0;
	for (int i = 1;i < amount+1;i++)
	{
		
		dp[i] = amount+1;
	}
	
	for (int i = 0; i < coinsSize;i++)//���Ż�����ǰ����Щһ�����ŵ�dp[x]�������
	{
        if (coins[i] <= amount)
        {
		    dp[coins[i]] = 1;
        }
	}
	
	for (int i = 1; i <= amount; i++)//���Ǽ����ÿһ��dp[i]���ﵽ�Ե����ϵ�Ŀ��,һ��Ҫ��1��ʼ����Ϊ����ֻ�ܴӵ������ƣ���֮������Ҫ��֪�����ˣ���ô���Ǹ��ﻹҪ��������
	{
		for (int j = 0; j < coinsSize; j++)//��forѭ�������ϼ���dp[i]��ֵ��ֱ������
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

1.״̬���̵����
dp[i] = min(dp[i], (dp[i - coins[j]] + 1));

dp[i]����������ֵi������Ӳ��������ô����ʵ���ǻ����Լ���һ�£�dp[i-coins[j]]+1��ֵ��������dp[i]��������˭��С��

��Ȼ��������Ҫ��֤i>coins[j]���ܽ�����˼��㡣

2.Ϊʲô��ѭ��(for(int j = 0; j < coinsSize; j++))�ܼ�������ŵ�dp[i]?

��Ϊ������coins������˵�����϶��ǹ̶��ģ���ôdp[coins[x]] = min(dp[coins[x]],dp[coins[x] - coins[x]]+1).
��һ������֪��==1�ģ�
Ҳ����˵��dp[coins[x]]�����Ž���һ������1�ģ��������ĿҪ��Ϳ���֪������ʹ����һ��ʼ��dp[coins[x]]��ֵΪ��=1��
����ѭ���У����𲽵ؽ����ŵ�ֵ�������

�����Ͻ�����Կ����������������dp[amount],���ҽ�dp[0]~dp[amount]��ֵȫ����������ˡ���ô����Ҳ��һ���ٴο����������ٶȵ��Ż��㡣

(�Ż�������152line~158)

3.��һ��forѭ����1��ʼ�ı�Ҫ��:��Ϊ����ֻ�ܴӵ������ƣ���֮������Ҫ��֪�����ˣ���ô���Ǹ��ﻹҪ��������?
����������֪��δ֪������֪����coins���������,Ҳ����˵��coins[]�м�����Ա�����м���dp[coins[x]]=1,�ټ���һ��dp[0]=0��
��dp[i]�е�i����С�ڵ���amount,Ҳ����coins[x]<=amount��coins��Ա�ų�����

*/
















