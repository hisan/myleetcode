
int* countBits(int num, int* returnSize){
    
    int *retarray = (int*)malloc(sizeof(int)*(1+num));
    int x = 0;
    int i;
    memset(retarray,0,sizeof(int)*(1+num));
    for (i = 0 ;i <= num;i++)
    {
        x = i;
        while(x)
        {
            retarray[i]++;
            x = x & (x-1);
        }
        
    }
    
    *returnSize = (1+num);
    
    return retarray;
}

