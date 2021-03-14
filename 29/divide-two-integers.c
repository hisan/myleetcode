#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int divide(int dividend, int divisor){
    int res = 0;
    if (dividend == 0)
    {
        return 0;
    }

    if (dividend == INT_MIN && divisor == -1)//此时dividend/divisor = INT_MAX+1
    {
        return INT_MAX;
    }

    int sign = (dividend < 0)^(divisor < 0) == 1?-1:1;//同为0，异为1,判断除数与被除数符号情况
    
    long m = labs(dividend);
    long n = labs(divisor);
    
    if (n == 1)
    {
        return sign == 1?-m:m;
    }

     while (m >= n) 
     {
        long t = n, p = 1;
        while (m >= (t << 1)) {
            t <<= 1;
            p <<= 1;
        }
        res += p;
        m -= t;
    }

    return sign == 1 ? res : -res;
}

int main()
{
	int num = divide(50,3);
	printf("%d\n",num);
	return num;
}
