typedef struct TreeNode Node;

typedef struct st_stack
{
    Node *array[10000];
    int top;
    int tail;
    int size;
}STACK;

void stack_init(STACK *pstack)
{
    memset(pstack,0,sizeof(STACK));
}

void in_stack(STACK *pstack,Node *pnode)
{
    pstack->array[pstack->top] = pnode;
    pstack->top++;
    pstack->size++;
}

bool stack_empty(STACK *pstack)
{
    if (pstack->size == 0)
    {
        return true;
    }

    return false;
}

Node* out_stack(STACK *pstack)
{
    Node* ptmp = pstack->array[pstack->top-1];
    pstack->top--;
    pstack->size--;
    return ptmp;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int *res = NULL;
    Node *ptmp = NULL;
    STACK g_stack;
    stack_init(&g_stack);

    *returnSize = 0;

    if (root == NULL)
    {
        return res;
    }

    ptmp = root;
    while ((ptmp!=NULL) || (false == stack_empty(&g_stack)))
    {
        while (ptmp!=NULL)
        {
            in_stack(&g_stack,ptmp);
            ptmp = ptmp->left;
        }

        ptmp = out_stack(&g_stack);

        if (ptmp != NULL)
        {
            printf("%d\n",ptmp->val);
            res = realloc(res,sizeof(int)*(*returnSize+1));
            res[*returnSize] = ptmp->val;
            (*returnSize)++;
            ptmp = ptmp->right;
        }
    }

    return res;
}