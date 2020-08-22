**************************************//2018-11-17**********（1）*******************************************************************************************
初步思路：先排序后求中位数
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int i,j;
    int n = nums1Size + nums2Size;
    int temp;
    int tempn;
    
    int *num3 = (int*)malloc(sizeof(int)*n);//给数组分配内存
    memset(num3,0,sizeof(num3));
    
    //先排序，将两者合并成一个有序数组
    for (i=0;i < nums1Size;i++)//注意边界条件
    {
        *(num3+i) = *(nums1+i);
    }
    for(j=0;j < nums2Size;j++)//注意边界条件
    {
        *(num3+j+nums1Size) = *(nums2+j);
    }
    
    //合并好后排序，采用冒泡排序法进行排序
    for(j = 0 ;j < n ;j ++)
    {
        for(i = j+1 ; i < n ;i++)//一定要注意边界条件
        {
            temp = *(num3+j);
            tempn = *(num3+i);
            if(temp > tempn)//交换两者的值
            {
                *(num3+j) = tempn;
                *(num3+i) = temp;
            }
        }
    }
    
    //冒泡排序的思想就是:
    /* 将每一轮遍历的第一个元素与第二个元素开始直到最后的元素相比较，
       大于则交换，然后继续比较,要搞清楚的是，换值不换序，我是依据按序来取值比较，
       即使我比较的过程中会交换不同序号上的值，但是我的序号是没有变的
    */
    int up = n/2;
    int test = n%2;
    double num = 0;
    if(test==0)//偶数
    {
        int down  = up -1;
        num = num3[up]+num3[down];
        num = num/2;
        free(num3);
        return num;
    }
    else//奇数
    {
        num = num3[up];
        free(num3);
        return num;
    }
   return 0;
}
//本题目用的是冒泡排序，时间复杂度为T(n^2),空间复杂度为O(m+n);提交居然通过了？？


//第二种做法：边比较变加入第三个数组




