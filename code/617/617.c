//2019/02/24

//思路：


//步骤：先序遍历两棵二叉树的同时进行值相加
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    
    if(t1 == NULL && t2 == NULL )
    {
        return NULL;
    }
    else if(t1 == NULL)
    {
        return t2;
    }
    else if(t2 == NULL )
    {
        return t1;
    }
    else
    {
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
    }
    
    return t1;
}
