/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize)
{    
    int size = pow(2,n);
    int *res = (int *)malloc(sizeof(int)*size);
    *returnSize = 0;
    int i = 0;
    for (i = 0; i < size; i++) 
    {
        res[i] = (i >> 1) ^ i;
    }

    *returnSize = i;
    return res;
}

#if 0
格雷编码：
	计算一个数的格雷编码：
	num = (num >> 1) ^num;
#endif 
