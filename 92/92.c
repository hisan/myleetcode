反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
1 ≤ m ≤ n ≤ 链表长度。
示例:
输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

//2019-04-22
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
typedef struct ListNode node;
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{  
    if((m == n )||(head->next == NULL)||(head == NULL))
    {
        return head;
    }  
    node *ptemp = head;
    node *ppre = NULL;
    node *pafter = NULL;
    node *pm =  NULL;
    node *pn = NULL;
    int i = 1;
    pn = pm = head;
    while(i < m)
    {
        ppre = ptemp;
        ptemp = ptemp->next;
        pm = ptemp;
        i++;
    }
   
    while(i < n)
    {
        ptemp = ptemp->next;
        pn = ptemp;
        pafter = pn->next;
        i++;
    }
   
    node *temp = NULL;
    node *pmflag = pm;
    node *pnflag = pn;
    node *pnewhead = (node*)malloc(sizeof(node));
    memset(pnewhead,0,sizeof(node));
   
    if(pm&&pn)
    {  
        ptemp = pm;
        temp = ptemp->next;
        while(ptemp != pafter)
        {
            ptemp->next = pnewhead;
            pnewhead = ptemp;
            ptemp = temp;
            if(temp!=NULL)
            {
                temp = temp->next;
            }
        }
        pmflag->next = pafter;
        if(ppre != NULL)
        {//m!=1
            ppre->next = pnewhead;
        }
        else
        {//m == 1
            head = pnflag;
        }
    }
    return head;
}























