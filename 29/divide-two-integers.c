#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int divide(int dividend, int divisor){
    int sign = (dividend<0)^(divisor<0)==0?1:-1;
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }

    if (dividend == 0)
    {
        return 0;
    }

    if (divisor == 1)
    {
        return dividend;
    }
    long div = labs(dividend);
    long divor = labs(divisor);
    long res = 0;
    while (div >= divor)
    {
        long tmp = divor;
        long p = 1;
        while (div >= (tmp<<1))
        {
            tmp<<=1;
            p<<=1;
        }
        res += p;
        div -= tmp;
    }
    return sign==1?res:-res;
}

int main()
{
	int num = divide(50,3);
	printf("%d\n",num);
	return num;
}
