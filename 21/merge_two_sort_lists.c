/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    typedef struct ListNode Node;
    Node *head = NULL;
    Node *New_List = NULL; 

    if (l1 == NULL || l2 == NULL)
    {
        return l1==NULL?l2:l1;
    }

    New_List = (Node *)malloc(sizeof(Node));
    memset(New_List,0,sizeof(Node));
    head = New_List;
    
    while (l1&&l2)
    {
        if (l2->val <= l1->val)
        {
            New_List->next = l2;
            New_List = New_List->next;
            l2 = l2->next;
        }
        else 
        {
            New_List->next = l1;
            New_List = New_List->next;
            l1 = l1->next;
        }
    }

    if (l1)
    {
        New_List->next = l1;
    }

    if (l2)
    {
        New_List->next = l2;
    }

    return head->next;
}
