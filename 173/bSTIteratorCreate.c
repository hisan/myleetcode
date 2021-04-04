/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
typedef struct {
    Node *ndarr[10000];
    int top;
    int size;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    Node *ptmp = root;
    if (!ptmp)
    {
        return NULL;
    }
    
    BSTIterator *BSTIter = (BSTIterator *)malloc(sizeof(BSTIterator));
    BSTIter->top = BSTIter->size = 0;

    while (ptmp)
    {
        BSTIter->ndarr[BSTIter->top++] = ptmp;
        BSTIter->size++;
        ptmp = ptmp->left;
    }
    
    return BSTIter;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->size > 0?true:false;
}

int bSTIteratorNext(BSTIterator* obj) {
    if (bSTIteratorHasNext(obj) == false)
    {
        return -1;
    }

    Node *ptmp = obj->ndarr[obj->top-1];
    obj->top--;
    obj->size--;
    int val = ptmp->val;
    ptmp = ptmp->right;
    while (ptmp)
    {
        obj->ndarr[obj->top++] = ptmp;
        obj->size++;
        ptmp = ptmp->left;
    }

    return val;
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj)
    {
        free(obj);
    }
    return;
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
