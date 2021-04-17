
#define deg_info(x)  do {printf("---------- %s:%d: %s ----------\r\n",__FUNCTION__,__LINE__,x);}while(0);
typedef struct TreeNode Node;
int calcNodeNr(struct TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1+calcNodeNr(root->left) + calcNodeNr(root->right);
}

//递归中序遍历
int traversInOrder(Node *root,int *pretArray,int *pindex)
{
	if (root == NULL)
	{
		return 0;
	}
	traversInOrder(root->left,pretArray,pindex);
	pretArray[*pindex] = root->val;
	(*pindex) += 1;
	traversInOrder(root->right,pretArray,pindex);
    return 1;
}

//快速排序
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

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
	int *retArray = NULL;
	int AllNum = 0;
	Node *p1  = root1;
	Node *p2 = root2;
	int index = 0;
	AllNum = calcNodeNr(root1) + calcNodeNr(root2);//计算出所有的节点个数
	retArray = (int *)malloc(sizeof(int)*AllNum);
	if (retArray == NULL)
	{	
		deg_info("malloc failed!")
		return NULL;
	}
	memset(retArray,0,sizeof(int)*AllNum);
	traversInOrder(root1,retArray,&index);
	traversInOrder(root2,retArray,&index);
	if (index != AllNum)
	{
		deg_info("get an error order!")
		return NULL;
	}
	
	//快速排序
	quicksort(retArray,0,index-1);
	
	*returnSize = index;
	return retArray;
}


