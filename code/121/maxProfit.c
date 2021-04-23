class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int daynum = prices.size();
        if (daynum <=1)
        {
            return 0;
        }
        
        vector<int>dp(daynum+1,0);
        dp[1] = 0;
        int minprice = prices[0];
        for (int i = 2;i <=daynum;i++)
        {
            minprice = min(prices[i-1],minprice);
            dp[i] = max(dp[i-1],prices[i-1]-minprice);
        }
        
        return dp[daynum];
    }
};
