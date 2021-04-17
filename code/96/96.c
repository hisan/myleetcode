/*
2020-08-09 12:22 杭州 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numTrees(int n)
{
    if (n <=1)
    {
        return 1;
    }

    int *dp = malloc(sizeof(int)*(n+1));
    memset(dp,0,sizeof(int)*(n+1));
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3;i <=n;i++)
    {
        for (int j = i-1;j>=0;j--)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

int main()
{
	int n = getchar() - 48;
	printf("ret:%d\r\n",numTrees(n));
	return 0;
}

/*
对于n来说，1,2...n,都可以做二叉搜索树的顶点，则dp[n]为n作为树顶点时的二叉搜索树的个数，
而对于顶点i,求dp[i],则等于左右子树构成的二叉搜索树的乘积。所以可以进行穷举，
在限定i为二叉搜索树的顶点后，同时按照二叉搜索树的定义可以确定左右子树的节点集，所以，
可以分别在这两个集里面分别使每一个结点作为子树的顶点，于是解题步骤就很明确了。



*/

