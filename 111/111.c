
int min(int a,int b)
{
    return  a>b?b:a;
}


int minDepth(struct TreeNode* root){
    
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left==NULL&&root->right == NULL)
    {
        return 1;
    }
    else if(root->left!=NULL&&root->right == NULL)
    {
        return 1+minDepth(root->left);
    }
    else if(root->left!=NULL&&root->right!=NULL)
    {
        return 1 + min( minDepth(root->left),minDepth(root->right) );
    }
    else if(root->left == NULL&&root->right != NULL)
    {
        return 1+minDepth(root->right);
    }
    
    return 0;
}
