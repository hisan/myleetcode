#define max(a,b) ((a) > (b)?(a):(b))
#define min(a,b) ((a) < (b)?(a):(b))

int maxArea(int* height, int heightSize){
    int i = 0,j = heightSize - 1;
    int ret = 0;

    while (i < j)
    {
        ret = max(ret,min(height[i],height[j])*(j-i));
        height[i] < height[j]?i++:j--;
    }

    return ret;
}

/*
这种做法没有遍历所有的区间就能得到最大值，为什么呢？

这里用到了动态规划，基本的表达式: area = min(height[i], height[j]) * (j - i) 
使用两个指针，值小的指针向内移动，这样就减小了搜索空间,因为面积取决于指针的距离与值小的值乘积，
如果值大的值向内移动，距离一定减小，而求面积的另外一个乘数一定小于等于值小的值，
因此面积一定减小，而我们要求最大的面积，因此值大的指针不动，而值小的指针向内移动遍历

*/
