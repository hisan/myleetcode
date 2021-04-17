//2018-12-05 思路：求得链表长度为len，知道应该被插入的结点的规律为链表的后n个结点：n = len/2（奇数个结点时）,or len/2-1（偶数个结点时），
// 将应该被插入的后半截链表段中的结点从第一个开始取出，并通过头插法建立在新的链表中得到新的链表
//在遍历新的链表，从新链表的第二个结点开始，将这些结点分别插入到前半截链表中相应的顺序即可。

//2018-12-09       解决了
void reorderList(struct ListNode* head) {
    if(!head||!head->next||!head->next->next)
    {
        return head;
    }
    typedef struct ListNode list;
    list* p = head;
    int len = 0 ;
    int size=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    size = len;
    if(len%2==0)
    {
        len = len/2-1;
    }
    else
    {
        len = len/2;
    }
    p=head;
    list* pre;
    for(int i =0;i<size-len;i++)
    {
        pre = p;
        p = p->next;
    }
    pre->next=NULL;
    list*temp_head = malloc(sizeof(list));
    temp_head->next=NULL;
    list* pnext = p->next;
    while(p)
    {
        p->next = temp_head->next;
        temp_head->next = p;
        if(pnext)
        {
            p = pnext;
            pnext = pnext->next;
        }
        else
        {
            break;
        }
    }
    p = temp_head->next;
    list* p1 = p->next;
    pre = head;
    pnext = pre->next;
    while(p)
    {
        p->next = pre->next;
        pre->next = p;
        if(pnext)
        {
            pre = pnext;
            pnext = pnext->next;
            if(p1)
            {
                p = p1;
                p1 = p1->next;
            }
            else
            {
                break;
            }
            
        }
        else
        {
            break;
        }
    }
    return head;
}