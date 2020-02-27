// （1）//reallloc函数的使用
// 指针名=（数据类型*）realloc（要改变内存大小的指针名，新的大小）。
// 新的大小可大可小（如果新的大小大于原内存大小，则新分配部分不会被初始化；如果新的大小小于原内存大小，可能会导致数据丢失 ），即，在参数一指向的内存地址开始处分配大小为第二个参数大小的内存块，并返回这块内存的初始地址（也即是第一个参数指向的内存起始地址），新的大小若是大于原内存时，也不会覆盖原内存。
// （2）//思想总结：
// 通过一个二级指针，指向一个基本元素类型为指向节点的指针的动态数组，从根节点开始遍历，前序：先访问根节点，将其放置在动态数组中（先为数组分配该指针再放），
// 再将游标指向根节点的左结点（叶子结点的左结点为null），直到游标指向null,则取动态数组中的第一个元素（栈顶元素）,重复上述过程。

//2019-1-1  中序
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode Tree;
    Tree ** stack = (Tree**)malloc(sizeof(Tree**));
    int *result = NULL;
    int cur = 0;
    while(cur>0||root!=NULL)
    {
        if(root)//root为空的条件主要针对root此时为叶子节点的子节点（null)
        {
            stack = (Tree**)realloc(stack,sizeof(Tree*)*cur+1);
            stack[cur++] = root;
            root = root->left;
        }
        else
        {
            root = stack[--cur];
            result = (int*)realloc(result,sizeof(int)*(*returnSize+1));
            result[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    return result;
}

//2019-1-1  前序
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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    typedef struct TreeNode Tree;
    *returnSize = 0;
    Tree ** stack = (Tree**)malloc(sizeof(Tree**));
    int *result = NULL;
    int cur = 0;
    while(cur>0||root!=NULL)
    {
        if(root)//root为空的条件主要针对root此时为叶子节点的子节点（null)
        {
            result = (int*)realloc(result,sizeof(int)*(*returnSize+1));
            result[(*returnSize)++] = root->val;
            
            stack = (Tree**)realloc(stack,sizeof(Tree*)*cur+1);
            stack[cur++] = root;
            root = root->left;
        }
        else
        {
            root = stack[--cur];
            root = root->right;
        }
    }
    return result;
}

//前序遍历，dlr,当前结点一定是先访问的，访问完再访问该节点的左结点，若已经到了最左结点（null),则访问栈顶结点的右结点，则又是重复上述过程
