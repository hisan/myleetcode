#include <stdio.h>

//接雨水
int min(int a,int b)
{
    return a>b?b:a;
}

int trap(int* height, int heightSize){
	
	if(heightSize <= 2)
    {
        return 0;
    }
	
    int left = 0;
    int right = heightSize - 1;

    int max_high = height[0];
    int max_pos = 0;
    for (int i = 1 ; i < heightSize;i++)//找到峰值最高的点，以它为标志点，从两边开始向它靠拢，因为我们知道它一定是一面合格的水池的墙
    {
        if (max_high < height[i])
        {
            max_pos = i;
            max_high = height[i];
        }
    }//得到最高长度及其坐标

	printf("############################left#################################\n");
	
    int LR;
    int all_height_l = 0;
    int wall_size = 0;
    while (left < max_pos)
    {
        while (left < max_pos && height[left+1] >= height[left])//找到能蓄水的池子的左墙 |__|
        {
            left++;
        }                                     
        
        #if 0
                              |
                            |||
		   说明都是这种情况||||
        #endif

        if (left == max_pos)
		{
			break;
		}
		
        LR = left+1;//最终找到一堵比左墙矮的墙
        
		while (LR <= max_pos && height[LR] < height[left])//找到下一堵墙,使之得能积水
        {
            LR++;
        }
		
		//以下是计算积水面积的公式，我们先计算出左右两面墙之间的墙体占的体积
        for (int k = left;k <= LR;k++)
        {
            if (height[k] > min(height[left],height[LR]))//以两面墙的最小值来计算
            {
                wall_size += min(height[left],height[LR]);
            }
            else 
            {
                wall_size += height[k];
            }
        }
		
		//(LR - left+1)*min(height[LR],height[left])，左右墙形成的矩形，面积为两面墙的宽乘高（左右两高的较小高）
        all_height_l += (LR - left+1)*min(height[LR],height[left]) - wall_size;//再减去实体墙占的空间，就得到水的面积
		
		printf("wall_size: %d,all_height_l:%d\n",wall_size,all_height_l);
		
        left = LR;
		wall_size = 0;
    }

	printf("\n\n############################right#################################\n");
	
    int RL;
    int all_height_r = 0;
    while (max_pos < right)
    {
        while (right > max_pos && height[right - 1] >= height[right])//这里right>max_po是对应height[right - 1] >= height[right]，right>max_po保证了right-1>=max_pos
        {
            right--;
        }

		if (right == max_pos)
		{
			break;
		}
		
        RL = right-1;
		
        while (RL >= max_pos && height[RL] < height[right])//我们知道max_pos一定为合格的墙，所以RL可以等于max_pos,当它等于max_pos时说明它是最后一个洼地
        {
            RL--;
        }
		
		for (int k = RL;k <= right;k++)
        {
            if (height[k] > min(height[right],height[RL]))
            {
                wall_size += min(height[right],height[RL]);
            }
            else 
            {
                wall_size += height[k];
            }
        }
		
		all_height_r += (right - RL+1)*min(height[RL],height[right]) - wall_size;
	    printf("wall_size: %d,all_height_r:%d\n",wall_size,all_height_r);
	   
		right = RL;
		wall_size = 0;
    }

    return all_height_r + all_height_l;
}

int main()
{
	//int height[] = {4,2,0,3,2,5};
	//int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	//int height[] = {0,2,0};								//ok 
	//int height[] = {4,2,0,3,2,5,4,2,0,3,4};
	
	int height[] = {4,2,0};
	
	int heightSize = sizeof(height)/sizeof(height[0]);
	int ret = trap(height,heightSize);
	printf("\n\n\nresult:%d\n",ret);
	return 0;
}


#if 0  //默写
int min(int a,int b)
{
    return a>b?b:a;
}

int trap(int* height, int heightSize)
{
	int i = 0,j = 0;
	int left = 0;
	int right = heightSize - 1;
	
	if (heightSize <= 2)
	{
		return 0;
	}
	
	int LR = 0,RL = 0;
	int wallsize = 0;
	int L_HEIGHT = 0,R_HEIGHT = 0;
	
	int max_pos = 0;
	int tmp = height[0];
	
	for (i = 1;i < heightSize;i++)
	{
		if (tmp <= height[i])
		{
			tmp = height[i];
			max_pos = i;
		}
	}
	
	while (left < max_pos)
	{
		while (left < max_pos && height[left+1] >= height[left])
		{
			left++;
		}
		
		if (left == max_pos)
		{
			break;
		}
		
		LR = left + 1;
		
		while (LR <= max_pos && height[LR] < height[left])
		{
			LR++;
		}
		
		for (j = left;j<=LR;j++)
		{
			if (height[j] > min(height[left],height[LR]) )
			{
				wallsize  += min(height[left],height[LR]);
			}
			else 
			{
				wallsize += height[j];
			}
		}
		
		L_HEIGHT += (LR - left +1 )*min(height[left],height[LR]) - wallsize;
		wallsize = 0;
		left = LR;
	}
	
	while (right > max_pos)
	{
		while (right > max_pos && height[right] <= height[right-1])
		{
			right--;
		}
		
		if (right == max_pos)
		{
			break;
		}
		
		RL = right - 1;
		while (RL >= max_pos && height[RL] < height[right])
		{
			RL--;
		}
		
		for (j = RL;j<=right;j++)
		{
			if (height[j] > min(height[right],height[RL]) )
			{
				wallsize  += min(height[right],height[RL]);
			}
			else 
			{
				wallsize += height[j];
			}
		}
		
		R_HEIGHT += (right - RL +1 )*min(height[right],height[RL]) - wallsize;
		wallsize = 0;
		right = RL;
	}
	
	return L_HEIGHT + R_HEIGHT;
}
#endif 

