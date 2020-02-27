
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int maxDepth(struct TreeNode* root) {
    if(root == NULL)
    {
        return 0;
    }
    
   int dep1 = maxDepth(root->left)+1;
   int dep2 = maxDepth(root->right)+1;
   return dep1>=dep2?dep1:dep2;
}

bool isBalanced(struct TreeNode* root) {
  
    if(root==NULL)
    {
        return true;
    }
    int leftdep = maxDepth(root->left);
    int rightdep = maxDepth(root->right);
    if(abs(leftdep - rightdep) <= 1)
    {
        return ( isBalanced(root->left) && isBalanced(root->right) );
    }
    else
    {
        return false;
    }
    return true;
}
