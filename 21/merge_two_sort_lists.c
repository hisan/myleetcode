/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	
    typedef struct ListNode Node;
    Node *p1 = l1;
    Node *p2 = l2;
	Node *head = NULL;
	Node *pnewlist = NULL;
	
	if (l1 == NULL || l2 == NULL)
	{
		return l1 == NULL?l1:l2;
	}
	
    while (p1 != NULL && p2 != NULL)
    {
		if (p1->val < p2->val)
		{
			if (pnewlist)
			{
				pnewlist->next = p1;
				pnewlist = pnewlist->next;
			}
			else 
			{
				head = p1;
				pnewlist = p1;
			}
			
			p1 = p1->next;
		}
		else 
		{
			if (pnewlist)
			{
				pnewlist->next = p2;
				pnewlist = pnewlist->next;
			}
			else 
			{
				head = p2;
				pnewlist = p2;
			}
			
			p2 = p2->next;
		}
    }
	
	if (p1 != NULL)
	{
		pnewlist->next = p1;
	}
	
	if (p2)
	{
		pnewlist->next = p2;
	}
	
	return head;
}