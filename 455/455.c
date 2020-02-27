
//2019-08-04提交通过
int partition(int *g,int left,int right)
{
    int key = g[left];
    while(left<right)
    {
        while(left<right && g[right] >= key)
        {
            right--;
        }
        g[left] = g[right];
        while(left<right && g[left] <= key)
        {
            left++;
        }
        g[right] = g[left];
    }
    g[left] = key;
    return left;
}

void quicksort(int *g,int left,int right)
{
    if(left < right)
    {
        int pivotloc = partition(g,left,right);
        quicksort(g,left,pivotloc-1);
        quicksort(g,pivotloc+1,right);
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int childsize = 0;//满足的小孩个数
    int i,j;
    int squence = 0;
    quicksort(g,0,gSize-1);
    quicksort(s,0,sSize-1);
    for(i=0;i<gSize;i++)
    {
        for(j= 0;j < sSize;j++)
        {
            if( (s[j] > 0) && (g[i] <= s[j]) )
            {
                childsize++;
                s[j] = 0;
                break;
            }
        }
    }
    return childsize;
}

