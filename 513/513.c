
//思路
//后序遍历，在每一个结点最终被遍历到时记录其栈的深度depth和val,并在这个遍历的过程中若栈的最大深度增加，则更新栈depth和value

//代码
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int findBottomLeftValue(struct TreeNode* root) {
    typedef struct TreeNode Node;
    int result = root->val;
    int depth = 0;
    int cur = 0;
    Node** stack  = (Node**)malloc(sizeof(Node*)*(cur+1));
    Node *p = root;
    Node *pcur = NULL;
    
    while(cur!=0||p!=NULL)
    {
        if(p)
        {
            stack = (Node**)realloc(stack,sizeof(Node*)*(cur+1));
            stack[cur++] = p;
            p = p->left;
        }
        else  
        {
            p = stack[cur-1];
            if( depth < cur-1)
            {
                depth = cur - 1;
                result = stack[depth]->val;
            }
            
            if(p->right!=NULL&&p->right != pcur)
            {
                p = p->right;
                stack = (Node**)realloc(stack,sizeof(Node*)*(cur+1));
                stack[cur++] = p;
                p = p->left;
            }
            else
            {
                cur--;
                pcur = p;
                p = NULL;
            }
        }
    }
    return result;
}






















