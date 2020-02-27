
//思路：采取递归实现，判断每一个节点，反转他的子节点，然后递归翻转该结点的子节点的子节点

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

typedef struct TreeNode Node;

struct TreeNode* invertTree(struct TreeNode* root) {
    
    Node *tempNode = NULL;
    if(root == NULL )
    {
        return NULL;
    }
    
    if(root->left == NULL && root->right == NULL )
    {
        return root;
    }
    else if(root->left == NULL )
    {
        root->left = root->right;
        root->right = NULL;
    }
    else if(root->right == NULL )
    {
        root->right = root->left;
        root->left = NULL;
    }
    else
    {
        tempNode =  root->left;
        root->left = root->right;
        root->right = tempNode;
    }
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
