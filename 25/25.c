//2018-12-06  思路：头插法，每插一段就移动一段，保证“头”一直在最后面
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k==1||!head||!head->next)
    {
        return head;
    }
    typedef struct ListNode list;
    list* new_head=malloc(sizeof(list));
    list* preal = new_head;
    list* pnext;
    new_head->next = NULL;
    list* p=head;
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    if(len<k)
    {
        return head;
    }
    int count = len/k;//求得需要头插的段数
    p = head;
    pnext = p->next;
    int  i =0;
    while(i<count)
    {   
        int j = 0;
        while(j<k&&p)
        {   
            p->next = new_head->next;
            new_head->next = p;
            if(pnext)//非常重要的边界条件
            {    
                p = pnext;
                pnext = pnext->next;
            }
            else
            {   
                return preal->next;
            }
            j++;
        }
        int l = k;
        while(l)
        {
            new_head = new_head->next;
            l--;
        }
        i++;
    }
//k<len的情况下，头插后还剩一个字段长度<k的链表，要将它接上
   list *ptemp=preal->next;
    while(ptemp->next!=NULL)
    {   
        ptemp = ptemp->next;
    }
    ptemp->next = p;
    return preal->next;
}