

//2019-08-06提交通过
typedef struct TreeNode treenode;

void makearray(treenode* root,int* treedim,int** returnColumnSizes,int* colunmnarray,int count,int *returnSize)
{
    int lefttreedim  = 0;
    int righttreedim = 0;
    int basecount = 0;
    int i = 0;
    int tempa  = 0;
    int tempcount = 0;
    int *ptemp = NULL;
    if(root!=NULL)
    {
        if( returnColumnSizes[*treedim] == NULL)
        {//该层遍历尚未开始，则为其分配数组空间，且初始化该维数组的第一个数组元素
            returnColumnSizes[*treedim] = (int*)malloc(sizeof(int)*count);
            memset(returnColumnSizes[*treedim],0,sizeof(int)*count);
            returnColumnSizes[*treedim][0] = root->val;
            colunmnarray[*treedim] = 1;
            (*returnSize) += 1;//数组维度
        }
        else
        {//表明此层的遍历并不是第一次开始
            returnColumnSizes[*treedim][colunmnarray[*treedim]] = root->val;
            colunmnarray[*treedim]++;
        }
        
        (*treedim)++;//树深度增加
        
        lefttreedim = *treedim;
        righttreedim = *treedim;//这是我觉得最精妙的地方，我为了能够使用在下面的左右孩子中递归使用同一个维度（当前树的高度），因此使用两个变量lefttreedim和righttreedim，并作为指针传递下去，这样我每一层的遍历都可以使用指针不同（为了避免维度增加时造成同步）值相同的值来进行

        makearray(root->left,&lefttreedim,returnColumnSizes, colunmnarray,count,returnSize);
        makearray(root->right,&righttreedim,returnColumnSizes,colunmnarray,count,returnSize);
    }
}

int maxnum(int a,int b)
{//两值取最大值
    if(a >= b)
    {
        return a;
    }
    
    return b;
}

int BTDeep(treenode*root)
{//递归计算二叉树的高度
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->left != NULL || root->right != NULL )
    {
        return 1 + maxnum(BTDeep(root->left),BTDeep(root->right));
    }
    
    return 1;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;    
    }
    
    int newcount = 0;
    int **newreturnColumnSizes = NULL;//动态分配的指针数组
    
    int treedeep = BTDeep(root);//计算树的高度
    int  count = 0;
    
    int treedim = 0;
    int *colomun = NULL;
    
    *returnSize = 0;
    
    if(treedeep <= 0)
    {
        return NULL;
    }
    count = 200;//列数
    colomun = (int*)malloc(sizeof(int)*treedeep);//用于存储二维数组的每一维的数组元素个数
    if(colomun == NULL )
    {
        return NULL;
    }
    
    memset(colomun,0,sizeof(int)*treedeep);
    

    newreturnColumnSizes = (int**)malloc(sizeof(int*)*treedeep);
    if(newreturnColumnSizes == NULL )
    {
        return NULL;
    }
    
    memset(newreturnColumnSizes,0,sizeof(int*)*treedeep);
    
    makearray(root,&treedim,newreturnColumnSizes,colomun,count,&newcount);
    
    if(returnColumnSizes == NULL)
    {
        returnColumnSizes = (int**)malloc(sizeof(int*)*1);
    }
    
    *returnSize = newcount;
    printf("%d\r\n",newcount);
    
    *returnColumnSizes = colomun;
    
    return newreturnColumnSizes;
    
}
