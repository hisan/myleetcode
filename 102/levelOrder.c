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
    Node *nodearray[3000];
    int top;
    int tail;
    int size;
}Queue;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    int **ret = NULL;
    int *retcol = NULL;

    *returnSize = 0;
    int tmpcount = 0;

    if (root == NULL)
    {
        return ret;
    }

    Queue g_queue;
    memset(&g_queue,0,sizeof(Queue));
    g_queue.nodearray[g_queue.top++] = root;
    g_queue.size++;
    
    while (g_queue.size > 0)
    {
        ret = realloc(ret,sizeof(int *)*(*returnSize + 1));
        ret[*returnSize] = (int *)malloc(sizeof(int)*(g_queue.size));

        tmpcount = 0;
        retcol = realloc(retcol,sizeof(int)*(*returnSize + 1));
        retcol[*returnSize] = g_queue.size;

        int size = g_queue.size;

        for (int i = 0; i< size;i++)
        {
            Node *ptop = g_queue.nodearray[g_queue.tail];
            g_queue.tail++;
            g_queue.size--;
            ret[*returnSize][tmpcount++] = ptop->val;

            if (ptop->left)
            {
                g_queue.nodearray[g_queue.top++] = ptop->left;
                g_queue.size++;
            }

            if (ptop->right)
            {
                g_queue.nodearray[g_queue.top++] = ptop->right;
                g_queue.size++;
            }
        }

        (*returnSize)++;
    }

    *returnColumnSizes = retcol;
    return ret;
}
