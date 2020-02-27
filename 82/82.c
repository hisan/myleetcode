//2018-11-28 21：10


//边界条件：1，1，1，1
//边界条件：2，2
struct ListNode* DelOneNode(int value,struct ListNode*head);

struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode list;
    list *newhead = head;
    int *map;
    int size=1;
    int i =0;
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)//单节点不可能出现重复数字
    {
        return head;
    }
    list *p = head;
    while(p->next!=NULL)
    {
        size++;
        p = p->next;
    }
    map = malloc(sizeof(int)*size);//数组内存分配
    memset(map,0,sizeof(int)*size);//初始时全部置为0
    p = head;//p再次指向链表头部
    while(p!=NULL)
    {
       map[p->val]++;
       p = p->next;
    }
    for(int i=0;i<size;i++)
    {
        if(map[i]>1)//得到重复出现的值并将其作为参数到一个链表中取删除所有值==该参数的结点
        {
            newhead = DelOneNode(i,newhead);
        }
    }
    return newhead;
}

//定义一个删除排序链表中值为value的所有结点
struct ListNode* DelOneNode(int value,struct ListNode*head)
{
    typedef struct ListNode list;
    list *pstart = head;
    list *pend = head;
    list *p = pstart;
    while(pstart!=NULL)
    {
        if(pstart->val==value)
        {
            list *temp = pstart;
            pstart = pend;
            if(pend->next!=NULL)
            {   
                pend = pend->next;
                temp->next=NULL;
            }
            else
            {
                return pstart;
            }
        }
        else
        {
            if(pend->next!=NULL)
            {   
                pstart = pend;
                pend = pend->next;
            }
            else
            {
                return pstart;
            }
        }
    }
    return pstart;
}



//2018-12-03  
struct ListNode*deloneNodeFromList(struct ListNode*head,int value);
struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode list;
    if(head==NULL)
    {
        return head;
    }
    int *map;
    int size=1;
    list*p=head;
    while(p->next!=NULL)
    {
        size++;
        p = p->next;
    }
    map = malloc(sizeof(int)*size);
    memset(map,0,sizeof(int)*size);
    p = head;
    for(int i =0;i<size;i++)
    {
        *(map+i)= (p+i)->val;//num[p->val]++，如果链表中的值是负数，显然就不行了，
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(*(map+i)==*(map+j))
            {
                //写一个函数，可以删除链表中值为*(map+j)的结点
                p = deloneNodeFromList(p,*(map+j));
            }
        }
    }
    return p;
}

struct ListNode*deloneNodeFromList(struct ListNode*head,int value)
{//在单链表中删除指定值
    typedef struct ListNode list;
    if(head==NULL)
    {
        return head;
    }
    while(head!=NULL)//先找到第一个值不等于value的结点
    {
        if(head->val!=value)
        {
            break;
        }
        head = head->next;
    }
    list* pre;
    list* cur=head;
    while(cur!=NULL)
    {
        if(cur->val==value)
        {
            pre->next = cur->next;
            cur = cur->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

//已解决，别人的解法

struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode list;
    if(head==NULL)
    {
        return head;
    }
    list* pre=NULL;
    list*cur = head;
    while(cur)
    {
        if(cur->next!=NULL&&cur->next->val == cur->val)
        {
            while(cur->next!=NULL&&cur->next->val == cur->val)
            {
                cur = cur->next;//cur第一类移位：重复串移位，从重复串第一个元素到重复串最后一个元素
            }
            if(pre==NULL)//说明pre还没有开始指向，也就是链表一开始就有重复的元素
            {
                head = cur->next;//得到链表头
            }
            else
            {
                pre->next = cur->next;
            }
        }
        else
        {
            pre = cur;//得到新前驱（当前遍历的结点的前一个结点）
        }
        cur = cur->next;//cur第二类移位，正常移位
    }
    return head;
}


