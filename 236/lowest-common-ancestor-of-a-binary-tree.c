/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if (root == NULL)
    {
        return root;
    }

    if (p->left == q || p->right == q || p == root)
    {
        return p;
    }

    if (q->left == p || q->right == p || q == root)
    {
        return q;
    }

    Node *left = lowestCommonAncestor(root->left,p,q);
    Node *right = lowestCommonAncestor(root->right,p,q);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    return left == NULL?right:left;
}
