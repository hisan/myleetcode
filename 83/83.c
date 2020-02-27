/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* deleteDuplicates(struct ListNode* head) {
    typedef struct ListNode list;
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    list *l1=head;//思路就是：第一个元素为基准元素，从基准元素的next元素开始比对，同值删除，后一个元素继续与基准元素比对。不等，则基准元素后移，继续上述过程
    list *p1=head;
    list *p2=head->next;
    while(l1!=NULL)
    {
        if(p1->val==p2->val)
        {   
            if(p2->next==NULL)
            {
                p1->next=NULL;
                return l1;
            }
            else
            {
                p1->next = p2->next;
                p2 = p1->next;
            }
        }
        else
        {
            if(p2->next==NULL)
            {
                return l1;
            }
            else  
            {
                p1 = p2;
                p2 = p2->next;
            }
        }
    }
    return l1;
}