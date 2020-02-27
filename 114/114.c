
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
void flatten(struct TreeNode* root) {
    //先序遍历这棵树，并构建链表
    typedef struct TreeNode node;
    
    int cur = 0;
    int size = 0;
    int i = 0;
    
    node **treestack = (node**)malloc(sizeof(node*)*(cur+1));
    node **rootarray = (node**)malloc(sizeof(node*)*(size+1));

    node *listhead = NULL;
    node *p = root;
    
    while(cur > 0|| p)
    {
        if(p)
        {
            treestack = (node**)realloc(treestack,sizeof(node*)*(cur+1));
            
            rootarray = (node**)realloc(rootarray,sizeof(node*)*(size+1));
            
            rootarray[size++] = p;
            treestack[cur++] = p;  
            
            p = p->left;
        }
        else
        {
            p = treestack[cur-1];
            cur--;
            p = p->right;
        }
    }
    
    while(i < size-1)
    {
        listhead = rootarray[i];
        listhead->left = NULL;
        listhead->right = rootarray[i+1];
        i++;
    }
   
    return rootarray[0];
}



//思路就是保留先序遍历得到的访问节点的顺序，然后按照这个序列构建链表就行。
