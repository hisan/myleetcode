


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    typedef struct TreeNode node;
    if(inorderSize == 0)
    {
        return NULL;
    }
    
    node *root = (node*)malloc(sizeof(node));
    root->val = preorder[0];
    int i = 0;
    for(;i < inorderSize;i++)
    {
        if(inorder[i] == preorder[0])
        {
            break;
        }
    }
    
    if(i == inorderSize)
    {//这有什么用？
        return NULL;
    }
    
    root->left = buildTree(preorder+1,0,inorder,i);
    root->right = buildTree(preorder+i+1,0,inorder+i+1,inorderSize-i-1);
    return root;
}
//(1)为什么是preorder+i+1?
//当确定i后，证明preorder[0]之后（包括preorder)的i个元素一定属于左子树，则之后的元素一定属于右子树，所以是+i又+1.
//(2)buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) 中，preorderSize为什么可有可无？
//因为我们永远是取preorder数组的首元素，用其去inorder中遍历找到不超过inorderSize的某个位序，所以，preorderSize为什么可有可无。
