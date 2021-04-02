/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
bool isPalindrome(struct ListNode* head){
    if (!head)
    {
        return false;
    }

    Node *pfast = head;
    Node *pslow = head;

    //先找到中间节点
    while (pfast->next && pfast->next->next)
    {
        pslow = pslow->next;
        pfast = pfast->next?pfast->next->next:pfast->next;
    }
    
    //逆转pslow之后的节点
    Node *pnewlist = NULL;
    Node *ptmp = pslow->next;
    while (ptmp)
    {
        if (!pnewlist)
        {
            pnewlist = ptmp;
            ptmp = ptmp->next;
            pnewlist->next = NULL;
        }
        else
        {
            Node *p1 = ptmp;
            ptmp = ptmp->next;
            p1->next = pnewlist;
            pnewlist = p1;
        }
    }

    while (head && pnewlist)
    {
        if (head->val != pnewlist->val)
        {
            return false;
        }

        head = head->next;
        pnewlist = pnewlist->next;
    }

    return true;
}
