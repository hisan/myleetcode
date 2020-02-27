//重点：
// 1.怎么理解递归建树这个步骤？？？
// {
   // (1) 每个函数中首先由函数参数中的数组，取其最大值，并赋值给一个根结点。
   // (2) 此时数组中最大值元素的位序将数组一分为二，左右边分别为当前节点的左右子树的所有子节点
   // (3) 以（2）中产生的两个数组分别重复（1）（2）两个步骤。
// }
// 2.递归的终止条件？
// {
        // 能够进行递归的条件是存在数组，所以当数组非法时递归终止，因此，只需判断数组下标是否合法即可。
// }

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
typedef struct TreeNode Node;

//求一个数组某一范围内的最大值的位序
int findarrayMaxnum(int *array,int left,int right)
{
    if(left == right )
    {
        return left;
    }
    int i = left;
    int  retnum = array[i];
    int retcount = left;
    for(;i <=right;i++)
    {
        if(retnum < array[i])
        {
            retnum = array[i];
            retcount = i;
        }
    }
    return retcount;
}

struct TreeNode* MakeNode()
{//分配一个结点
    //typedef struct TreeNode Node;
    Node* node = (Node*)malloc(sizeof(Node));
    memset(node,0,sizeof(Node));
    return node;
}

//递归算法实现构建一棵树
struct TreeNode* CreateTree(int *array,int left,int right)
{//传递指针or传递指针的指针，在对一个函数外部的指针分配动态内存时，传入参数应该是指针的指针
    //(也就是我们要为其分配动态内存的指针的地址，这样是因为若函数的参数是函数自己的栈区变量，则函数返回就会释放该变量)
    //分配内存
    struct TreeNode* root = NULL;
    root = MakeNode();
    if(root == NULL)
    {
        return NULL;
    }

    if( (left < 0 || right < 0) || (left > right))
    {//递归终止的条件
        return NULL;
    }
    int tempcounter = findarrayMaxnum(array,left,right);
    root->val = array[tempcounter];
    root->left = CreateTree(array,left,tempcounter-1);
    root->right = CreateTree(array,tempcounter+1,right);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    Node* root = NULL;
    root = CreateTree(nums,0,numsSize-1);
    return root;
}

//变体 1

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

typedef struct TreeNode Node;

Node * MakeNode()
{
    Node *node = (Node*)malloc(sizeof(Node));
    memset(node,0,sizeof(Node));
    return node;
}
int findMaxCounterInArray(int *array,int left,int right)
{
    int tempCount = left;
    int  i = left;
    int tempMaxElem = array[left];
    for(;i <= right;i++)
    {
        if(tempMaxElem <= array[i])
        {
            tempMaxElem = array[i];
            tempCount = i;
        }
    }
    return tempCount;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int left,int right)
{
    if( (nums == NULL) || (right < 0 || left < 0) || (right < left))
    {//递归终止条件
        return NULL;
    }

    Node *node = MakeNode();

    int tempCounter = findMaxCounterInArray(nums,left,right);

    node->val = nums[tempCounter];
    node->left = constructMaximumBinaryTree(nums,left,tempCounter-1);
    node->right = constructMaximumBinaryTree(nums,tempCounter+1,right);

    return node;
}
