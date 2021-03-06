int uniquePaths(int m, int n){
	int i = 0;
	int j = 0;
	int tmp = 0;
	int **dp = (int **)malloc(sizeof(int *)*m);
	
	for (i = 0;i < m;i++)
	{
		dp[i] = (int *)malloc(sizeof(int)*n);
		memset(dp[i],0,sizeof(int)*n);
	}
	
	for (j = 0;j < n;j++)
	{
		dp[0][j] = 1;
	}
	
	for (j = 0;j < m;j++)
	{
		dp[j][0] = 1;
	}
	
	for (i = 1;i < m;i++)
	{
		for (j = 1;j < n;j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
    
	tmp = dp[m-1][n-1];

    for (i = 1;i < m;i++)
	{
		free(dp[i]);
	}
	
	free(dp);
	
	return tmp;
}
