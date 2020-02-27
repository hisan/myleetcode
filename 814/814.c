//思路：
//主要还是对二叉树进行遍历，在遍历的过程中，若当前的结点为子节点且他的val==0,则将他的父节点指向他的指针只为null


//移除所有不包含 1 的子树
struct TreeNode* pruneTree(struct TreeNode* root) {
    //遍历，将val=0的子节点置空
    if(root == NULL )
    {
        return NULL;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(!root->left && !root->right&&root->val==0)
    {
        return NULL;
    }
    return root;
}

