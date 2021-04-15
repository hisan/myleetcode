#include <stdio.h>

int bit1_count(int n)
{
	int num = 0;
	unsigned int mask = 1;
	while (mask)
	{
		if (n & mask)
			num++;
		mask<<=1;
	}

	return num;
}

int main()
{
	int n;
	while (EOF != scanf("%d",&n))
	{
		int ret = bit1_count(n);
		printf("n:%d   bit1:%d\n",n,ret);
	}
	return 0;
}
