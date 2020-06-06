//2020-0606 ����

#include <stdio.h>
#include <string.h>



//�鲢��˼�룺����·���������������л��ֳ���С�������У��ڽ��й鲢

//�鲢
void merge(int *a,int low,int mid,int high)
{
	int i,j,k,l;
	int b[100] = {0};
	for (l = low; l <= high;l++)//�����������е�ԭʼ�����ȱ�������
	{
		b[l] = a[l];
	}
	
	k = low;//����ֻ�ܱ�֤��������������ֻ�����ǵ���δ����������
	for (i = low,j = mid+1;i <= mid && j <=high;)
	{
		if (b[i] <= b[j])
		{
			a[k] = b[i++];
		}
		else
		{
			a[k] = b[j++];
		}
		k++;
	}
	
	while (i <= mid)
	{
		a[k++] = b[i++];
	}
	
	while (j <= high)
	{
		a[k++] = b[j++];
	}
}

void mergesort(int *a,int low,int high)
{
	int mid = 0;
	if (low < high)
	{
		mid = (low + high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void print_array(int *a,int num)
{
	for (int i = 0 ; i < num;i++)
	{
		printf("%d\r\n",a[i]);
	}
	printf("\r\n");
}

int main()
{
	int a[] = {1,12,1,3,23,56,23,12};
	int num = sizeof(a)/sizeof(a[0]);
	mergesort(a,0,sizeof(a)/sizeof(a[0]) -1);
	print_array(a,sizeof(a)/sizeof(a[0]));
}
