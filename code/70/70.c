
//动态规划题目：爬楼梯 2019-09-23
int climbStairs(int n){
    int dp[500] = {0};
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	return dp[n];
}

/*动态规划的含义解释：最优化原理
求解 决策过程中最优化 的数学方法：利用各阶段之间的关系，逐个求解。最终得到全局最优解。

注意:在设计动态规划算法时，需要确认原问题与子问题】、动态规划状态、边界状态结值、状态转移方程等关键因素。
*/
