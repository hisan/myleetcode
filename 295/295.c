//2020-02-24 ��ʱ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nodenum;
    double *nums;
} MedianFinder;

/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder *pmedianhead = (MedianFinder*)malloc(sizeof(MedianFinder));
    memset(pmedianhead,0,sizeof(MedianFinder));
    return pmedianhead;
}

void insertsort(double *a,int size)
{
	if (a == NULL || size == 0)
	{
		return ;
	}
	
	int i = 0,j = 0,k = 0;
	double tmp = 0;
	for (i=1;i < size;i++)
	{
		if (a[i] < a[0])//����ǰ��������С�ڵ��������������еĵ�һ�������򽫵�ǰ���������в���Ϊ�������еĵ�һ����
		{
			tmp = a[i];
			for (j = i ; j >=1;j--)//���������е���ȫ��������һ��λ��
			{
				a[j] = a[j-1];
			}
			a[0] = tmp;
		}
		else if(a[i] >= a[i-1])//ֱ�Ӳ�����β��
		{
			continue;
		}
		else 
		{
			for (j = 0;j <=i;j++)//Ѱ�Ҳ���λ��:����ǰ�������жϣ��������λ��һ��������������
			{
				if (a[i] > a[j])
				{
					continue;
				}
				
				tmp = a[i];
				for (int k = i;k >= j;k--)
				{
					a[k] = a[k-1];
				}
				a[j] = tmp;
			}
		}
	}
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if(obj == NULL)
    {
        return;
    }
    
    obj->nums = (double*)realloc( obj->nums,sizeof(double)*( obj->nodenum+1));
    obj->nums[obj->nodenum++] = num;
    insertsort(obj->nums,obj->nodenum);
}

double medianFinderFindMedian(MedianFinder* obj) {

    if (obj->nodenum == 1)
    {
        return obj->nums[0];
    }
    if ( obj->nodenum % 2 == 0)
    {
        return (obj->nums[obj->nodenum/2 - 1] + obj->nums[obj->nodenum/2]) / 2;
    }
    else 
    {
        return obj->nums[obj->nodenum/2];
    }
}

void medianFinderFree(MedianFinder* obj) {
    if(obj == NULL)
    {
        return ;
    }
    
    if(obj->nums!=NULL)
    {
        free(obj->nums);
    }
    
    if(obj!=NULL)
    {
        free(obj);
    }
}

int printarray(double *g,int size)
{
	int i = 0;
	printf("after sort:	");
	for (i = 0; i < size-1;i++)
	{
		printf("%f,",g[i]);
	}
	printf("%f,",g[size-1]);
	return 0;
}

int main()
{
	MedianFinder *p = medianFinderCreate();
	double ret = 0;
	medianFinderAddNum(p,6);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,10);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,2);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,6);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,5);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,0);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,6);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,3);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,1);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,0);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	medianFinderAddNum(p,0);
	ret = medianFinderFindMedian(p);
	printarray(p->nums,p->nodenum);
	printf("	ret: %f\r\n",ret);
	
	return 0;
}








