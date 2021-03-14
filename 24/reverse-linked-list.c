/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    typedef struct ListNode Node;
    Node *pNewList = NULL;
    Node *ptmp = NULL;

    while (head)
    {
        ptmp = head->next;
        if (pNewList)
        {
            head->next = pNewList;
            pNewList = head;
        }
        else 
        {
            pNewList = head;
            head->next = NULL;
        }
        head = ptmp;
    }

    return pNewList;
}

