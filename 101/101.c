
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
1
/ \
2 2
/ \ / \
3 4 4 3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
1
/ \
2 2
\ \
3 3


//递归解法
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
typedef struct TreeNode node;
bool testSymmetric(node* p,node* q);

bool isSymmetric(struct TreeNode* root) {
    node *p,*q;
    if(!root)
    {
        return true;
    }
    
    p = root->left;
    q = root->right;
    
    return testSymmetric(p,q);
}

bool testSymmetric(node* p,node* q)
{
    if(!p&&!q)
    {
        return true;
    }
    
    if((!p&&q)||(p&&!q)||(p->val!=q->val))
    {
        return false;
    }
    return testSymmetric(p->left,q->right)&&testSymmetric(p->right,q->left);
}
//思路：镜像对称，不能从根节点开始，这题要从根节点以后的结点开始采用递归思想
镜像对称：两个结点，他们的值相同，他们的左孩子值相同，右孩子值相同，这就是镜像对称


//迭代解法























