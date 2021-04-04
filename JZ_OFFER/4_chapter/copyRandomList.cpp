/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node *,Node *> node_map;
       Node *ptmp = head;
       Node *res = NULL;
       while (ptmp)
       {

           Node *node = new Node(ptmp->val);
           node_map.insert(make_pair(ptmp,node));

           if (!res)
           {
               res = node;
           }

           ptmp = ptmp->next;
       }

       for (auto v:node_map)
       {
           if (v.first->next)
           {
                v.second->next = node_map[v.first->next];
           }

           if (v.first->random)
           {
                v.second->random = node_map[v.first->random];
           }
       }
       
       return res;
    }
};
