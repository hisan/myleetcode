//2018-11-28 19：46 end

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* rotateRight(struct ListNode* head, int k) {
    typedef struct ListNode list;
    list *p1 = head;
    list *p2 = head;
    list *p3 = head;//这是赋值，将head内存单元中的值赋给p3
    list *p4 = head;
    int len = 0;
    if(head==NULL)//链表为空则返回空
    {
        return NULL;
    }
    if(head->next==NULL||k==0)//一个结点的情况、不移动的情况下，直接返回链表
    {
        return head;
    }
    len++;
    while(p4->next!=NULL)//使得p4指向链表尾
    {
        len++;
        p4 = p4->next;
    }
    p4->next= p2;//串起来,形成单向循环链表
    k%=len;//求得真正需要移动的步长
    if(k==0)//若k移动的步数为len的整数倍，则相当于没移动直接返回链表
    {   
        p4->next = NULL;//我之前遗漏了这一步，返回了一个循环链表，当然是不行的
        return head;
    }
    //根据规律可得，移动k部，则新链表的头节点为第len-k个，尾部当然就是第len-k-1个
    for(int i =0 ;i<len-k-1;i++)
    {
        p3 = p3->next;
    }
    p2 = p3->next;
    p3->next=NULL;
    return p2;
}