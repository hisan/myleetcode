/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct TreeNode Node;


typedef struct st_stack
{
    Node *arr[100];
    int top;
    int size;
}stack;


int min(int a,int b)
{
    return a>b?b:a;
}

int minDiffInBST(struct TreeNode* root){
    stack g_stack;
    g_stack.size = g_stack.top = 0;
    Node *ptmp = root;
    int val_array[100];
    int idx = 0;
    int mindis = 0;
    while (ptmp || g_stack.size > 0)
    {
        while (ptmp)
        {
            g_stack.arr[g_stack.top++] = ptmp;
            g_stack.size++;
            ptmp = ptmp->left;
        }

        ptmp = g_stack.arr[g_stack.top-1];
        g_stack.top -= 1;
        g_stack.size -= 1;
        val_array[idx++] = ptmp->val;

        ptmp = ptmp->right;
    }

    mindis = val_array[1] - val_array[0];
    for (int i = 2 ;i < idx;++i)
    {
        mindis = min(mindis,val_array[i] - val_array[i-1]);
    }

    return mindis;
}






