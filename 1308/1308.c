
给出二叉搜索树的根节点，该二叉树的节点值各不相同，修改二叉树，使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键小于节点键的节点。
节点的右子树仅包含键大于节点键的节点。
左右子树也必须是二叉搜索树。

示例：

输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

提示：
树中的节点数介于 1 和 100 之间。
每个节点的值介于 0 和 100 之间。
给定的树为二叉搜索树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definitionc for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//2019-12-29
typedef struct TreeNode node;

int getBiNodeSum(node *root)
{
    if (root != NULL)
    {
        return 1+ getBiNodeSum(root->left) + getBiNodeSum(root->right);
    }
    
    return 0;
}

int calcBiNodeSum(const node *root,int value)
{
	int ret = 0;
    if (root != NULL)
    {
        if (root->val > value)
        {
            ret += root->val;
        }
		ret += calcBiNodeSum(root->left,value);
		ret += calcBiNodeSum(root->right,value);
    }

    return ret;
}

int GetValueArray(int* ValueArray,int size,node *root,node **nodearray)
{
    int i;
    for (i = 0 ;i < size ; i++)
    {
        ValueArray[i] = calcBiNodeSum(root,nodearray[i]->val);
		//printf(" ValueArray[%d] = %d\n",i,ValueArray[i]);
    }

    for ( i = 0 ;i < size ; i++)
    {
        nodearray[i]->val += ValueArray[i];
    }

    return 0;
}

void DTraversTree(node *root,node **nodearray,int *count)
{
    if (root != NULL)
    {
        nodearray[*count] = root;
		(*count)++;
		DTraversTree(root->left,nodearray,count);
		DTraversTree(root->right,nodearray,count);
    }
}

struct TreeNode* bstToGst(struct TreeNode* root){
    //先定一个遍历序列，将所有的节点的指针都保存在一个线性数组中，
    //再通过在一棵树种计算按题目要求计算每一个节点符合要求的值并保存在另一个线性数组中
    //最后分别对应下标相加即可。
    int size = 0;
    int count = 0;
    int *ValueArray = NULL;
	node **nodearray = NULL;
    size = getBiNodeSum(root);
    
    if (size == 0 || root == NULL)
    {
        return root;
    }
   
    nodearray = (node **)malloc(sizeof(node *)*size);
    if (nodearray == NULL)
    {
        return NULL;
    }
    memset(nodearray,0,sizeof(node *)*size);

    ValueArray = (int *)malloc(sizeof(int)*size);
    if (ValueArray == NULL)
    {
        return NULL;
    }
    memset(ValueArray,0,sizeof(int)*size);

    DTraversTree(root,nodearray,&count);
    GetValueArray(ValueArray,size,root,nodearray);
    return root;
}

