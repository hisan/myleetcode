#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


#define bool int
#define false -1
#define true 0


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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize)
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

    in_stack(&g_stack,root);
    while (false == stack_empty(&g_stack))
    {
        ptmp = out_stack(&g_stack);
        if (ptmp != NULL)
        {
            printf("%d\n",ptmp->val);
            res = realloc(res,sizeof(int)*(*returnSize+1));
            res[*returnSize] = ptmp->val;
            (*returnSize)++;

            if (ptmp->right != NULL)
            {
                in_stack(&g_stack,ptmp->right);
            }

            if (ptmp->left != NULL)
            {
                in_stack(&g_stack,ptmp->left);
            }
        }
    }

    return res;
}


#if 0
  1
    \
     2
    /
   3 
#endif

int main()
{
	Node root;
	Node node1,node2;
	
	root.val = 1;
	root.left = NULL;
	root.right = &node1;
	
	node1.val = 2;
	node1.left = &node2;
	node1.right = NULL;
	
	node2.val = 3;
	node2.left = node2.right = NULL;
	
	int returnSize = 0;
	
	int* res = preorderTraversal(&root,&returnSize);

	
	return 0;
}















