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
    Node *parray[10000];
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
    g_stack.parray[g_stack.top] = pnode;
    g_stack.top++;
    g_stack.size++;
}

Node *pop_stack()
{
    Node *ptmp = g_stack.parray[g_stack.top-1];
    g_stack.top--;
    g_stack.size--;
    return ptmp;
}

Node *top_stack()
{
    Node *ptmp = g_stack.parray[g_stack.top-1];
    return ptmp;
}

bool stack_empty()
{
    return g_stack.size>0?false:true;
}

int kthSmallest(struct TreeNode* root, int k){
    Node *pseq[10000] = {0};
    int node_cnt = 0;
    Node *ptmp = root;
    while (ptmp != NULL || false == stack_empty())
    {
        while(ptmp)
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

    return pseq[k-1]->val;
}
