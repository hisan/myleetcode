/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
node *cutlist(node *list,int size)
{
    node *p = list;
    while (p && size>1)
    {
        p = p->next;
        --size;
    }

    if (!p)
    {
        return p;
    }

    node *newhead = p->next;
    p->next = NULL;
    return newhead;
}

node *mergelist(node *list1,node *list2)
{
    node tmp;
    tmp.next = NULL;
    node *pnewlist = &tmp;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            pnewlist->next = list1;
            list1 = list1->next;
            pnewlist = pnewlist->next;
        }
        else 
        {
            pnewlist->next = list2;
            list2 = list2->next;
            pnewlist = pnewlist->next;
        }
    }

    if (list1)
    {
        pnewlist->next = list1;
    }

    if (list2)
    {
        pnewlist->next = list2;
    }

    return tmp.next;
}

struct ListNode* sortList(struct ListNode* head){
    node *cur = NULL;
    node tmp;
    memset(&tmp,0,sizeof(tmp));
    tmp.next = head;
    node *tail = NULL;
    int length = 0;

    node *p = head;
    while (p)
    {
        length++;
        p = p->next;
    }
    
    if (length <=1)
    {
        return head;
    }

    printf("%d\n",length);

    for (int i = 1; i < length;i<<=1)
    {
        printf("%d\n",i);
        cur = tmp.next;
        tail = &tmp;
        while (cur)
        {
            node *left = cur;
            node *right = cutlist(left,i);
            cur = cutlist(right,i);
            tail->next = mergelist(left,right);
            while (tail->next)
            {
                tail = tail->next;
            }
        }
    }
    return tmp.next;
}

