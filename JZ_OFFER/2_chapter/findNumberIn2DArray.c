bool findtarget(int **matrix,int left,int right,int target)
{
    if (target == matrix[left][right])
    {
        return true;
    }
    else if (target < matrix[left][right])
    {
        
        return findtarget(matrix,left,right-1,target);

    }
    else 
    {
         return findtarget(matrix,left+1,right,target);
    }

    return false;
}

bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    int n = *matrixColSize;
    findtarget(matrix,0,n-1,target);
    return false;
}

int main()
{
	
}