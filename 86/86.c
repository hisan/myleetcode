
//2018-12-03
//思路：另起两条新链l1,l2，遍历当前链表，>=x的尾插l2,<x的尾插l1

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* partition(struct ListNode* head, int x) {
    //保留相对位置
    typedef struct ListNode list;
    list *l1=malloc(sizeof(list));
    l1->next=NULL;
    list *head1=l1;
    list *l2=malloc(sizeof(list));
    l2->next=NULL;
    list *head2=l2;
    if(head==NULL)//保证至少有两个结点
    {
        return head;
    }
    while(head)
    {
        if(head->val<x)
        {//尾插l1
            l1->next=head;
            l1 = l1->next;//因为head一定不为null，所以l1一定不为null,同理l2
        }
        else
        {//尾插l2
            l2->next=head;
            l2 = l2->next;
        }
        head=head->next;
    }
    l1->next = head2->next;//接链
    head2->next=NULL;
    l2->next = NULL;
    return head1->next;
}
//注意内存泄漏