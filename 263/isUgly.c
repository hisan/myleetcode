int g[3] = {2,3,5};
bool isUglyJudge(int n)
{
    for (int i = 0 ; i < 3;i++)
    {
        if (n%g[i] == 0)
        {
            if (n/g[i] == 1)
            {
                return true;
            }
            return isUglyJudge(n/g[i]);
        }
    }
    return false;
}

bool isUgly(int n){
    if (n == 1)
    {
        return true;
    }

    if (n == 0)//0和1为特殊情况，单独处理
    {
        return false;
    }

    return isUglyJudge(n);
}

