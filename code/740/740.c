//2020-06-13 23:07 ����  ͨ��
#include <stdio.h>
int max(int a,int b)
{
	return a<b?b:a;
}

int deleteAndEarn(int* nums, int numsSize)
{
	int sums[10001] = {0};
	int take = 0,skip = 0;
	
	for (int i = 0; i < numsSize;i++)
	{
		sums[nums[i]] += nums[i];//��ͳ��ÿ�����ֵ����ֵ
	}
	
	for (int i = 0; i < 10001; i++)
	{
		int takei = sums[i] + skip;//(�ڴ�ǰ���������ֵĻ�����)���������˵�ǰ�������ܵõ����־��ǵ�ǰ���ֵĻ���sums[i]���ټ��ϲ���ǰ��������ܵõ��Ļ���
		int skipi = max(skip,take);//���õ�ǰ�����֣���ôǰ����������ǿ��ÿɲ��ã����Բ��õ�ǰ���ֵ�������==max(��ǰ������ֵĻ��֣�����ǰ������ֵĻ���)
		take = takei;
		skip = skipi;
	}
	
	return max(skip,take);
}

int main()
{
	//int nums[] = {2, 2, 3, 3, 3, 4};
	int nums[] = {3, 4, 2};
	
	int ret = deleteAndEarn(nums,sizeof(nums)/sizeof(nums[0]));
	printf("%d\r\n",ret);
	
}