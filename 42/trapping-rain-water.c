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
    for (int i = 1 ; i < heightSize;i++)
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
        while (left < max_pos && height[left] <= height[left+1])
        {
            left++;
        }
		
		if (left == max_pos)
		{
			break;
		}
		
        LR = left+1;
        
		while (LR <= max_pos && height[LR] < height[left])//找到下一堵墙,使得能积水
        {
            LR++;
        }
		
        for (int k = left;k <= LR;k++)
        {
            if (height[k] > min(height[left],height[LR]))
            {
                wall_size += min(height[left],height[LR]);
            }
            else 
            {
                wall_size += height[k];
            }
        }
		
        all_height_l += (LR - left+1)*min(height[LR],height[left]) - wall_size;
		
		printf("wall_size: %d,all_height_l:%d\n",wall_size,all_height_l);
		
        left = LR;
		wall_size = 0;
    }

	printf("\n\n############################right#################################\n");
	
    int RL;
    int all_height_r = 0;
    while (max_pos < right)
    {
        while (right > max_pos && height[right - 1] >= height[right])
        {
            right--;
        }

		if (right == max_pos)
		{
			break;
		}
		
        RL = right-1;
		
        while (RL >= max_pos && height[RL] < height[right])
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

