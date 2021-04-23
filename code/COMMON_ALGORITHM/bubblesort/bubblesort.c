#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/zyb/CODE/API/include/aux_api.h"

void bubblesort(int *a,int size)
{
	#if 0
	为什么是size-1? 因为我们有size个元素，按照冒泡排序,只需要size-1趟，就能确定size-1个元素的确切位置。
	那剩下的那个元素，还需要再确定吗？当然是不需要了，就跟概率一样，你确定p=30%,那1-p难道不是%70吗？
	#endif 
	for (int i = 0 ;i < size-1;++i)
	{
		int bswitch = 0;
		
		#if 0
		由冒泡排序我们可知，每一轮都确定一个最小的元素，那么下一轮比较的时候，该最小元素不必参与进来。
		所以从尾元素开始比较，到已确定位置的元素停止即可。
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
		
		if (bswitch == 0)//若上一次扫描没有发生交换，则说明数据已全部有序
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