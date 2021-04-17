class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size <= 1)
        {
            return 0;
        }

        vector<int> sell(size,0);
        vector<int> buy(size,0);
        vector<int> cool(size,0);

        buy[0] = -prices[0];
        for (int i = 1;i <size;++i)
        {
            sell[i] = buy[i-1]+prices[i];
            buy[i] = max(buy[i-1],cool[i-1]-prices[i]);
            cool[i] = max(sell[i-1],cool[i-1]);
        }

        return max(sell[size-1],cool[size-1]);
    }
};
