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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = NULL;
    Node *ptmp = NULL;
    Node *pcur = NULL;
    STACK g_stack;
    stack_init(&g_stack);

    *returnSize = 0;

    if (root == NULL)
    {
        return res;
    }

    ptmp = root;
    while (ptmp != NULL || false == stack_empty(&g_stack))
    {
        while (ptmp)
        {
            in_stack(&g_stack,ptmp);
            ptmp = ptmp->left;
        }

        ptmp = out_stack(&g_stack);//这里应该是取栈顶元素但是不出栈
        if (ptmp->right && pcur != ptmp->right)
        {
            in_stack(&g_stack,ptmp);//由于之前已经出栈了，所以这里要再入栈
            ptmp = ptmp->right;
        }
		else 
		{
			res = realloc(res,sizeof(int)*(*returnSize+1));
			res[*returnSize] = ptmp->val;
            (*returnSize)++;
			pcur = ptmp;
			ptmp = NULL;
		}
    }

    return res;
}



#if 0
  1
    \
     2
    / \
   3   6 
#endif

int main()
{
	Node root;
	Node node1,node2,node3;
	
	root.val = 1;
	root.left = NULL;
	root.right = &node1;
	
	node1.val = 2;
	node1.left = &node2;
	node1.right = &node3;
	
	node2.val = 3;
	node2.left = node2.right = NULL;
	
	node3.val = 6;
	node3.left = node3.right = NULL;
	
	int returnSize = 0;
	
	int* res = postorderTraversal(&root,&returnSize);
	
	return 0;
}







