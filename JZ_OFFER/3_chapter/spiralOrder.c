/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int up = 0;
    int down = matrixSize-1;
    int left = 0;
    int right = *matrixColSize -1;

    int count = 0;
    int num = matrixSize*(*matrixColSize);

    int *res = (int *)malloc(sizeof(int)*num);

    printf("up:%d down:%d left:%d right:%d\n",up,down,left,right);
    
    while (count < num)
    {
        for (int i = left;i <= right;i++)
        {
            res[count++] = matrix[up][i];
        }
        up++;

        for (int j = up;j <= down;j++)
        {
            res[count++] = matrix[j][right];
        }
        right--;

        for (int j = right;j >= left;j--)
        {
            res[count++] = matrix[down][j];
        }
        down--;

        for (int j = down;j >= up;j--)
        {
            res[count++] = matrix[j][left];
        }
        left++;
    }

    *returnSize = count;
    return res;
}
