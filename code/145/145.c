//2018-1-1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode Tree;
    Tree** stack = (Tree**)malloc(sizeof(Tree*));
    Tree* p = root;
    Tree* pcur = NULL;//由于是后序遍历，所以要判断当前结点的右结点是否访问过
    int cur = 0;
    *returnSize = 0;
    int *result = NULL;
    if(!root)
    {
        return result;
    }
    while(cur>0||p!=NULL)
    {
        if(p)
        {
            stack = (Tree**)realloc(stack,sizeof(Tree*)*(cur+1));
            stack[cur++] = p;
            p = p->left;
        }
        else
        {
            p = stack[cur-1];//取栈顶元素
            if(p->right&&p->right!=pcur)
            {//由于是后序遍历，所以要判断当前结点的右结点是否访问过
                p = p->right;//转换成右子树
                stack = (Tree**)realloc(stack,sizeof(Tree*)*(cur+1));
                stack[cur++] = p;//stack是二级指针，此时用它来存储结点的地址，此时的它相当于指针数组
                p = p->left;
                 
            }
            else
            {
                cur--;//退栈
                result = (int*)realloc(result,sizeof(int)*((*returnSize)+1));
                result[(*returnSize)++] = p->val;
                pcur = p;
                p = NULL;
            }
        }
    }
    return result;
}

////pcur的必要性：
    // 以树的序列{1,NULL,2,3}来讲，入栈顺序位【1，2，3】，当3,2,出栈后，开始访问1，但是如果没有判断p->right是否等于pcur,
    // 则又会将1->right入栈，造成遍历失败，pcur的作用就是用于这样的情形，在后序遍历之时，LRD,此时的D是否为"真正的"D(也就是他的right是否访问过了);