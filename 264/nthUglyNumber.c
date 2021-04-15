
int min(int a,int b)
{
    return a >b?b:a;
}

int nthUglyNumber(int n){
    int ret[2000] = {0};
    int idx = 0;
    ret[idx++] = 1;
    
    int v1 = 0,v2 = 0,v3 = 0;
    int idx1 = 0,idx2 = 0,idx3 = 0;

    for (int i = 1;i <=n;i++)//每一个数乘以2，3，5,都得到一个丑数，取其中最小的一个插入结果数组中
    {
        v1 = ret[idx1]*2;
        v2 = ret[idx2]*3;
        v3 = ret[idx3]*5;

        ret[idx++] = min(v1,min(v2,v3));

        if (ret[idx-1] == v1) ++idx1;
        if (ret[idx-1] == v2) ++idx2;
        if (ret[idx-1] == v3) ++idx3;
    }

    return ret[n-1];
}

