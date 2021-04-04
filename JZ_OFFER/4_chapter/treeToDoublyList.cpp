/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        vector<Node *> vnd;
        stack<Node *> stack;
        Node *p = root;
        if (p == NULL)
        {
            return p;
        }
        while (p || stack.size() > 0)//得到其LDR的序列
        {
            while (p)
            {
                stack.push(p);
                p = p->left;
            }

            p = stack.top();
            stack.pop();
            vnd.push_back(p);
            p = p->right;
        }

        for (int i = 0; i < vnd.size();i++)//根据循环链表的特征，重新更改其指针关系
        {
            if (i == 0)
            {
                vnd[i]->left = vnd[vnd.size()-1];
            }
            else 
            {
                vnd[i]->left = vnd[i-1];
            }

            if (i + 1 == vnd.size())
            {
                vnd[i]->right = vnd[0];
            }
            else 
            {
                vnd[i]->right = vnd[i+1];
            }
        }

        return vnd[0];
    }
};
