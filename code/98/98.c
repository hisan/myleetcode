
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isValidBST(struct TreeNode* root) {
    if(!root)
    {
        return false;
    }
    
    if(!root->right&&!root->left)
    {
        return true;
    }
    
    if(root->right->val < root->val && root->left->val > root ->val)
    {
        return ( isValidBST(root->left) & isValidBST(root->right) );
    }
    else   
    {
        return false;
    }
}



//错误示例
bool isValidBST(struct TreeNode* root) {
    if(!root)
    {
        return false;
    }
    
    if(!root->right&&!root->left)
    {
        return true;
    }
    else if(root->right&&!root->left)
    {//这是一个不充分的条件，当前结点可以满足，但是，当前结点的子节点会不满足当前结点的父节点
        return ( isValidBST(root->right) );
    }
    else if(!root->right&&root->left)
    {
        return ( isValidBST(root->left) );
    }
    else if(root->right->val > root->val && root->left->val < root ->val)
    {
        return ( isValidBST(root->left) & isValidBST(root->right) );
    }
    else   
    {
        return false;
    }
}


//错误示例2
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
typedef struct TreeNode Node;

//分别计算左右子树的最小值和最大值
int calcMaxValueInRightTree(Node *root)
{
    int max = root->val;
    if(root->left != NULL)
    {
        int maxleft = calcMaxValueInRightTree(root->left);
        max = max > maxleft?max:maxleft;
    }
    
    if(root->right != NULL)
    {
        int maxright = calcMaxValueInRightTree(root->right);
        max = max > maxright?max:maxright;
    }
    
    return max;
}

int calcMinValueInLeftTree(Node *root)
{
    int min = root->val;
    if(root->left != NULL)
    {
        int minleft = calcMinValueInLeftTree(root->left);
        min = min < minleft?min:minleft;
    }
    
    if(root->right != NULL)
    {
        int minright = calcMinValueInLeftTree(root->right);
        min = min < minright?min:minright;
    }
    
    return min;
}

bool TestBST(Node *root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(root->val < min || root->val > max)
    {
        return false;
    }
    
    return TestBST(root->left,min,root->val - 1) && TestBST(root->right,root->val +1,max);
}

bool isValidBST(struct TreeNode* root) {
    
    int max = 0;
    int min = 0;
    if(!root)
    {
        return true;
    }
    
    if(root->right != NULL)
    {
        max = calcMaxValueInRightTree(root->right);
    }
    
    if(root->left != NULL)
    {
        min = calcMinValueInLeftTree(root->left);
    }
    
    return TestBST(root,min,max);
}


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
typedef struct TreeNode Node;

//分别计算左右子树的最小值和最大值
int calcMaxValueInTree(Node *root)
{
    int max = root->val;
    if(root->left != NULL)
    {
        int maxleft = calcMaxValueInTree(root->left);
        max = max > maxleft?max:maxleft;
    }
    
    if(root->right != NULL)
    {
        int maxright = calcMaxValueInTree(root->right);
        max = max > maxright?max:maxright;
    }
    
    return max;
}

int calcMinValueInTree(Node *root)
{
    int min = root->val;
    if(root->left != NULL)
    {
        int minleft = calcMinValueInTree(root->left);
        min = min < minleft?min:minleft;
    }
    
    if(root->right != NULL)
    {
        int minright = calcMinValueInTree(root->right);
        min = min < minright?min:minright;
    }
    
    return min;
}

bool isValidBST(struct TreeNode* root) {
    
    if(!root)
    {
        return true;
    }
    
    if(root->left != NULL&&calcMaxValueInTree(root->left) >= root->val)
    {
        return false;
    }
    
    if(root->right != NULL&&calcMinValueInTree(root->right) <= root->val)
    {
        return false;
    }
    
    return isValidBST(root->left)&&isValidBST(root->right);
}
