#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode Node;

Node *make_node()
{
    Node *pNode = (Node *)malloc(sizeof(Node));
    memset(pNode,0,sizeof(Node));
    return pNode;
}

Node *buildPro(int **preorder,int *preorderSize,int *inorder,int *inorderSize)
{
	if (*inorderSize <= 0 || *preorderSize <= 0)
    {
        return NULL;
    }
	
    Node *root = NULL;
    root = make_node();
    root->val = (*preorder)[0];
    
    //计算出经DLR的第一个元素划分后的左、右子数组的DLR和LDR,并调用递归
    int *new_inorder_left = NULL;
    int new_inorder_left_size = 0;

    int *new_inorder_right = NULL;
    int new_inorder_right_size = 0;

    int *new_preorder_left = NULL;
    int new_pre_order_left_size = 0;

    new_inorder_left = &inorder[0];

    for (int i = 0;i < *inorderSize;i++)
    {
        if (inorder[i] == (*preorder)[0])//求得两个子数组的未知边界
        {
            new_inorder_right = inorder + i + 1;
            new_inorder_right_size = *inorderSize - i -1;
            new_inorder_left_size = i;
            break;
        }
    }
	
	(*preorder) += 1;
	(*preorderSize) -= 1;
	
    if (new_inorder_left_size > 0)
    {
        root->left = buildPro(preorder,preorderSize, new_inorder_left, &new_inorder_left_size);
    }

    if (new_inorder_right_size > 0)
    {
        root->right = buildPro(preorder,preorderSize, new_inorder_right, &new_inorder_right_size);
    }
	
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    return buildPro(&preorder,&preorderSize,inorder,&inorderSize);
}


int main()
{
	int preorder[] = {3,1,2,4};
	int preorderSize = sizeof(preorder)/sizeof(preorder[0]);
	
	int inorder[] = {1,2,3,4};
	int inorderSize = sizeof(inorder)/sizeof(inorder[0]);
	
	Node *root = buildTree(preorder,preorderSize,inorder,inorderSize);
	
	return 0;
}


















