/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int i = 0;
    int *res = (int *)malloc(sizeof(int)*100000);
    memset(res,0,sizeof(int)*100000);
    res[0] = 0;
    *returnSize = 1;
    
    for (i = 1; i <= num;i++)
    {
        if (i%2==0)
        {
            res[i] = res[i/2];
        }
        else 
        {
            res[i] = res[i-1] + 1;
        }

        (*returnSize) += 1;
    }

    return res;
}
