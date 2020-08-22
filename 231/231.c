
bool isPowerOfTwo(int n){
    if (n == 1 )
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }
   
   if ( n%2 != 0)//若当前数除不尽2，那么它一定不是2的幂。除得尽，则需要进一步判断
   {
       return false;
   }

   return isPowerOfTwo(n/2);
}



bool isPowerOfTwo(int n){
    if (n<=0) return false;
    if ( (n&(n-1)) == 0) return true;
    return false;
}

//这个是个学习bit运算很好的例子
求bit位，其中最好的就是将当前数x与x-1相&或者|得到。



