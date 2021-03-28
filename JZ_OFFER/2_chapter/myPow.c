#include <stdio.h>

double myPow(double x, int n)
{
	double ret = 1.0;
	
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            ret *= x;
        }

        x *= x;
        n/=2;
    }
	
    return ret;
}

int main()
{
	double x = 0.0;
	int n = 0;					//int	Ϊ4bytes
	short a = 0;				//short	Ϊ2bytes
	float b = 0;				//float	Ϊ4bytes
	char c = 0;					//char	Ϊ1bytes
	double ret = 0.0;			//doubleΪ8bytes
	
	
	
	
	
	
	
	
	
	printf("%d bytes\n",sizeof(c));
	while (EOF != scanf("%f%d",&x,&n))
	{
		ret = myPow(x,n);
		printf("%f\n",ret);
	}
	
	return 0;
}