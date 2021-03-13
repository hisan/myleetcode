bool isPowerOfFour(int n){
    int num = 0;
    int times = 0;
    while (n>0)
    {
        if ((n&1) == 0)//0的个数
        {
             times++;
        }
        else//1的个数
        {
            num+=1;
        }
        n >>= 1;
    }
    if ( num == 1 && times %2 == 0)//num等于1判断是否为2的幂,times为偶数，说明n的二进制中0的个数为偶数，那么就满足4^x = 2^2^y ，既x为偶数
    {
        return true; 
    }

    return false;
}
