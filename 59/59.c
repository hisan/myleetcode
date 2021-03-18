/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int i = 0;
    int up = 0,down = n-1,left = 0,right = n-1;
    int cur_num = 1;
    int *colsize = (int *)malloc(sizeof(int)*n);
    int **res = (int **)malloc(sizeof(int *)*n);
    for (i = 0; i < n;i++)
    {
        res[i] = (int *)malloc(sizeof(int)*n);
        colsize[i] = n;
    }
    
    *returnSize = n;
    *returnColumnSizes = colsize;

    while (1)
    {
        for (i = left; i <= right;i++)
        {
            res[up][i] = cur_num;
            cur_num += 1;
        }

        up +=1;
        if (up > down)
        {
            break;
        }

        for (i = up;i <= down;i++)
        {
            res[i][right] = cur_num;
            cur_num +=1;
        }

        right -=1;
        if (left > right)
        {
            break;
        }

        for (i = right;i >= left;i--)
        {
            res[down][i] = cur_num;
            cur_num += 1;
        }

        down -= 1;
        if (up > down)
        {
            break;
        }

        for (i = down;i >= up;i--)
        {
            res[i][left] = cur_num;
            cur_num += 1;
        }

        left += 1;
        if (left > right)
        {
            break;
        }
    }

    return res;
}
