#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/zyb/CODE/API/include/aux_api.h"

void bubblesort(int *a,int size)
{
	#if 0
	Ϊʲô��size-1? ��Ϊ������size��Ԫ�أ�����ð������,ֻ��Ҫsize-1�ˣ�����ȷ��size-1��Ԫ�ص�ȷ��λ�á�
	��ʣ�µ��Ǹ�Ԫ�أ�����Ҫ��ȷ���𣿵�Ȼ�ǲ���Ҫ�ˣ��͸�����һ������ȷ��p=30%,��1-p�ѵ�����%70��
	#endif 
	for (int i = 0 ;i < size-1;++i)
	{
		int bswitch = 0;
		
		#if 0
		��ð���������ǿ�֪��ÿһ�ֶ�ȷ��һ����С��Ԫ�أ���ô��һ�ֱȽϵ�ʱ�򣬸���СԪ�ز��ز��������
		���Դ�βԪ�ؿ�ʼ�Ƚϣ�����ȷ��λ�õ�Ԫ��ֹͣ���ɡ�
		#endif
		
		for (int j = size-1;j > i;--j)
		{
			if (a[j-1] > a[j])
			{
				a[j-1] ^= a[j];
				a[j] ^= a[j-1];
				a[j-1] ^= a[j];
				bswitch = 1;
			}
		}
		
		if (bswitch == 0)//����һ��ɨ��û�з�����������˵��������ȫ������
		{
			break;
		}
	}
}


int main()
{
	int g[] = {100,4,6,1,1,12,1,14,43,1234,1231,12};
	int size = sizeof(g)/sizeof(g[0]);
	
	bubblesort(g,size);
	outputarray(g,size);
	return 0;
}