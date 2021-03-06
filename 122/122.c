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
1.你可以尽可能地完成更多的交易（多次买卖一支股票）。
2.你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票)
*/