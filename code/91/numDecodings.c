int max(int a,int b)
{
    return a>b?a:b;
}

int numDecodings(char * s){
    int len = strlen(s);
    if (len <=0 || s[0] == '0')
    {
        return 0;
    }

    int dp[101] = {0};
    dp[0] = 1;
    for (int i = 1; i <= len;++i)
    {
        dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];//若当前字符为0,则当前字符为右边界的字符的组合数一定没有新变化，为啥？因为它不能依靠自己，只能寄希望于前一个字符是否能带它一起玩（"s[i-1][i]"组成一个数：这个数可能为00,10,20,..60,只有10,20,是合格的)
        //若当前字符为不0,则它至少可以单独加入前面的组合中，即，dp[i]的组合数至少和dp[i-1]的组合数是相等的

        //其次，除了字母的方式，还有和前面一个字母组合的方式，只要组合不是01,02...这种非法的方式，都算是一种组合，
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            dp[i] += dp[i-2];
        }
    }

    return dp[len];
}
