int maxProfit(int* prices, int pricesSize){
    int max = 0;
    for (int i = pricesSize-1;i > 0 ;i--)
    {
        if (prices[i] > prices[i-1])
        {
            max += prices[i] - prices[i-1];
        }
    }

    return max;
}

/*
1.����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
2.�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ)
*/