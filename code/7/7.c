
int reverse(int x)
{
    int y = 0;
    while (x != 0)
    {
        int n = x % 10;
        if (y > INT_MAX / 10 || y < INT_MIN / 10)
        {//这个范围是一个简单的数学不等式推论出来的，就是避免在进行 y = y * 10 + n时数字溢出，所以要提前判断
            return 0;
        }
        y = y * 10 + n;
        x /= 10;
    }
    return y;
}

//#define INT_MAX 2^31-1  //32位数表示的最大正整数
//#define INT_MIN -2^31     //....
//因为  y = y * 10 + n 很容易造成数值溢出，所以我们为了保证不溢出，要提前使得  y = y * 10 + n <=INT_MAX  ==> y<=(INT_MAX -n)/10,
//负数同理。
