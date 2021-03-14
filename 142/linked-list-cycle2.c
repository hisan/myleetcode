/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    typedef struct ListNode Node;

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *pf = head;
    Node *ps = head;
    int flag = 0;
    while (ps)
    {
        ps = ps->next;
        if (pf->next&&pf->next->next)
        {
            pf = pf->next->next;
        }
        else 
        {
            flag = 0;
            break;
        }

        if (ps == pf)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)//链表无环，直接返回
    {
        return NULL;
    }

    ps = head;
    
    printf("%d\n",pf->val);

    while (ps)
    {
        if (ps == pf)
        {
            break;
        }

        ps = ps->next;
        pf = pf->next;
    }

    return pf;
}


#if 0
#endif 































