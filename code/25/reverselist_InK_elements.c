/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#if 0
1.剪切
2.翻转
3.链接
#endif


typedef struct ListNode node;

//裁剪链表,得到其以list开头，长度为k的链表，*tail为其尾结点,pnewhead为下一条链表的新头节点
node *curlist(node *list,int k,node **tail)
{
    (*tail) = NULL;
    node *p = list;
    while (k > 1 && p)
    {
        p = p->next;
        --k;
    }
    if (p == NULL)
    {
        return p;
    }
    node *pnewhead = p->next;
    (*tail) = p;
    p->next = NULL;
    return pnewhead;
}

//反转单链表
void reverselist(node *list)
{
    node *pnewlist = NULL;
    node *ptmp = list;
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
            node *p = ptmp->next;
            ptmp->next = pnewlist;
            pnewlist = ptmp;
            ptmp = p;
        }
    }
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int len = 0;
    node *ptmp = head;
    while (ptmp)
    {
        len++;
        ptmp = ptmp->next;
    }

    if (len <= 0)
    {
        return head;
    }

    int segment = len/k;
    node *pcurhead = head;
    node *pnexthead = NULL;
    node *pcurtail = NULL;

    node *plisthead = NULL;
    node *plisttail = NULL;
    for(int i = 0 ; i < segment;i++)
    {
        if (i == 0)
        {
            pnexthead = curlist(pcurhead,k,&pcurtail);
            
            reverselist(pcurhead);

            plisttail = pcurhead;
            plisthead = pcurtail;

            pcurhead = pnexthead;
        }
        else 
        {
            pnexthead = curlist(pcurhead,k,&pcurtail);
           
            reverselist(pcurhead);

            plisttail->next = pcurtail;

            plisttail = pcurhead;

            pcurhead = pnexthead;
        }
    }

    if (pnexthead)
    {
        plisttail->next = pnexthead;
    }

    return plisthead;
}
