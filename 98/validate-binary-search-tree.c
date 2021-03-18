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
    Node *NodeArray[10000];
    int top;
    int tail;
    int size;
}stack;


stack g_stack;

void stack_init()
{
    memset(&g_stack,0,sizeof(stack));
}

void push_stack(Node *pnode)
{
    g_stack.NodeArray[g_stack.top] = pnode;
    g_stack.top++;
    g_stack.size++;
}

Node *pop_stack()
{
    Node *tmp = g_stack.NodeArray[g_stack.top-1];
    g_stack.top--;
    g_stack.size--;
    return tmp;
}

bool stack_empty()
{
    return g_stack.size == 0?true:false;
}

bool isValidBST(struct TreeNode* root){
    stack_init();
    Node *pseq[10000] = {0};
    int node_cnt = 0;
    Node *ptmp = root;

    while(ptmp != NULL || stack_empty() == false)
    {
        while (ptmp)
        {
            push_stack(ptmp);
            ptmp = ptmp->left;
        }

        ptmp = pop_stack();
        if (ptmp)
        {
            pseq[node_cnt++] = ptmp;
            ptmp = ptmp->right;
        }
    }

    for (int i = 1; i < node_cnt;i++)
    {
        if (pseq[i]->val <= pseq[i-1]->val)
        {
            return false;
        }
    }

    return true;
}
